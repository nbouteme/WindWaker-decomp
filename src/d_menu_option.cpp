#include <d_menu_option.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DPicture.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_menu_option.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JUtility/JUTGamePad.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSRtc.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <d_lib.h>
#include <m_Do_hostIO.h>
#include <d_meter.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMenu_Option_c.h>
#include <dMo_HIO_c.h>


namespace d_menu_option {
undefined g_moHIO;
}

/* __thiscall dMo_HIO_c::dMo_HIO_c(void) */

void __thiscall dMo_HIO_c::dMo_HIO_c(dMo_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dMenu_Option_c::screenSet(void) */

void __thiscall dMenu_Option_c::screenSet(dMenu_Option_c *this)

{
  J2DScreen *pJVar1;
  dMenu_Option_c *pdVar2;
  int iVar3;
  dMenu_Option_c *pdVar4;
  dMenu_Option_c *pdVar5;
  dMenu_Option_c *pdVar6;
  int iVar7;
  int iVar8;
  
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x746f7074);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x73703031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x40),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x736b3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x78),pJVar1);
  iVar3 = 0;
  iVar7 = 0;
  iVar8 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),
                        *(undefined4 *)((int)&d_menu_option::label_t_4008 + iVar8));
    pdVar5 = this + iVar7;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar5 + 0xb0),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),
                        *(undefined4 *)((int)&d_menu_option::label_d_4009 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar5 + 0x3f8),pJVar1);
    pdVar2 = (dMenu_Option_c *)0x0;
    J2DPicture::changeTexture(*(J2DPicture **)(pdVar5 + 0xb0),"font_07_02.bti",0);
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(pdVar5 + 0xb0),"font_00.bti");
    iVar3 = iVar3 + 1;
    iVar7 = iVar7 + 0x38;
    iVar8 = iVar8 + 4;
  } while (iVar3 < 0xf);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x73747230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x778),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x73743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x740),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x7b0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x7e8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6f3131);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x820),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x79617a32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x858),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x79617a31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x890),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74747975);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x8c8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74686c64);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x9a8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74736963);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x9e0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74736f75);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x970),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x746d6f6e);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xa18),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74737465);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xa50),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74737572);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xa88),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74766962);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x938),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x74617269);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xaf8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x746e6173);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xac0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63723332);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xb30),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63723331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xb68),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63633232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xba0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63633231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xbd8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63633132);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc10),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x63723131);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc48),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x62733039);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc80),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x62733030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xcb8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x626c616b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xcf0),pJVar1);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xd48,0x19d);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xd5c,0x19b);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xd70,0x1a9);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xd84,0x1d5);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xd98,0x1d4);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xdac,0x1d7);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xdc0,0x1d8);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xdd4,0x1eb);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xde8,0x19a);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xdfc,0x19a);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xe10,0x1d1);
  f_op_msg_mng::fopMsgM_messageGet(this + 0xe24,0x1d6);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 8),*(JUTFont **)(this + 0xd2c));
  J2DTextBox::setString(*(J2DTextBox **)(this + 8),(char *)(this + 0xd48),(___)pdVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x740),*(JUTFont **)(this + 0xd2c));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x778),*(JUTFont **)(this + 0xd30));
  iVar3 = 0;
  iVar7 = 0;
  iVar8 = 0;
  do {
    pdVar4 = this + iVar8;
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0x9a8),*(JUTFont **)(this + 0xd2c));
    pdVar6 = this + iVar7;
    J2DTextBox::setString(*(J2DTextBox **)(pdVar4 + 0x9a8),(char *)(pdVar6 + 0xd5c),(___)pdVar2);
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0xac0),*(JUTFont **)(this + 0xd2c));
    pdVar5 = pdVar6 + 0xd84;
    J2DTextBox::setString(*(J2DTextBox **)(pdVar4 + 0xac0),(char *)pdVar5,(___)pdVar2);
    changeScaleCenter(this,(fopMsgM_pane_class *)(pdVar4 + 0x9a8),(char *)(pdVar6 + 0xd5c));
    changeScaleCenter(this,(fopMsgM_pane_class *)(pdVar4 + 0xac0),(char *)pdVar5);
    iVar3 = iVar3 + 1;
    iVar7 = iVar7 + 0x14;
    iVar8 = iVar8 + 0x38;
    pdVar2 = pdVar5;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar7 = 0;
  iVar8 = 0;
  do {
    pdVar4 = this + iVar8;
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0xa18),*(JUTFont **)(this + 0xd2c));
    pdVar2 = this + iVar7 + 0xdac;
    J2DTextBox::setString(*(J2DTextBox **)(pdVar4 + 0xa18),(char *)pdVar2,(___)pdVar5);
    changeScaleCenter(this,(fopMsgM_pane_class *)(pdVar4 + 0xa18),(char *)pdVar2);
    iVar3 = iVar3 + 1;
    iVar7 = iVar7 + 0x14;
    iVar8 = iVar8 + 0x38;
    pdVar5 = pdVar2;
  } while (iVar3 < 3);
  iVar3 = 0;
  iVar8 = 0;
  iVar7 = 0;
  do {
    pdVar5 = pdVar2;
    if (iVar3 != 1) {
      pdVar4 = this + iVar7;
      J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0x8c8),*(JUTFont **)(this + 0xd2c));
      pdVar5 = this + iVar8 + 0xde8;
      J2DTextBox::setString(*(J2DTextBox **)(pdVar4 + 0x8c8),(char *)pdVar5,(___)pdVar2);
      changeScaleRight(this,(fopMsgM_pane_class *)(pdVar4 + 0x8c8),(char *)pdVar5);
    }
    iVar3 = iVar3 + 1;
    iVar8 = iVar8 + 0x14;
    iVar7 = iVar7 + 0x38;
    pdVar2 = pdVar5;
  } while (iVar3 < 4);
  *(short *)(this + 0x856) = (short)(int)*(float *)(*(int *)(this + 0x820) + 0xa4);
  *(short *)(this + 0x3e) = (short)(int)*(float *)(*(int *)(this + 8) + 0xa4);
  *(short *)(this + 0x76) = (short)(int)*(float *)(*(int *)(this + 0x40) + 0xa4);
  *(short *)(this + 0xae) = (short)(int)*(float *)(*(int *)(this + 0x78) + 0xa4);
  if (0xb4 < *(short *)(this + 0x856)) {
    *(short *)(this + 0x856) = *(short *)(this + 0x856) + -0x168;
  }
  if (0xb4 < *(short *)(this + 0x3e)) {
    *(short *)(this + 0x3e) = *(short *)(this + 0x3e) + -0x168;
  }
  if (0xb4 < *(short *)(this + 0x76)) {
    *(short *)(this + 0x76) = *(short *)(this + 0x76) + -0x168;
  }
  if (0xb4 < *(short *)(this + 0xae)) {
    *(short *)(this + 0xae) = *(short *)(this + 0xae) + -0x168;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d34f0) */
