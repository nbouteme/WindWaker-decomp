#include <d_auction_screen.h>
#include <f_op_msg_mng.h>
#include <d_auction_screen.h>
#include <J2DGraph/J2DPicture.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DScreen.h>
#include <d_com_inf_game.h>
#include <d_resorce.h>
#include <m_Do_ext.h>
#include <d_meter.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dAuction_screen_c.h>
#include <dAs_HIO_c.h>
#include <dAs_c.h>


namespace d_auction_screen {
undefined g_asHIO;
undefined1 talkmode;
undefined1 talkFlag;
undefined1 slotShow;
undefined1 gaugeShow;
undefined1 gaugeTrans;
undefined2 gaugeTransTimer;
}

/* __thiscall dAs_HIO_c::dAs_HIO_c(void) */

void __thiscall dAs_HIO_c::dAs_HIO_c(dAs_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall dAuction_screen_c::screenSet(void) */

void __thiscall dAuction_screen_c::screenSet(dAuction_screen_c *this)

{
  J2DScreen *pJVar1;
  int iVar2;
  
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x636c6970);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x44),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x7c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xb4),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xec),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x124),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d3035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69636f6e);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x194),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cc),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x204),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x23c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x274),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643034);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2ac),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x67643035);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2e4),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69703030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x31c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69703031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x354),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69703032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x38c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69703033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3c4),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6d657431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3fc),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6d657432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x434),pJVar1);
  iVar2 = *(int *)(this + 0xc);
  *(undefined *)(iVar2 + 0x104) = 0xff;
  *(undefined *)(iVar2 + 0x105) = 0xff;
  *(undefined *)(iVar2 + 0x106) = 0xff;
  *(undefined *)(iVar2 + 0x107) = 0;
  return;
}


/* __thiscall dAuction_screen_c::initPosSet(fopMsgM_pane_class *,
                                            float,
                                            float) */

void __thiscall
dAuction_screen_c::initPosSet
          (dAuction_screen_c *this,fopMsgM_pane_class *param_1,float param_2,float param_3)

{
  float fVar1;
  
  fVar1 = d_auction_screen::_4038;
  (param_1->mPosCenterOrig).x =
       param_2 + (param_1->mPosTopLeftOrig).x + (param_1->mSizeOrig).x * d_auction_screen::_4038;
  (param_1->mPosCenterOrig).y =
       param_3 + (param_1->mPosTopLeftOrig).y + (param_1->mSizeOrig).y * fVar1;
  return;
}


/* __thiscall dAuction_screen_c::gaugeMove(void) */

void __thiscall dAuction_screen_c::gaugeMove(dAuction_screen_c *this)

{
  double dVar1;
  double dVar2;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._23488_2_ < 0x65) {
    *(float *)(this + 0x460) =
         (*(float *)(this + 0x420) *
         (float)((double)CONCAT44(0x43300000,
                                  (int)d_com_inf_game::g_dComIfG_gameInfo._23488_2_ ^ 0x80000000) -
                d_auction_screen::_4053)) / d_auction_screen::_4050;
    *(float *)(this + 0x450) =
         *(float *)(this + 0x438) + *(float *)(this + 0x460) * d_auction_screen::_4038;
  }
  d_auction_screen::dAs_timerCalc();
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,7 - d_auction_screen::gaugeTransTimer,0);
  dVar1 = (double)d_auction_screen::_4051;
  *(float *)(this + 0x41c) = *(float *)(this + 0x414) + (float)(dVar1 * dVar2);
  *(float *)(this + 0x454) = *(float *)(this + 0x44c) + (float)(dVar1 * dVar2);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x3fc));
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x434));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAuction_screen_c::nowRupeeSet(void) */

void __thiscall dAuction_screen_c::nowRupeeSet(dAuction_screen_c *this)

{
  short sVar1;
  
  sVar1 = *(short *)(this + 0x472);
  changeNumberTexture(this,*(J2DPane **)(this + 0x44),(int)(sVar1 / 100));
  changeNumberTexture(this,*(J2DPane **)(this + 0x7c),(int)(short)(((int)sVar1 % 100) / 10));
  changeNumberTexture(this,*(J2DPane **)(this + 0xb4),(int)(sVar1 % 10));
  return;
}


/* __thiscall dAuction_screen_c::nextRupeeSet(short) */

void __thiscall dAuction_screen_c::nextRupeeSet(dAuction_screen_c *this,short param_1)