/* WARNING: Removing unreachable block (ram,0x801d34f8) */
/* __thiscall dMenu_Option_c::mainInit(void) */

void __thiscall dMenu_Option_c::mainInit(dMenu_Option_c *this)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  dMenu_Option_c *pdVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcf0));
  iVar3 = 0;
  iVar5 = 0;
  dVar7 = (double)d_menu_option::_4106;
  dVar8 = (double)d_menu_option::_4107;
  do {
    pdVar4 = this + iVar5;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar4 + 0x858),(double)d_menu_option::_4105,
               (double)d_menu_option::_4105);
    fVar1 = *(float *)(this + 0x888);
    piVar2 = *(int **)(this + 0x858);
    piVar2[0x27] = (int)(float)((double)*(float *)(this + 0x884) * dVar7);
    piVar2[0x28] = (int)(float)((double)fVar1 * dVar7);
    *(undefined *)(piVar2 + 0x2a) = 0x7a;
    piVar2[0x29] = (int)(float)dVar8;
    (**(code **)(*piVar2 + 0x20))();
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar4 + 0xc80));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar4 + 0x858));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar4 + 0x9a8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar4 + 0xac0));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar5 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar5 + 0xa18));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar3 < 3);
  iVar3 = 0;
  iVar5 = 0;
  do {
    if (iVar3 != 1) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar5 + 0x8c8));
    }
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar3 < 4);
  iVar3 = 0;
  iVar5 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar5 + 0xb30),(double)d_menu_option::_4105,
               (double)d_menu_option::_4105);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar5 + 0xb30));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar3 < 6);
  *(undefined2 *)(this + 0xb66) = 0;
  *(undefined2 *)(this + 0xb9e) = 0;
  *(undefined2 *)(this + 0xbd6) = 0;
  *(undefined2 *)(this + 0x88e) = 0;
  *(undefined2 *)(this + 0x8c6) = 0;
  cursorMove(this);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __thiscall dMenu_Option_c::noteInit(void) */

void __thiscall dMenu_Option_c::noteInit(dMenu_Option_c *this)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_option::_4105,
             (double)d_menu_option::_4122);
  fVar1 = d_menu_option::_4123 +
          (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
                 d_menu_option::_4125);
  fVar2 = *(float *)(this + 0x850) * d_menu_option::_4106;
  piVar3 = *(int **)(this + 0x820);
  piVar3[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_option::_4106);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)fVar1;
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x740));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x778));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7b0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x7e8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x820));
  return;
}


/* WARNING: Removing unreachable block (ram,0x801d37ac) */
/* __thiscall dMenu_Option_c::titleInit(void) */

void __thiscall dMenu_Option_c::titleInit(dMenu_Option_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)*(short *)(this + 0x3e) + 0x14U ^ 0x80000000) -
                         d_menu_option::_4125);
  if ((double)d_menu_option::_4152 < dVar5) {
    dVar5 = (double)(float)(dVar5 - (double)d_menu_option::_4151);
  }
  if (dVar5 < (double)d_menu_option::_4153) {
    dVar5 = (double)(float)(dVar5 + (double)d_menu_option::_4151);
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 8),(double)d_menu_option::_4105,
             (double)d_menu_option::_4154);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x40),(double)d_menu_option::_4105,
             (double)d_menu_option::_4154);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x78),(double)d_menu_option::_4105,
             (double)d_menu_option::_4154);
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x3e) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar2 = *(float *)(this + 0x38) * d_menu_option::_4106;
  piVar3 = *(int **)(this + 8);
  piVar3[0x27] = (int)(*(float *)(this + 0x34) * d_menu_option::_4106);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)(dVar5 + (double)(float)dVar1);
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x76) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar2 = *(float *)(this + 0x70) * d_menu_option::_4106;
  piVar3 = *(int **)(this + 0x40);
  piVar3[0x27] = (int)(*(float *)(this + 0x6c) * d_menu_option::_4106);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)(dVar5 + (double)(float)dVar1);
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0xae) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar2 = *(float *)(this + 0xa8) * d_menu_option::_4106;
  piVar3 = *(int **)(this + 0x78);
  piVar3[0x27] = (int)(*(float *)(this + 0xa4) * d_menu_option::_4106);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)(dVar5 + (double)(float)dVar1);
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x40));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x78));
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Option_c::mainMove(void) */

void __thiscall dMenu_Option_c::mainMove(dMenu_Option_c *this)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0xcb6),0);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcf0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(this + (uint)(byte)this[0xe3c] * 0x38 + 0x9a8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(this + (uint)(byte)this[0xe3f] * 0x38 + 0xac0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(this + (uint)(byte)this[0xe3e] * 0x38 + 0xa18),(float)dVar3);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0xc80),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x858),(float)dVar3);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 2);
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (iVar1 != 1) {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x8c8),(float)dVar3);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb30),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb68),(float)dVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801d39d0) */
/* WARNING: Removing unreachable block (ram,0x801d39d8) */
/* __thiscall dMenu_Option_c::noteMove(void) */

void __thiscall dMenu_Option_c::noteMove(dMenu_Option_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,*(short *)(this + 0xcb6) + -7,0);
  dVar7 = (double)(float)((double)d_menu_option::_4189 - dVar6);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x820),(double)d_menu_option::_4105,
             (double)(float)((double)d_menu_option::_4122 * dVar7));
  dVar5 = (double)d_menu_option::_4123;
  dVar1 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x856) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar2 = *(float *)(this + 0x850) * d_menu_option::_4106;
  piVar3 = *(int **)(this + 0x820);
  piVar3[0x27] = (int)(*(float *)(this + 0x84c) * d_menu_option::_4106);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)((float)(dVar5 * dVar7) + (float)dVar1);
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x740),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x778),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7b0),(float)dVar6);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7e8),(float)dVar6);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801d3c48) */
/* WARNING: Removing unreachable block (ram,0x801d3c40) */
/* WARNING: Removing unreachable block (ram,0x801d3c50) */
/* __thiscall dMenu_Option_c::titleMove(void) */