{
  changeNumberTexture(this,*(J2DPane **)(this + 0xec),(int)(param_1 / 100));
  changeNumberTexture(this,*(J2DPane **)(this + 0x124),(int)(short)(((int)param_1 % 100) / 10));
  changeNumberTexture(this,*(J2DPane **)(this + 0x15c),(int)(param_1 % 10));
  return;
}


/* __thiscall dAuction_screen_c::changeNumberTexture(J2DPane *,
                                                     int) */

void __thiscall
dAuction_screen_c::changeNumberTexture(dAuction_screen_c *this,J2DPane *param_1,int param_2)

{
  if ((param_2 < 0) || (9 < param_2)) {
    param_2 = 0;
  }
  J2DPicture::changeTexture((J2DPicture *)param_1,(&d_auction_screen::number_4067)[param_2],0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8015fe18) */
/* WARNING: Removing unreachable block (ram,0x8015fe10) */
/* WARNING: Removing unreachable block (ram,0x8015fe20) */
/* __thiscall dAuction_screen_c::rupeeCountTrans(void) */

void __thiscall dAuction_screen_c::rupeeCountTrans(dAuction_screen_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f29;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
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
  dVar4 = (double)d_auction_screen::_4110;
  if (d_auction_screen::talkmode == '\0') {
    if (*(short *)(this + 0x1ca) < 1) {
      *(undefined2 *)(this + 0x1ca) = 0;
    }
    else {
      *(short *)(this + 0x1ca) = *(short *)(this + 0x1ca) + -1;
    }
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1ca),0);
    dVar6 = (double)d_auction_screen::_4111;
    dVar5 = (double)(float)((double)d_auction_screen::_4112 * dVar4);
  }
  else {
    if (*(short *)(this + 0x1ca) < 10) {
      *(short *)(this + 0x1ca) = *(short *)(this + 0x1ca) + 1;
      iVar1 = (int)*(short *)(this + 0x1ca);
      if (iVar1 < 5) {
        dVar5 = (double)d_auction_screen::_4111;
        dVar6 = dVar5;
        dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,5 - iVar1,0);
      }
      else {
        dVar6 = (double)d_auction_screen::_4111;
        dVar5 = (double)d_auction_screen::_4112;
        dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,iVar1 + -5,0);
      }
    }
    else {
      *(undefined2 *)(this + 0x1ca) = 10;
      dVar6 = (double)d_auction_screen::_4111;
      dVar5 = (double)d_auction_screen::_4112;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x44),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb4),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xec),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x124),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x15c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x194),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1cc),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x204),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x274),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2ac),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2e4),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x31c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x354),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x38c),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3c4),(float)dVar4);
  }
  initPosSet(this,(fopMsgM_pane_class *)(this + 0xc),(float)dVar6,(float)dVar5);
  initPosSet(this,(fopMsgM_pane_class *)(this + 0x194),(float)dVar6,(float)dVar5);
  iVar1 = 0;
  iVar2 = 0;
  do {
    initPosSet(this,(fopMsgM_pane_class *)(this + iVar2 + 0x1cc),(float)dVar6,(float)dVar5);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  iVar1 = 0;
  iVar2 = 0;
  do {
    initPosSet(this,(fopMsgM_pane_class *)(this + iVar2 + 0x31c),(float)dVar6,(float)dVar5);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc),(double)d_auction_screen::_4111,
             (double)d_auction_screen::_4111);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x194),(double)d_auction_screen::_4111,
             (double)d_auction_screen::_4111);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar2 + 0x1cc),(double)d_auction_screen::_4111,
               (double)d_auction_screen::_4111);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar2 + 0x31c),(double)d_auction_screen::_4111,
               (double)d_auction_screen::_4111);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8015ffb8) */
/* __thiscall dAuction_screen_c::rupeeCountUp(void) */

void __thiscall dAuction_screen_c::rupeeCountUp(dAuction_screen_c *this)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)(*(float *)(this + 0x5c) - *(float *)(this + 0x104));
  if (2 < *(short *)(this + 0x470)) {
    *(undefined2 *)(this + 0x470) = 0;
  }
  *(short *)(this + 0x470) = *(short *)(this + 0x470) + 1;
  if (2 < *(short *)(this + 0x470)) {
    *(undefined2 *)(this + 0x470) = 0;
    *(short *)(this + 0x472) = *(short *)(this + 0x472) + 1;
    nowRupeeSet(this);
    nextRupeeSet(this,*(short *)(this + 0x472) + 1);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8df,(cXyz *)0x0,0,0,d_auction_screen::_4110,
               d_auction_screen::_4110,d_auction_screen::_4131,d_auction_screen::_4131,0);
  }
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,(int)*(short *)(this + 0x470),2);
  dVar3 = (double)(float)(dVar3 * dVar2);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xb4),(double)d_auction_screen::_4111,dVar3);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x15c),(double)d_auction_screen::_4111,dVar3);
  if (((int)*(short *)(this + 0x472) % 10 == 9) || (*(short *)(this + 0x470) == 0)) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x7c),(double)d_auction_screen::_4111,dVar3);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x124),(double)d_auction_screen::_4111,dVar3);
  }
  if (((int)*(short *)(this + 0x472) % 100 == 99) || (*(short *)(this + 0x470) == 0)) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x44),(double)d_auction_screen::_4111,dVar3);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0xec),(double)d_auction_screen::_4111,dVar3);
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80160120) */
/* __thiscall dAuction_screen_c::rupeeCountDown(void) */

void __thiscall dAuction_screen_c::rupeeCountDown(dAuction_screen_c *this)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)(*(float *)(this + 0x5c) - *(float *)(this + 0x104));
  if (*(short *)(this + 0x470) < 1) {
    *(undefined2 *)(this + 0x470) = 3;
  }
  *(short *)(this + 0x470) = *(short *)(this + 0x470) + -1;
  if (*(short *)(this + 0x470) < 1) {
    *(undefined2 *)(this + 0x470) = 3;
    *(short *)(this + 0x472) = *(short *)(this + 0x472) + -1;
    nowRupeeSet(this);
  }
  nextRupeeSet(this,*(short *)(this + 0x472) + 1);
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,3 - *(short *)(this + 0x470),2);
  dVar3 = (double)(float)(-dVar3 * dVar2);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xb4),(double)d_auction_screen::_4111,dVar3);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x15c),(double)d_auction_screen::_4111,dVar3);
  if (((int)*(short *)(this + 0x472) == ((int)*(short *)(this + 0x472) / 10) * 10) ||
     (*(short *)(this + 0x470) == 3)) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x7c),(double)d_auction_screen::_4111,dVar3);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x124),(double)d_auction_screen::_4111,dVar3);
  }
  if (((int)*(short *)(this + 0x472) == ((int)*(short *)(this + 0x472) / 100) * 100) ||
     (*(short *)(this + 0x470) == 3)) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x44),(double)d_auction_screen::_4111,dVar3);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0xec),(double)d_auction_screen::_4111,dVar3);
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80160484) */
/* __thiscall dAuction_screen_c::slotShowAnime(void) */

void __thiscall dAuction_screen_c::slotShowAnime(dAuction_screen_c *this)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_auction_screen::slotShow == '\0') {
    if (0 < *(short *)(this + 0x42)) {
      *(short *)(this + 0x352) = *(short *)(this + 0x352) + -1;
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x352),0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x44),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb4),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xec),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x124),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x15c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x194),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1cc),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x204),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x274),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2ac),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2e4),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x31c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x354),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x38c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3c4),(float)dVar2);
    }
  }
  else {
    if (*(short *)(this + 0x42) < 8) {
      *(short *)(this + 0x42) = *(short *)(this + 0x42) + 1;
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x42),0);
      dVar2 = (double)(d_auction_screen::_4166 * (float)((double)d_auction_screen::_4110 - dVar2));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xc),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x194),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1cc),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x204),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x23c),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x274),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2ac),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2e4),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x31c),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x354),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x38c),dVar2,(double)d_auction_screen::_4112);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x3c4),dVar2,(double)d_auction_screen::_4112);
      if ((7 < *(short *)(this + 0x42)) && (d_auction_screen::talkFlag == '\0')) {
        d_auction_screen::talkFlag = '\x01';
        d_auction_screen::talkmode = 1;
        *(undefined2 *)(this + 0x1ca) = 10;
      }
    }
    if (*(short *)(this + 0x352) < 7) {
      *(short *)(this + 0x352) = *(short *)(this + 0x352) + 1;
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x352),0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x44),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb4),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xec),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x124),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x15c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x194),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1cc),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x204),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x23c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x274),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2ac),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2e4),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x31c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x354),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x38c),(float)dVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3c4),(float)dVar2);
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __thiscall dAuction_screen_c::gaugeShowAnime(void) */