void __thiscall dMenu_Option_c::titleMove(dMenu_Option_c *this)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
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
  dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,*(short *)(this + 0xcb6) + -7,0);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)*(short *)(this + 0x3e) + 0x14U ^ 0x80000000) -
                         d_menu_option::_4125);
  if ((double)d_menu_option::_4152 < dVar5) {
    dVar5 = (double)(float)(dVar5 - (double)d_menu_option::_4151);
  }
  if (dVar5 < (double)d_menu_option::_4153) {
    dVar5 = (double)(float)(dVar5 + (double)d_menu_option::_4151);
  }
  dVar6 = (double)(float)((double)d_menu_option::_4189 - dVar4);
  dVar5 = (double)(float)(dVar5 * dVar6);
  if (*(short *)(this + 0xcb6) == 8) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x84e,(cXyz *)0x0,0,0,d_menu_option::_4189,
               d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
  }
  dVar6 = (double)(float)((double)d_menu_option::_4154 * dVar6);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 8),(double)d_menu_option::_4105,dVar6);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x40),(double)d_menu_option::_4105,dVar6);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x78),(double)d_menu_option::_4105,dVar6);
  dVar6 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x3e) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar1 = *(float *)(this + 0x38) * d_menu_option::_4106;
  piVar2 = *(int **)(this + 8);
  piVar2[0x27] = (int)(*(float *)(this + 0x34) * d_menu_option::_4106);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)(dVar5 + (double)(float)dVar6);
  (**(code **)(*piVar2 + 0x20))();
  dVar6 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x76) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar1 = *(float *)(this + 0x70) * d_menu_option::_4106;
  piVar2 = *(int **)(this + 0x40);
  piVar2[0x27] = (int)(*(float *)(this + 0x6c) * d_menu_option::_4106);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)(dVar5 + (double)(float)dVar6);
  (**(code **)(*piVar2 + 0x20))();
  dVar6 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0xae) ^ 0x80000000) -
          d_menu_option::_4125;
  fVar1 = *(float *)(this + 0xa8) * d_menu_option::_4106;
  piVar2 = *(int **)(this + 0x78);
  piVar2[0x27] = (int)(*(float *)(this + 0xa4) * d_menu_option::_4106);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)(dVar5 + (double)(float)dVar6);
  (**(code **)(*piVar2 + 0x20))();
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 8),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x40),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x78),(float)dVar4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d3d14) */
/* __thiscall dMenu_Option_c::cursorMove(void) */

void __thiscall dMenu_Option_c::cursorMove(dMenu_Option_c *this)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  dMenu_Option_c *pdVar4;
  dMenu_Option_c *pdVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = 0;
  iVar6 = 0;
  pdVar5 = this + *(short *)(this + 0xb9e) * 0x38;
  dVar8 = (double)d_menu_option::_4106;
  do {
    pdVar4 = this + iVar6;
    *(undefined4 *)(pdVar4 + 0xb4c) = *(undefined4 *)(pdVar5 + 0x8dc);
    *(undefined4 *)(pdVar4 + 0xb50) = *(undefined4 *)(pdVar5 + 0x8e0);
    *(undefined4 *)(pdVar4 + 0xb5c) = *(undefined4 *)(pdVar5 + 0x8ec);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar4 + 0xb30));
    piVar2 = *(int **)(pdVar4 + 0xb30);
    fVar1 = *(float *)(pdVar4 + 0xb60);
    piVar2[0x27] = (int)(float)((double)*(float *)(pdVar4 + 0xb5c) * dVar8);
    piVar2[0x28] = (int)(float)((double)fVar1 * dVar8);
    *(undefined *)(piVar2 + 0x2a) = 0x7a;
    (**(code **)(*piVar2 + 0x20))();
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar3 < 6);
  cursorScale(this);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d3e50) */
/* __thiscall dMenu_Option_c::cursorScale(void) */

void __thiscall dMenu_Option_c::cursorScale(dMenu_Option_c *this)

{
  short sVar1;
  dMenu_Option_c *pdVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double in_f31;
  float local_38 [5];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  sVar1 = *(short *)(this + 0xb9e);
  if (sVar1 == 2) {
    pdVar2 = this + (uint)(byte)this[0xe3f] * 0x38;
    local_38[0] = *(float *)(pdVar2 + 0xac4) - d_menu_option::_4270;
    local_38[1] = d_menu_option::_4270 + *(float *)(pdVar2 + 0xac4) + *(float *)(pdVar2 + 0xae4);
    in_f31 = (double)*(float *)(pdVar2 + 0xad8);
  }
  else {
    if (sVar1 < 2) {
      if (sVar1 == 0) {
        pdVar2 = this + (uint)(byte)this[0xe3c] * 0x38;
        local_38[0] = *(float *)(pdVar2 + 0x9ac) - d_menu_option::_4270;
        local_38[1] = d_menu_option::_4270 + *(float *)(pdVar2 + 0x9ac) + *(float *)(pdVar2 + 0x9cc)
        ;
        in_f31 = (double)*(float *)(pdVar2 + 0x9c0);
      }
    }
    else {
      if (sVar1 < 4) {
        pdVar2 = this + (uint)(byte)this[0xe3e] * 0x38;
        local_38[0] = *(float *)(pdVar2 + 0xa1c) - d_menu_option::_4270;
        local_38[1] = d_menu_option::_4270 + *(float *)(pdVar2 + 0xa1c) + *(float *)(pdVar2 + 0xa3c)
        ;
        in_f31 = (double)*(float *)(pdVar2 + 0xa30);
      }
    }
  }
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    pdVar2 = this + iVar5;
    *(undefined4 *)(pdVar2 + 0x874) = *(undefined4 *)((int)local_38 + iVar4);
    *(float *)(pdVar2 + 0x878) = (float)in_f31;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 0x858));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 2);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Option_c::typeMove(void) */

void __thiscall dMenu_Option_c::typeMove(dMenu_Option_c *this)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  sVar1 = *(short *)(this + 0xb9e);
  if (sVar1 == 2) {
    uVar2 = 0;
    iVar3 = 0;
    do {
      if (uVar2 == (byte)this[0xe3f]) {
        f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0xac0);
      }
      else {
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xac0));
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x38;
    } while ((int)uVar2 < 2);
  }
  else {
    if (sVar1 < 2) {
      if (sVar1 == 0) {
        uVar2 = 0;
        iVar3 = 0;
        do {
          if (uVar2 == (byte)this[0xe3c]) {
            f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x9a8);
          }
          else {
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x9a8));
          }
          uVar2 = uVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while ((int)uVar2 < 2);
      }
    }
    else {
      if (sVar1 < 4) {
        uVar2 = 0;
        iVar3 = 0;
        do {
          if (uVar2 == (byte)this[0xe3e]) {
            f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0xa18);
          }
          else {
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xa18));
          }
          uVar2 = uVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while ((int)uVar2 < 3);
      }
    }
  }
  cursorScale(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801d41a8) */
/* __thiscall dMenu_Option_c::yazAnime(void) */

void __thiscall dMenu_Option_c::yazAnime(dMenu_Option_c *this)