void __thiscall dAuction_screen_c::gaugeShowAnime(dAuction_screen_c *this)

{
  double dVar1;
  
  if (d_auction_screen::gaugeShow == '\0') {
    if (0 < *(short *)(this + 0x432)) {
      *(short *)(this + 0x432) = *(short *)(this + 0x432) + -1;
      dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x432),0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3fc),(float)dVar1);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x434),(float)dVar1);
    }
  }
  else {
    if (*(short *)(this + 0x432) < 7) {
      *(short *)(this + 0x432) = *(short *)(this + 0x432) + 1;
      dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x432),0);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3fc),(float)dVar1);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x434),(float)dVar1);
    }
  }
  return;
}


/* __thiscall dAuction_screen_c::initialize(void) */

void __thiscall dAuction_screen_c::initialize(dAuction_screen_c *this)

{
  *(undefined2 *)(this + 0x472) = 0;
  *(undefined2 *)(this + 0x474) = 0;
  *(undefined2 *)(this + 0x470) = 0;
  gaugeMove(this);
  nowRupeeSet(this);
  nextRupeeSet(this,*(short *)(this + 0x472) + 1);
  return;
}


/* __thiscall dAuction_screen_c::_create(void) */

void __thiscall dAuction_screen_c::_create(dAuction_screen_c *this)

{
  J2DPane *pJVar1;
  ulong uVar2;
  TBox2_float_ local_28;
  TBox2_float_ local_18;
  
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_18.mTL.x = d_auction_screen::_4111;
    local_18.mTL.y = d_auction_screen::_4111;
    local_18.mBR.x = d_auction_screen::_4214;
    local_18.mBR.y = d_auction_screen::_4215;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = pJVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_auction_screen.cpp",0x21c,"scrn1 != 0");
    m_Do_printf::OSPanic("d_auction_screen.cpp",0x21c,&DAT_8035e718);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"auction1.blo",*(JKRArchive **)(this + 0x46c));
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_28.mTL.x = d_auction_screen::_4111;
    local_28.mTL.y = d_auction_screen::_4111;
    local_28.mBR.x = d_auction_screen::_4214;
    local_28.mBR.y = d_auction_screen::_4215;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 8) = pJVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_auction_screen.cpp",0x220,"scrn2 != 0");
    m_Do_printf::OSPanic("d_auction_screen.cpp",0x220,&DAT_8035e718);
  }
  J2DScreen::set(*(J2DScreen **)(this + 8),"auction2.blo",*(JKRArchive **)(this + 0x46c));
  screenSet(this);
  initialize(this);
  return;
}


/* __thiscall dAuction_screen_c::_move(void) */

void __thiscall dAuction_screen_c::_move(dAuction_screen_c *this)

{
  short sVar1;
  
  gaugeMove(this);
  rupeeCountTrans(this);
  sVar1 = *(short *)(this + 0x472);
  if (sVar1 < d_com_inf_game::g_dComIfG_gameInfo._23486_2_) {
    if (sVar1 == 0) {
      *(short *)(this + 0x472) = d_com_inf_game::g_dComIfG_gameInfo._23486_2_;
      nowRupeeSet(this);
      nextRupeeSet(this,*(short *)(this + 0x472) + 1);
    }
    else {
      rupeeCountUp(this);
      if (*(short *)(this + 0x472) == d_com_inf_game::g_dComIfG_gameInfo._23486_2_) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8e0,(cXyz *)0x0,0,0,d_auction_screen::_4110,
                   d_auction_screen::_4110,d_auction_screen::_4131,d_auction_screen::_4131,0);
      }
    }
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo._23486_2_ < sVar1) {
      rupeeCountDown(this);
    }
  }
  slotShowAnime(this);
  gaugeShowAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dAuction_screen_c::_draw(void) */

void __thiscall dAuction_screen_c::_draw(dAuction_screen_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x44));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0xec));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x194));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1cc));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 6);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x31c));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3fc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x434));
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  *(undefined *)(*(int *)(this + 4) + 0xcc) = 1;
  J2DScreen::draw(*(J2DScreen **)(this + 8),d_auction_screen::_4111,d_auction_screen::_4111,
                  &pCtx->parent);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_auction_screen::_4111,d_auction_screen::_4111,
                  &pCtx->parent);
  return;
}


/* __thiscall dAuction_screen_c::_open(void) */