{
  float fVar1;
  short sVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = d_menu_option::_4331;
  if (*(short *)(this + 0x88e) < 10) {
    fVar1 = d_menu_option::_4330;
  }
  fVar3 = *(float *)(this + 0x888) * d_menu_option::_4106;
  piVar4 = *(int **)(this + 0x858);
  piVar4[0x27] = (int)(*(float *)(this + 0x884) * d_menu_option::_4106);
  piVar4[0x28] = (int)fVar3;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  dVar7 = (double)(d_menu_option::_4107 + fVar1);
  piVar4[0x29] = (int)(d_menu_option::_4107 + fVar1);
  (**(code **)(*piVar4 + 0x20))();
  fVar1 = *(float *)(this + 0x8c0) * d_menu_option::_4106;
  piVar4 = *(int **)(this + 0x890);
  piVar4[0x27] = (int)(*(float *)(this + 0x8bc) * d_menu_option::_4106);
  piVar4[0x28] = (int)fVar1;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar4 + 0x20))();
  *(short *)(this + 0x88e) = *(short *)(this + 0x88e) + 1;
  sVar2 = *(short *)(this + 0x8c6);
  if (sVar2 < 1) {
    if (sVar2 < 0) {
      *(short *)(this + 0x8c6) = sVar2 + 1;
      iVar5 = MSL_C.PPCEABI.bare.H::abs((int)*(short *)(this + 0x8c6));
      local_28 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_option::_4106 + *(float *)(this + 0x864)) -
                                  *(int *)(&d_menu_option::moveX_4308 + iVar5 * 4) ^ 0x80000000);
      local_38 = (double)CONCAT44(0x43300000,
                                  (int)(d_menu_option::_4106 + *(float *)(this + 0x868)) ^
                                  0x80000000);
      (**(code **)(**(int **)(this + 0x858) + 0x10))
                ((double)(float)(local_28 - d_menu_option::_4125),
                 (double)(float)(local_38 - d_menu_option::_4125));
    }
  }
  else {
    *(short *)(this + 0x8c6) = sVar2 + -1;
    local_30 = (double)CONCAT44(0x43300000,
                                (int)(d_menu_option::_4106 + *(float *)(this + 0x89c)) +
                                *(int *)(&d_menu_option::moveX_4308 + *(short *)(this + 0x8c6) * 4)
                                ^ 0x80000000);
    local_20 = (double)CONCAT44(0x43300000,
                                (int)(d_menu_option::_4106 + *(float *)(this + 0x8a0)) ^ 0x80000000)
    ;
    (**(code **)(**(int **)(this + 0x890) + 0x10))
              ((double)(float)(local_30 - d_menu_option::_4125),
               (double)(float)(local_20 - d_menu_option::_4125));
  }
  if (0x13 < *(short *)(this + 0x88e)) {
    *(undefined2 *)(this + 0x88e) = 0;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMenu_Option_c::ccAnime(void) */

void __thiscall dMenu_Option_c::ccAnime(dMenu_Option_c *this)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = *(short *)(this + 0xb66);
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    if (iVar2 == (int)sVar1 / 7) {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0xb30);
      f_op_msg_mng::fopMsgM_setInitAlpha(this + (iVar4 + 1) * 0x38 + 0xb30);
    }
    else {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0xb30));
      f_op_msg_mng::fopMsgM_setNowAlphaZero
                ((fopMsgM_pane_class *)(this + (iVar4 + 1) * 0x38 + 0xb30));
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 2;
    iVar3 = iVar3 + 0x70;
  } while (iVar2 < 3);
  *(short *)(this + 0xb66) = *(short *)(this + 0xb66) + 1;
  if (0x14 < *(short *)(this + 0xb66)) {
    *(undefined2 *)(this + 0xb66) = 0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMenu_Option_c::stickMove(unsigned char) */

void __thiscall dMenu_Option_c::stickMove(dMenu_Option_c *this,uchar param_1)

{
  short sVar1;
  
  if (param_1 == '\x04') {
    if (0 < *(short *)(this + 0xb9e)) {
      *(short *)(this + 0xb9e) = *(short *)(this + 0xb9e) + -1;
      if (*(short *)(this + 0xb9e) == 1) {
        *(undefined2 *)(this + 0xb9e) = 0;
      }
      cursorMove(this);
      noteSet(this);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_option::_4189,
                 d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
    }
  }
  else {
    if (param_1 < 4) {
      if (param_1 == '\x02') {
        sVar1 = *(short *)(this + 0xb9e);
        if (sVar1 == 2) {
          if ((_sRumbleSupported & 0x80000000) != 0) {
            if (this[0xe3f] == (dMenu_Option_c)0x0) {
              this[0xe3f] = (dMenu_Option_c)0x1;
              JUTGamePad::CRumble::startPatternedRumble
                        (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,(uchar *)(this + 0xe38),
                         0,0x3c);
            }
            else {
              this[0xe3f] = (dMenu_Option_c)0x0;
            }
            *(undefined2 *)(this + 0x8c6) = 6;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                       d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
          }
        }
        else {
          if (sVar1 < 2) {
            if (sVar1 == 0) {
              if (this[0xe3c] == (dMenu_Option_c)0x0) {
                this[0xe3c] = (dMenu_Option_c)0x1;
              }
              else {
                this[0xe3c] = (dMenu_Option_c)0x0;
              }
              *(undefined2 *)(this + 0x8c6) = 6;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                         d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
            }
            else {
              if (-1 < sVar1) {
                if (this[0xe3d] == (dMenu_Option_c)0x0) {
                  this[0xe3d] = (dMenu_Option_c)0x1;
                }
                else {
                  this[0xe3d] = (dMenu_Option_c)0x0;
                }
                *(undefined2 *)(this + 0x8c6) = 6;
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                           d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
              }
            }
          }
          else {
            if (sVar1 < 4) {
              if ((byte)this[0xe3e] < 2) {
                this[0xe3e] = (dMenu_Option_c)((char)this[0xe3e] + 1);
              }
              else {
                this[0xe3e] = (dMenu_Option_c)0x0;
              }
              *(undefined2 *)(this + 0x8c6) = 6;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                         d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
              JAIZelBasic::setOutputMode
                        (JAIZelBasic::zel_basic,
                         *(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4));
              setSoundMode(this,*(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4))
              ;
            }
          }
        }
        typeMove(this);
      }
      else {
        if ((param_1 < 2) && (param_1 != '\0')) {
          sVar1 = *(short *)(this + 0xb9e);
          if (sVar1 == 2) {
            if ((_sRumbleSupported & 0x80000000) != 0) {
              if (this[0xe3f] == (dMenu_Option_c)0x0) {
                this[0xe3f] = (dMenu_Option_c)0x1;
                JUTGamePad::CRumble::startPatternedRumble
                          (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,
                           (uchar *)(this + 0xe38),0,0x3c);
              }
              else {
                this[0xe3f] = (dMenu_Option_c)0x0;
              }
              *(undefined2 *)(this + 0x8c6) = 0xfffa;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                         d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
            }
          }
          else {
            if (sVar1 < 2) {
              if (sVar1 == 0) {
                if (this[0xe3c] == (dMenu_Option_c)0x0) {
                  this[0xe3c] = (dMenu_Option_c)0x1;
                }
                else {
                  this[0xe3c] = (dMenu_Option_c)0x0;
                }
                *(undefined2 *)(this + 0x8c6) = 0xfffa;
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                           d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
              }
              else {
                if (-1 < sVar1) {
                  if (this[0xe3d] == (dMenu_Option_c)0x0) {
                    this[0xe3d] = (dMenu_Option_c)0x1;
                  }
                  else {
                    this[0xe3d] = (dMenu_Option_c)0x0;
                  }
                  *(undefined2 *)(this + 0x8c6) = 0xfffa;
                  JAIZelBasic::seStart
                            (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                             d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
                }
              }
            }
            else {
              if (sVar1 < 4) {
                if (this[0xe3e] == (dMenu_Option_c)0x0) {
                  this[0xe3e] = (dMenu_Option_c)0x2;
                }
                else {
                  this[0xe3e] = (dMenu_Option_c)((char)this[0xe3e] + -1);
                }
                *(undefined2 *)(this + 0x8c6) = 0xfffa;
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x84f,(cXyz *)0x0,0,0,d_menu_option::_4189,
                           d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
                JAIZelBasic::setOutputMode
                          (JAIZelBasic::zel_basic,
                           *(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4));
                setSoundMode(this,*(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4
                                            ));
              }
            }
          }
          typeMove(this);
        }
      }
    }
    else {
      if ((param_1 == '\b') && (*(short *)(this + 0xb9e) < 3)) {
        *(short *)(this + 0xb9e) = *(short *)(this + 0xb9e) + 1;
        if (*(short *)(this + 0xb9e) == 1) {
          *(undefined2 *)(this + 0xb9e) = 2;
        }
        cursorMove(this);
        noteSet(this);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x80e,(cXyz *)0x0,0,0,d_menu_option::_4189,
                   d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801d4bd8) */
/* WARNING: Removing unreachable block (ram,0x801d4be0) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dMenu_Option_c::noteSet(void) */

void __thiscall dMenu_Option_c::noteSet(dMenu_Option_c *this)

{
  float fVar1;
  float fVar2;
  mesg_header *pmVar3;
  ulong uVar4;
  int iVar5;
  dMenu_Option_c *pdVar6;
  ___ _Var7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  undefined1 *local_358;
  undefined4 local_354;
  undefined2 local_350;
  undefined2 local_34e;
  undefined4 local_34c;
  undefined2 local_348;
  undefined2 local_346;
  undefined2 local_344;
  undefined2 local_342;
  undefined local_340;
  undefined local_33f;
  undefined local_33e;
  undefined local_33d;
  undefined local_33c;
  undefined local_33b;
  undefined local_33a;
  undefined local_339;
  undefined local_338;
  undefined local_337;
  undefined local_336;
  undefined local_335;
  undefined4 local_334;
  undefined2 local_330;
  undefined2 local_32e;
  undefined2 local_32c;
  undefined2 local_32a;
  undefined local_328;
  undefined local_327;
  undefined local_326;
  undefined local_325;
  undefined local_324;
  undefined local_323;
  undefined local_322;
  undefined local_321;
  undefined local_320;
  undefined local_31f;
  undefined local_31e;
  undefined local_31d;
  undefined auStack796 [8];
  undefined4 local_314;
  undefined4 *local_310;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  ___ local_2d0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b4;
  ___ local_2b0;
  int local_200;
  int local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  int local_1d8;
  int local_1d0;
  undefined4 local_1c0;
  undefined4 local_1bc;
  uint local_1b4 [15];
  int local_178 [55];
  byte abStack155 [24];
  undefined local_83;
  undefined local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  double local_58;
  undefined4 local_50;
  uint uStack76;
  double local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_358 = &fopMsgM_itemMsgGet_c::__vt;
  local_354 = 0;
  local_350 = 0;
  local_34e = 0;
  fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack796);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0xd38),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0xd3c),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0xd40),"");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0xd44),"");
  outFontInit(this);
  dVar14 = (double)*(float *)(*(int *)(this + 0x740) + 0xe8);
  dVar13 = (double)*(float *)(*(int *)(this + 0x778) + 0xe8);
  pmVar3 = (mesg_header *)
           fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_358,0x262);
  if (pmVar3 == (mesg_header *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_menu_option.cpp",0x313,"head_p");
    m_Do_printf::OSPanic("d_menu_option.cpp",0x313,&DAT_803606c1);
  }
  local_2e0 = fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_358,pmVar3);
  fopMsgM_itemMsgGet_c::getMesgEntry((fopMsgM_itemMsgGet_c *)&local_34c,(mesg_header *)&local_358);
  local_334 = local_34c;
  local_330 = local_348;
  local_32e = local_346;
  local_32c = local_344;
  local_32a = local_342;
  local_328 = local_340;
  local_327 = local_33f;
  local_326 = local_33e;
  local_325 = local_33d;
  local_324 = local_33c;
  local_323 = local_33b;
  local_322 = local_33a;
  local_321 = local_339;
  local_320 = local_338;
  local_31f = local_337;
  local_31e = local_336;
  local_31d = local_335;
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)auStack796);
  _Var7 = *(___ *)(this + 0xd44);
  local_2d4 = *(undefined4 *)(this + 0xd40);
  local_2d8 = *(undefined4 *)(this + 0xd3c);
  local_2dc = *(undefined4 *)(this + 0xd38);
  auStack796._4_4_ = *(undefined4 *)(this + 0xd2c);
  local_314 = *(undefined4 *)(this + 0xd30);
  local_200 = (int)*(float *)(*(int *)(this + 0x740) + 0xe0);
  local_78 = (longlong)local_200;
  local_1f8 = (int)*(float *)(*(int *)(this + 0x778) + 0xe0);
  local_70 = (longlong)local_1f8;
  local_1fc = (int)*(float *)(*(int *)(this + 0x740) + 0xe4);
  local_68 = (longlong)local_1fc;
  local_310 = &local_334;
  local_1d8 = (int)dVar14;
  local_60 = (longlong)local_1d8;
  local_1d0 = (int)dVar13;
  local_58 = (double)(longlong)local_1d0;
  local_1f4 = 0x1d0;
  local_1f0 = 0x1d0;
  local_1bc = 2;
  local_1c0 = 0;
  local_83 = 1;
  local_80 = 0;
  local_2d0 = _Var7;
  local_2bc = local_2dc;
  local_2b8 = local_2d8;
  local_2b4 = local_2d4;
  local_2b0 = _Var7;
  fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)auStack796);
  fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)auStack796);
  fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)auStack796);
  local_1ec = 0;
  fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)auStack796);
  fVar2 = d_menu_option::_4105;
  iVar5 = *(int *)(this + 0x740);
  uStack76 = (int)local_1ec._2_2_ ^ 0x80000000;
  local_50 = 0x43300000;
  fVar1 = ((float)((double)(*(float *)(iVar5 + 0x18) - *(float *)(iVar5 + 0x10)) - dVar14) -
          (float)((double)CONCAT44(0x43300000,uStack76) - d_menu_option::_4125) *
          *(float *)(iVar5 + 0xe4)) * d_menu_option::_4106;
  dVar13 = (double)fVar1;
  *(float *)(iVar5 + 0xd8) = d_menu_option::_4105;
  *(float *)(iVar5 + 0xdc) = fVar1;
  iVar5 = *(int *)(this + 0x778);
  *(float *)(iVar5 + 0xd8) = fVar2;
  *(float *)(iVar5 + 0xdc) = fVar1;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x740),*(char **)(this + 0xd38),_Var7);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x778),*(char **)(this + 0xd3c),_Var7);
  iVar5 = (int)(*(float *)(*(int *)(this + 0x740) + 0xe4) * d_menu_option::_4106);
  local_48 = (double)(longlong)iVar5;
  iVar11 = 0;
  iVar10 = 0;
  iVar9 = 0;
  do {
    dVar14 = d_menu_option::_4125;
    uVar8 = (uint)abStack155[iVar11];
    if (((uVar8 != 0xff) && (pdVar6 = this + iVar9, *(short *)(pdVar6 + 0xe6) == -1)) &&
       (uVar8 != 0x16)) {
      local_48 = (double)CONCAT44(0x43300000,*(uint *)((int)local_1b4 + iVar10) ^ 0x80000000);
      *(float *)(pdVar6 + 0xbc) = (float)(local_48 - d_menu_option::_4125);
      uStack76 = iVar5 * *(int *)((int)local_178 + iVar10) * 2 ^ 0x80000000;
      local_50 = 0x43300000;
      *(float *)(pdVar6 + 0xc0) =
           (float)(dVar13 + (double)(float)((double)CONCAT44(0x43300000,uStack76) - dVar14));
      local_58 = (double)CONCAT44(0x43300000,uVar8);
      *(float *)(pdVar6 + 0xb8) = (float)(local_58 - d_menu_option::_4542);
      f_op_msg_mng::fopMsgM_outFontSet(*(undefined4 *)(pdVar6 + 0xb0),pdVar6 + 0xe6,0xff);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 4;
    iVar9 = iVar9 + 0x38;
  } while (iVar11 < 0xf);
  fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack796);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801d4c68) */
/* __thiscall dMenu_Option_c::outFontInit(void) */

void __thiscall dMenu_Option_c::outFontInit(dMenu_Option_c *this)

{
  int *piVar1;
  int iVar2;
  dMenu_Option_c *pdVar3;
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
  dVar6 = (double)d_menu_option::_4105;
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
/* __thiscall dMenu_Option_c::outFontMove(void) */

void __thiscall dMenu_Option_c::outFontMove(dMenu_Option_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  dMenu_Option_c *pdVar5;
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
           *(float *)(this + 0x74c) + *(float *)(this + 0x82c) + *(float *)(this + 0x7bc);
      *(float *)(pdVar5 + 0x408) =
           *(float *)(pdVar5 + 0xc0) +
           *(float *)(this + 0x750) + *(float *)(this + 0x830) + *(float *)(this + 0x7c0);
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


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Option_c::outFontDraw(void) */

void __thiscall dMenu_Option_c::outFontDraw(dMenu_Option_c *this)

{
  dMenu_Option_c *pdVar1;
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
      pdVar1[0xe5] = *(dMenu_Option_c *)(*(int *)(this + 0x740) + 0xac);
      f_op_msg_mng::fopMsgM_outFontDraw2
                (*(undefined4 *)(pdVar1 + 0xb0),*(undefined4 *)(pdVar1 + 0x3f8),
                 (int)*(float *)(pdVar1 + 0x404),(int)*(float *)(pdVar1 + 0x408),0x19,0x19,
                 pdVar1 + 0xe6,pdVar1[0xe5],(int)*(float *)(pdVar1 + 0xb8));
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 0xf);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801d5034) */
/* WARNING: Removing unreachable block (ram,0x801d502c) */
/* WARNING: Removing unreachable block (ram,0x801d503c) */
/* __thiscall dMenu_Option_c::stringlength(fopMsgM_pane_class *,
                                           char *) */

double __thiscall
dMenu_Option_c::stringlength(dMenu_Option_c *this,fopMsgM_pane_class *param_1,char *param_2)

{
  float fVar1;
  char cVar2;
  float fVar3;
  bool bVar4;
  J2DScreen *pJVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  byte local_78 [4];
  undefined uStack116;
  byte local_73;
  float local_68;
  float local_64;
  double local_60;
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
  dVar8 = (double)d_menu_option::_4105;
  bVar4 = false;
  pJVar5 = param_1->mpPane;
  local_68 = pJVar5[1].parent.mPosBR.x;
  local_64 = pJVar5[1].parent.mPosBR.y;
  dVar10 = (double)pJVar5[1].parent.mPosTL.x;
  uVar6 = (**(code **)(**(int **)(this + 0xd2c) + 0x30))();
  local_60 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
  dVar9 = (double)(local_68 / (float)(local_60 - d_menu_option::_4125));
  while (*param_2 != '\0') {
    if (*param_2 == '\x1a') {
      param_2 = param_2 + 1 + param_2[1] + -1;
    }
    else {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      (**(code **)(**(int **)(this + 0xd2c) + 0x2c))(*(int **)(this + 0xd2c),cVar2,&uStack116);
      uVar6 = (uint)local_73;
      if (bVar4) {
        local_60 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
        dVar8 = (double)(float)(dVar8 + (double)(float)(dVar10 + (double)(float)((double)(float)(
                                                  local_60 - d_menu_option::_4125) * dVar9)));
      }
      else {
        (**(code **)(**(int **)(this + 0xd2c) + 0x2c))(*(int **)(this + 0xd2c),cVar2,local_78);
        local_60 = (double)CONCAT44(0x43300000,uVar6 + local_78[0] ^ 0x80000000);
        dVar8 = (double)(float)(dVar9 * (double)(float)(local_60 - d_menu_option::_4125));
        bVar4 = true;
      }
    }
  }
  if ((double)d_menu_option::_4642 < dVar8) {
    fVar1 = (float)((double)CONCAT44(0x43300000,
                                     (int)(local_68 * (float)((double)d_menu_option::_4642 / dVar8))
                                     ^ 0x80000000) - d_menu_option::_4125);
    pJVar5 = param_1->mpPane;
    fVar3 = d_menu_option::_4105;
    if (d_menu_option::_4105 < fVar1) {
      fVar3 = fVar1;
    }
    pJVar5[1].parent.mPosBR.x = fVar3;
    fVar1 = d_menu_option::_4105;
    if (d_menu_option::_4105 < local_64) {
      fVar1 = local_64;
    }
    pJVar5[1].parent.mPosBR.y = fVar1;
    dVar8 = (double)d_menu_option::_4642;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return dVar8;
}


/* __thiscall dMenu_Option_c::changeScaleCenter(fopMsgM_pane_class *,
                                                char *) */

void __thiscall
dMenu_Option_c::changeScaleCenter(dMenu_Option_c *this,fopMsgM_pane_class *param_1,char *param_2)

{
  double dVar1;
  
  dVar1 = (double)stringlength(this,param_1,param_2);
  (param_1->mSize).x = (float)dVar1;
  (param_1->mSizeOrig).x = (float)dVar1;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  (param_1->mPosTopLeftOrig).x = (param_1->mPosTopLeft).x;
  return;
}


/* __thiscall dMenu_Option_c::setSoundMode(unsigned long) */

dMenu_Option_c * __thiscall dMenu_Option_c::setSoundMode(dMenu_Option_c *this,ulong param_1)

{
  if (param_1 == 0) {
    this = (dMenu_Option_c *)os::OSSetSoundMode(0);
  }
  else {
    if ((-1 < (int)param_1) && ((int)param_1 < 3)) {
      this = (dMenu_Option_c *)os::OSSetSoundMode(1);
    }
  }
  return this;
}


/* __thiscall dMenu_Option_c::changeScaleRight(fopMsgM_pane_class *,
                                               char *) */

void __thiscall
dMenu_Option_c::changeScaleRight(dMenu_Option_c *this,fopMsgM_pane_class *param_1,char *param_2)

{
  float fVar1;
  double dVar2;
  
  dVar2 = (double)stringlength(this,param_1,param_2);
  fVar1 = (param_1->mSize).x;
  (param_1->mSize).x = (float)dVar2;
  (param_1->mSizeOrig).x = (float)dVar2;
  fVar1 = ((param_1->mPosTopLeft).x + fVar1) - (param_1->mSize).x * d_menu_option::_4106;
  (param_1->mPosCenter).x = fVar1;
  (param_1->mPosCenterOrig).x = fVar1;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMenu_Option_c::initialize(void) */

void __thiscall dMenu_Option_c::initialize(dMenu_Option_c *this)

{
  mainInit(this);
  noteInit(this);
  titleInit(this);
  outFontInit(this);
  this[0xe40] = (dMenu_Option_c)0x1;
  *(undefined2 *)(this + 0xd26) = 0;
  *(undefined2 *)(this + 0x7e6) = 0;
  *(undefined2 *)(this + 0xcb6) = 0;
  *(undefined2 *)(this + 0xcee) = 0;
  this[0xe3c] = (dMenu_Option_c)
                d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig.field_0x2;
  this[0xe3d] = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_;
  this[0xe3e] = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_;
  if ((_sRumbleSupported & 0x80000000) == 0) {
    this[0xe3f] = (dMenu_Option_c)0x0;
  }
  else {
    this[0xe3f] = d_com_inf_game::g_dComIfG_gameInfo._23555_1_;
  }
  this[0xe41] = (dMenu_Option_c)0x0;
  JAIZelBasic::setOutputMode
            (JAIZelBasic::zel_basic,
             *(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4));
  setSoundMode(this,*(ulong *)(&d_menu_option::soundMode + (uint)(byte)this[0xe3e] * 4));
  return;
}


/* __thiscall dMenu_Option_c::_create(void) */

void __thiscall dMenu_Option_c::_create(dMenu_Option_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_option::_4105;
    local_18.mTL.y = d_menu_option::_4105;
    local_18.mBR.x = d_menu_option::_4723;
    local_18.mBR.y = d_menu_option::_4724;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_option.cpp",0x432,"scrn != 0");
    m_Do_printf::OSPanic("d_menu_option.cpp",0x432,&DAT_803606c1);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"option.blo",*(JKRArchive **)(this + 0xd28));
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_menu_option::_4725,d_menu_option::_4106,0,0x2000);
  }
  *(STControl **)(this + 0xd34) = this_01;
  if (*(int *)(this + 0xd34) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_option.cpp",0x436,"stick != 0");
    m_Do_printf::OSPanic("d_menu_option.cpp",0x436,&DAT_803606c1);
  }
  screenSet(this);
  initialize(this);
  this[0xe40] = (dMenu_Option_c)0x0;
  this[0xe38] = (dMenu_Option_c)0x0;
  this[0xe39] = (dMenu_Option_c)0xa;
  this[0xe3a] = (dMenu_Option_c)0xff;
  this[0xe3b] = (dMenu_Option_c)0xc0;
  uRam803f6fd4 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"オプション画面",
                            (JORReflexible *)&d_menu_option::g_moHIO);
  return;
}