undefined4 __thiscall dAuction_screen_c::_open(dAuction_screen_c *this)

{
  *(undefined2 *)(this + 0x470) = 0;
  *(undefined2 *)(this + 0x474) = 5;
  return 1;
}


/* __thiscall dAuction_screen_c::_close(void) */

undefined4 __thiscall dAuction_screen_c::_close(dAuction_screen_c *this)

{
  *(undefined2 *)(this + 0x474) = 0;
  return 1;
}


/* __thiscall dAs_c::_create(void) */

PhaseState __thiscall dAs_c::_create(dAs_c *this)

{
  PhaseState PVar1;
  dRes_info_c *pdVar2;
  ulong uVar3;
  JKRSolidHeap *pJVar4;
  undefined **ppuVar5;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad
                    ((request_of_phase_process_class *)(this + 0x104),"Auction");
  *(undefined4 *)(this + 0x100) = 0;
  this[0x10c] = (dAs_c)0x0;
  d_com_inf_game::g_dComIfG_gameInfo._23488_2_ = 0;
  d_com_inf_game::g_dComIfG_gameInfo._23486_2_ = 0;
  if (PVar1 == cPhs_COMPLEATE_e) {
    pdVar2 = dRes_control_c::getResInfo
                       ("Auction",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pdVar2 == (dRes_info_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_auction_screen.cpp",0x2c6,"resInfo != 0");
      m_Do_printf::OSPanic("d_auction_screen.cpp",0x2c6,&DAT_8035e718);
    }
    pJVar4 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x2960,0x20);
    *(JKRSolidHeap **)(this + 0xfc) = pJVar4;
    if (*(int *)(this + 0xfc) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      ppuVar5 = (undefined **)JKernel::operator_new(0x478);
      if (ppuVar5 != (undefined **)0x0) {
        *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
        *ppuVar5 = &dAuction_screen_c::__vt;
      }
      *(undefined ***)(this + 0x100) = ppuVar5;
      if (*(int *)(this + 0x100) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_auction_screen.cpp",0x2d0,"dAs_scrn != 0");
        m_Do_printf::OSPanic("d_auction_screen.cpp",0x2d0,&DAT_8035e718);
      }
      *(JKRArchive **)(*(int *)(this + 0x100) + 0x46c) = pdVar2->mpArchive;
      dAuction_screen_c::_create(*(dAuction_screen_c **)(this + 0x100));
      m_Do_ext::mDoExt_restoreCurrentHeap();
      m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0xfc));
      PVar1 = cPhs_COMPLEATE_e;
    }
  }
  return PVar1;
}


/* __thiscall dAs_c::_execute(void) */

undefined4 __thiscall dAs_c::_execute(dAs_c *this)

{
  dAs_c dVar1;
  char cVar2;
  
  dVar1 = this[0x10c];
  if (dVar1 == (dAs_c)0x0) {
    cVar2 = dAuction_screen_c::_open(*(dAuction_screen_c **)(this + 0x100));
    if (cVar2 != '\0') {
      this[0x10c] = (dAs_c)0x1;
    }
  }
  else {
    if (dVar1 == (dAs_c)0x1) {
      dAuction_screen_c::_move(*(dAuction_screen_c **)(this + 0x100));
      cVar2 = d_meter::dMeter_isAuctionFlag();
      if (cVar2 == '\0') {
        *(undefined2 *)(*(int *)(this + 0x100) + 0x470) = 0;
        this[0x10c] = (dAs_c)0x3;
      }
    }
    else {
      if (dVar1 == (dAs_c)0x2) {
        if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10U) == 0) {
          this[0x10c] = (dAs_c)0x1;
        }
      }
      else {
        if ((dVar1 == (dAs_c)0x3) &&
           (cVar2 = dAuction_screen_c::_close(*(dAuction_screen_c **)(this + 0x100)), cVar2 != '\0')
           ) {
          f_op_msg_mng::fopMsgM_Delete(this);
        }
      }
    }
  }
  return 1;
}


/* __thiscall dAs_c::_draw(void) */

undefined4 __thiscall dAs_c::_draw(dAs_c *this)

{
  if (*(dDlst_base_c **)(this + 0x100) != (dDlst_base_c *)0x0) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(this + 0x100));
  }
  return 1;
}


/* __thiscall dAs_c::_delete(void) */

undefined4 __thiscall dAs_c::_delete(dAs_c *this)