/* __thiscall dMenu_Option_c::_delete(void) */

void __thiscall dMenu_Option_c::_delete(dMenu_Option_c *this)

{
  int *piVar1;
  
  (**(code **)(**(int **)(this + 0xd28) + 0x24))();
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0xd34));
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,cRam803f6fd4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMenu_Option_c::_move(void) */

void __thiscall dMenu_Option_c::_move(dMenu_Option_c *this)

{
  uchar uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = STControl::checkTrigger(*(STControl **)(this + 0xd34));
  if (this[0xe3f] != (dMenu_Option_c)0x0) {
    if ((_sRumbleSupported & 0x80000000) == 0) {
      iVar4 = 0;
      this[0xe3f] = (dMenu_Option_c)0x0;
      uVar3 = 0;
      do {
        if (uVar3 == (byte)this[0xe3f]) {
          f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar4 + 0xac0);
        }
        else {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar4 + 0xac0));
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while ((int)uVar3 < 2);
      cursorScale(this);
    }
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) {
      if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0) {
          if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0) {
            if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2) {
              if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) == 0) {
                this[0xe40] = (dMenu_Option_c)0x3;
                *(undefined2 *)(this + 0xcb6) = 0;
                this[0xe41] = (dMenu_Option_c)0x1;
                d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig.field_0x2 =
                     *(byte *)(this + 0xe3c);
                d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ = this[0xe3d]
                ;
                if ((_sRumbleSupported & 0x80000000) != 0) {
                  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._3_1_ =
                       this[0xe3f];
                }
                d_com_inf_game::g_dComIfG_gameInfo._23555_1_ = this[0xe3f];
                d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_ = this[0xe3e]
                ;
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x84d,(cXyz *)0x0,0,0,d_menu_option::_4189,
                           d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
                goto LAB_801d56d0;
              }
            }
          }
        }
      }
    }
  }
  if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') &&
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0) {
          if ((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2) &&
             ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) == 0)) {
            this[0xe40] = (dMenu_Option_c)0x3;
            this[0xe41] = (dMenu_Option_c)0x1;
            *(undefined2 *)(this + 0xcb6) = 0;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x84d,(cXyz *)0x0,0,0,d_menu_option::_4189,
                       d_menu_option::_4189,d_menu_option::_4220,d_menu_option::_4220,0);
            goto LAB_801d56d0;
          }
        }
      }
    }
  }
  if (uVar1 == '\0') {
    *(undefined2 *)(this + 0x7e6) = 0;
    *(undefined2 *)(this + 0xcee) = 0;
  }
  else {
    if (*(short *)(this + 0xcee) == 0) {
      stickMove(this,uVar1);
    }
    sVar2 = 4;
    if (*(short *)(this + 0x7e6) < 2) {
      sVar2 = 10;
    }
    *(short *)(this + 0xcee) = *(short *)(this + 0xcee) + 1;
    if (sVar2 < *(short *)(this + 0xcee)) {
      if (*(short *)(this + 0x7e6) < 2) {
        *(short *)(this + 0x7e6) = *(short *)(this + 0x7e6) + 1;
      }
      *(undefined2 *)(this + 0xcee) = 0;
    }
  }
LAB_801d56d0:
  yazAnime(this);
  if ((*(short *)(this + 0xb9e) == 2) && ((_sRumbleSupported & 0x80000000) == 0)) {
    *(undefined *)(*(int *)(this + 0x858) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x890) + 0xaa) = 0;
  }
  else {
    *(undefined *)(*(int *)(this + 0x858) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x890) + 0xaa) = 1;
  }
  ccAnime(this);
  outFontMove(this);
  if (this[0xe3d] == (dMenu_Option_c)0x0) {
    *(undefined *)(*(int *)(this + 0x778) + 0xaa) = 1;
  }
  else {
    *(undefined *)(*(int *)(this + 0x778) + 0xaa) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_Option_c::_draw(void) */

void __thiscall dMenu_Option_c::_draw(dMenu_Option_c *this)

{
  float fVar1;
  double dVar2;
  int iVar3;
  dMenu_Option_c *pdVar4;
  int iVar5;
  int iVar6;
  double dVar7;
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
  
  if (this[0xe41] == (dMenu_Option_c)0x0) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x40));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x78));
    iVar3 = 0;
    iVar5 = 0;
    do {
      pdVar4 = this + iVar5;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x740));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x858));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0x9a8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0xac0));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar4 + 0xc80));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 2);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7e8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x820));
    iVar3 = 0;
    iVar5 = 0;
    do {
      if (iVar3 != 1) {
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x8c8));
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 4);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0xa18));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 3);
    iVar3 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0xb30));
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar3 < 6);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcf0));
  }
  else {
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0xcb6),0);
    dVar2 = d_menu_option::_4542;
    fVar1 = (float)((double)d_menu_option::_4189 - dVar7);
    local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3d]);
    *(char *)(*(int *)(this + 8) + 0xac) =
         (char)(int)((float)(local_68 - d_menu_option::_4542) * fVar1);
    local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x75]);
    *(char *)(*(int *)(this + 0x40) + 0xac) = (char)(int)((float)(local_58 - dVar2) * fVar1);
    local_48 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xad]);
    *(char *)(*(int *)(this + 0x78) + 0xac) = (char)(int)((float)(local_48 - dVar2) * fVar1);
    iVar3 = 0;
    iVar5 = 2;
    do {
      pdVar4 = this + iVar3;
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x775]);
      *(char *)(*(int *)(pdVar4 + 0x740) + 0xac) = (char)(int)((float)(local_40 - dVar2) * fVar1);
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x88d]);
      *(char *)(*(int *)(pdVar4 + 0x858) + 0xac) = (char)(int)((float)(local_50 - dVar2) * fVar1);
      local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x9dd]);
      *(char *)(*(int *)(pdVar4 + 0x9a8) + 0xac) = (char)(int)((float)(local_60 - dVar2) * fVar1);
      local_38 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xaf5]);
      *(char *)(*(int *)(pdVar4 + 0xac0) + 0xac) = (char)(int)((float)(local_38 - dVar2) * fVar1);
      local_28 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0xcb5]);
      *(char *)(*(int *)(pdVar4 + 0xc80) + 0xac) = (char)(int)((float)(local_28 - dVar2) * fVar1);
      dVar7 = d_menu_option::_4542;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x7e5]);
    *(char *)(*(int *)(this + 0x7b0) + 0xac) =
         (char)(int)((float)(local_20 - d_menu_option::_4542) * fVar1);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x81d]);
    *(char *)(*(int *)(this + 0x7e8) + 0xac) = (char)(int)((float)(local_30 - dVar7) * fVar1);
    local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x855]);
    *(char *)(*(int *)(this + 0x820) + 0xac) = (char)(int)((float)(local_40 - dVar7) * fVar1);
    iVar5 = 0;
    iVar3 = 0;
    iVar6 = 4;
    do {
      if (iVar5 != 1) {
        local_20 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0x8fd]);
        *(char *)(*(int *)(this + iVar3 + 0x8c8) + 0xac) =
             (char)(int)((float)(local_20 - dVar7) * fVar1);
      }
      dVar2 = d_menu_option::_4542;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar3 = 0;
    iVar5 = 3;
    do {
      local_20 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xa4d]);
      *(char *)(*(int *)(this + iVar3 + 0xa18) + 0xac) =
           (char)(int)((float)(local_20 - dVar2) * fVar1);
      dVar7 = d_menu_option::_4542;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 0;
    iVar5 = 6;
    do {
      local_20 = (double)CONCAT44(0x43300000,(uint)(byte)(this + iVar3)[0xb65]);
      *(char *)(*(int *)(this + iVar3 + 0xb30) + 0xac) =
           (char)(int)((float)(local_20 - dVar7) * fVar1);
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0xd25]);
    *(char *)(*(int *)(this + 0xcf0) + 0xac) =
         (char)(int)((float)(local_20 - d_menu_option::_4542) * fVar1);
  }
  outFontDraw(this);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_option::_4105,d_menu_option::_4105,
                  &(d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent);
  return;
}