{
  if (*(int *)(this + 0xfc) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x104),"Auction");
  return 1;
}


namespace d_auction_screen {

/* __stdcall dAs_Draw(dAs_c *) */

void dAs_Draw(dAs_c *param_1)

{
  ::dAs_c::_draw(param_1);
  return;
}


/* __stdcall dAs_Execute(dAs_c *) */

void dAs_Execute(dAs_c *param_1)

{
  ::dAs_c::_execute(param_1);
  return;
}


/* __stdcall dAs_IsDelete(dAs_c *) */

undefined4 dAs_IsDelete(void)

{
  return 1;
}


/* __stdcall dAs_Delete(dAs_c *) */

void dAs_Delete(dAs_c *param_1)

{
  dAuction_screen_delete();
  ::dAs_c::_delete(param_1);
  return;
}


/* __stdcall dAs_Create(msg_class *) */

void dAs_Create(dAs_c *param_1)

{
  talkFlag = 0;
  ::dAs_c::_create(param_1);
  return;
}


/* __stdcall dAuction_screen_create(void) */

undefined4 dAuction_screen_create(void)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = d_meter::dMeter_isAuctionFlag();
  if (cVar2 == '\0') {
    d_meter::dMeter_onAuctionFlag();
    uVar1 = f_op_msg_mng::fopMsgM_create
                      (0x1ed,(fopAc_ac_c *)0x0,(cXyz *)0x0,(int *)0x0,(int *)0x0,(undefined *)0x0);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* __stdcall dAuction_screen_delete(void) */

bool dAuction_screen_delete(void)

{
  char cVar1;
  
  cVar1 = d_meter::dMeter_isAuctionFlag();
  if (cVar1 != '\0') {
    d_meter::dMeter_offAuctionFlag();
  }
  return cVar1 != '\0';
}


/* __stdcall dAuction_screen_talkStart(void) */

undefined4 dAuction_screen_talkStart(void)

{
  talkmode = 1;
  return 1;
}


/* __stdcall dAuction_screen_talkEnd(void) */

undefined4 dAuction_screen_talkEnd(void)

{
  talkmode = 0;
  return 1;
}


/* __stdcall dAuction_screen_slotShow(void) */

undefined4 dAuction_screen_slotShow(void)

{
  slotShow = 1;
  return 1;
}


/* __stdcall dAuction_screen_slotHide(void) */

undefined4 dAuction_screen_slotHide(void)

{
  slotShow = 0;
  return 1;
}


/* __stdcall dAuction_screen_gaugeShow(void) */

undefined4 dAuction_screen_gaugeShow(void)

{
  gaugeShow = 1;
  return 1;
}


/* __stdcall dAuction_screen_gaugeHide(void) */

undefined4 dAuction_screen_gaugeHide(void)

{
  gaugeShow = 0;
  return 1;
}


/* __stdcall dAuction_screen_gaugeUp(void) */

undefined4 dAuction_screen_gaugeUp(void)

{
  gaugeTrans = 1;
  return 1;
}


/* __stdcall dAuction_screen_gaugeDown(void) */

undefined4 dAuction_screen_gaugeDown(void)

{
  gaugeTrans = 0;
  return 1;
}


/* __stdcall dAs_timerCalc(void) */

void dAs_timerCalc(void)

{
  if (gaugeTrans != '\0') {
    if (6 < gaugeTransTimer) {
      return;
    }
    gaugeTransTimer = gaugeTransTimer + 1;
    return;
  }
  if (gaugeTransTimer < 1) {
    return;
  }
  gaugeTransTimer = gaugeTransTimer + -1;
  return;
}

}

/* __thiscall dAuction_screen_c::~dAuction_screen_c(void) */

void __thiscall dAuction_screen_c::_dAuction_screen_c(dAuction_screen_c *this)

{
  short in_r4;
  
  if (this != (dAuction_screen_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dAuction_screen_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dAuction_screen_c::draw(void) */

void __thiscall dAuction_screen_c::draw(dAuction_screen_c *this)

{
  _draw(this);
  return;
}


/* __thiscall dAs_HIO_c::~dAs_HIO_c(void) */

void __thiscall dAs_HIO_c::_dAs_HIO_c(dAs_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dAs_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_auction_screen {

void __sinit_d_auction_screen_cpp(void)

{
  ::dAs_HIO_c::dAs_HIO_c((dAs_HIO_c *)&g_asHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