/* __thiscall dMenu_Option_c::_open(void) */

undefined4 __thiscall dMenu_Option_c::_open(dMenu_Option_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  d_meter::dMenu_setPushMenuButton(0);
  if (*(short *)(this + 0xcb6) == 0) {
    noteSet(this);
  }
  *(short *)(this + 0xcb6) = *(short *)(this + 0xcb6) + 1;
  if (*(short *)(this + 0xcb6) < 8) {
    mainMove(this);
  }
  else {
    if (*(short *)(this + 0xcb6) < 0xf) {
      noteMove(this);
      titleMove(this);
      _move(this);
      if (*(short *)(this + 0xcb6) == 0xe) {
        this[0xe40] = (dMenu_Option_c)0x2;
        *(undefined2 *)(this + 0xcb6) = 0;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_Option_c::_close(void) */

bool __thiscall dMenu_Option_c::_close(dMenu_Option_c *this)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(this + 0xcb6) + 1;
  *(short *)(this + 0xcb6) = sVar1;
  iVar2 = (int)sVar1;
  f_op_msg_mng::fopMsgM_valueIncrease(10,iVar2,0);
  d_meter::dMenu_setPushMenuButton(2);
  if (9 < iVar2) {
    initialize(this);
    this[0xe40] = (dMenu_Option_c)0x0;
  }
  return 9 < iVar2;
}


/* __thiscall dMo_HIO_c::~dMo_HIO_c(void) */

void __thiscall dMo_HIO_c::_dMo_HIO_c(dMo_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMo_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_option {

void __sinit_d_menu_option_cpp(void)

{
  ::dMo_HIO_c::dMo_HIO_c((dMo_HIO_c *)&g_moHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

