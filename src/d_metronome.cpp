#include <d_metronome.h>
#include <f_op_msg_mng.h>
#include <d_a_player_main.h>
#include <d_metronome.h>
#include <d_particle.h>
#include <m_Do_lib.h>
#include <JAZelAudio/JAIZelInst.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DScreen.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMetronome_c.h>
#include <dMn_HIO_c.h>


namespace d_metronome {
undefined g_mnHIO;
}

/* __thiscall dMn_HIO_c::dMn_HIO_c(void) */

void __thiscall dMn_HIO_c::dMn_HIO_c(dMn_HIO_c *this)

{
  *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  *(float *)(this + 4) = d_metronome::_4072;
  *(undefined2 *)(this + 8) = 0xb;
  *(undefined2 *)(this + 10) = 5;
  this[0x1c] = (dMn_HIO_c)0xff;
  this[0x1d] = (dMn_HIO_c)0x0;
  this[0xc] = (dMn_HIO_c)0xff;
  this[0xd] = (dMn_HIO_c)0xff;
  this[0xe] = (dMn_HIO_c)0xff;
  this[0xf] = (dMn_HIO_c)0xff;
  this[0x14] = (dMn_HIO_c)0xff;
  this[0x15] = (dMn_HIO_c)0xff;
  this[0x16] = (dMn_HIO_c)0xff;
  this[0x17] = (dMn_HIO_c)0x0;
  this[0x10] = (dMn_HIO_c)0xff;
  this[0x11] = (dMn_HIO_c)0xb9;
  this[0x12] = (dMn_HIO_c)0x0;
  this[0x13] = (dMn_HIO_c)0xff;
  this[0x18] = (dMn_HIO_c)0xff;
  this[0x19] = (dMn_HIO_c)0xb9;
  this[0x1a] = (dMn_HIO_c)0x0;
  this[0x1b] = (dMn_HIO_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall dMetronome_c::screenSet(void) */

void __thiscall dMetronome_c::screenSet(dMetronome_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = (int)&this->vtbl + iVar4;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 8),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::cn_t1_4083 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 400),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::wn_t1_4084 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 0x318),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::pk_t1_4085 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 0x628),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::i11_t1_4086 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 0x4a0),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::i12_t1_4087 + iVar3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(iVar2 + 0x7b0),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::bs_t1_4088 + iVar3));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 0x38;
  } while (iVar1 < 7);
  iVar1 = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x938 + iVar3),*(J2DScreen **)&this->field_0x4,
               *(int *)((int)&d_metronome::timing_t_4089 + iVar4));
    iVar1 = iVar1 + 1;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 0x15);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)&this->field_0xdd0,*(J2DScreen **)&this->field_0x4,0x313132);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x802222b8) */
/* __thiscall dMetronome_c::metronomeMove(void) */

void __thiscall dMetronome_c::metronomeMove(dMetronome_c *this)

{
  short sVar1;
  undefined3 uVar2;
  uint uVar3;
  undefined uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined local_88;
  undefined uStack135;
  undefined uStack134;
  undefined local_84;
  undefined uStack131;
  undefined uStack130;
  uint local_5c;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar11 = (double)daPy_lk_c::getTactMetronomeRate
                             (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  iVar9 = (int)((double)d_metronome::_4270 * dVar11);
  if (iVar9 < 0x15) {
    if (iVar9 < 0) {
      iVar9 = 0;
    }
  }
  else {
    iVar9 = 0x14;
  }
  if (iVar9 != *(int *)&this->field_0xe34) {
    *(undefined2 *)(&this->field_0x96e + *(int *)&this->field_0xe34 * 0x38) = 5;
  }
  if (*(char *)&this->field_0xe38 == '\0') {
    dVar11 = (double)daPy_lk_c::getTactMetronomeRate
                               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
    if (dVar11 < (double)*(float *)&this->field_0xe0c) {
      *(undefined *)&this->field_0xe38 = 1;
    }
    if (iVar9 < 0xb) {
      iVar9 = iVar9 + 10;
    }
    else {
      iVar9 = 0x1e - iVar9;
    }
  }
  else {
    dVar11 = (double)daPy_lk_c::getTactMetronomeRate
                               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
    if (dVar11 < (double)*(float *)&this->field_0xe0c) {
      *(undefined *)&this->field_0xe38 = 0;
    }
    if (iVar9 < 0xb) {
      iVar9 = 10 - iVar9;
    }
    else {
      iVar9 = iVar9 + -10;
    }
  }
  if (((*(short *)&this->field_0x26e == 0) && (iVar9 == 10)) && (*(short *)&this->field_0xe06 == 0))
  {
    *(undefined2 *)&this->field_0xe06 = 1;
  }
  sVar1 = *(short *)&this->field_0xe06;
  if (sVar1 != 0) {
    if (sVar1 < 10) {
      dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - sVar1,0);
      dVar12 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)&this->field_0xe06,0);
      dVar12 = (double)(d_metronome::_4272 +
                       (float)((double)(DAT_803e7000 - d_metronome::_4272) * dVar12));
      *(short *)&this->field_0xe06 = *(short *)&this->field_0xe06 + 1;
    }
    else {
      dVar12 = (double)d_metronome::_4271;
      *(undefined2 *)&this->field_0xe06 = 0;
      dVar11 = dVar12;
    }
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)&this->field_0xdd0,(float)dVar12);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0xdd0,(float)dVar11);
  }
  dVar11 = (double)daPy_lk_c::getTactMetronomeRate
                             (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  *(float *)&this->field_0xe0c = (float)dVar11;
  *(int *)&this->field_0xe34 = iVar9;
  iVar8 = 0;
  iVar7 = 0;
  do {
    if (iVar8 == iVar9) {
      if (iVar8 == 10) {
        iVar6 = *(int *)(&this->field_0x938 + iVar7);
        *(undefined *)(iVar6 + 0x108) = 0xff;
        *(undefined *)(iVar6 + 0x109) = 0x50;
        *(undefined *)(iVar6 + 0x10a) = 0x50;
        *(undefined *)(iVar6 + 0x10b) = 0;
        iVar6 = *(int *)(&this->field_0x938 + iVar7);
        *(undefined *)(iVar6 + 0x104) = 0xff;
        *(undefined *)(iVar6 + 0x105) = 0x50;
        *(undefined *)(iVar6 + 0x106) = 0x50;
        *(undefined *)(iVar6 + 0x107) = 0xff;
      }
      else {
        iVar6 = *(int *)(&this->field_0x938 + iVar7);
        *(undefined *)(iVar6 + 0x108) = 0xff;
        *(undefined *)(iVar6 + 0x109) = 0xb9;
        *(undefined *)(iVar6 + 0x10a) = 0;
        *(undefined *)(iVar6 + 0x10b) = 0;
        iVar6 = *(int *)(&this->field_0x938 + iVar7);
        *(undefined *)(iVar6 + 0x104) = 0xff;
        *(undefined *)(iVar6 + 0x105) = 0xb9;
        *(undefined *)(iVar6 + 0x106) = 0;
        *(undefined *)(iVar6 + 0x107) = 0xff;
      }
    }
    else {
      iVar6 = (int)&this->vtbl + iVar7;
      if ((*(short *)(iVar6 + 0x96e) == 0) || (DAT_803e7019 == '\0')) {
        iVar5 = *(int *)(iVar6 + 0x938);
        *(undefined *)(iVar5 + 0x108) = 0;
        *(undefined *)(iVar5 + 0x109) = 0;
        *(undefined *)(iVar5 + 0x10a) = 0;
        *(undefined *)(iVar5 + 0x10b) = 0;
        iVar6 = *(int *)(iVar6 + 0x938);
        *(undefined *)(iVar6 + 0x104) = 0xff;
        *(undefined *)(iVar6 + 0x105) = 0xff;
        *(undefined *)(iVar6 + 0x106) = 0xff;
        *(undefined *)(iVar6 + 0x107) = 0xff;
      }
      else {
        *(short *)(iVar6 + 0x96e) = *(short *)(iVar6 + 0x96e) + -1;
        dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(iVar6 + 0x96e),0);
        if (iVar8 == 10) {
          uVar4 = (undefined)(int)-(float)((double)d_metronome::_4274 * dVar11);
          uVar3 = (uint)CONCAT21(CONCAT11((char)(int)-(float)((double)d_metronome::_4273 * dVar11),
                                          uVar4),uVar4);
          uVar4 = (undefined)
                  (int)(d_metronome::_4275 - (float)((double)d_metronome::_4276 * dVar11));
          uVar2 = CONCAT21(CONCAT11(0xff,uVar4),uVar4);
        }
        else {
          local_5c = (uint)CONCAT11((char)(int)-(float)((double)d_metronome::_4273 * dVar11),
                                    (char)(int)-(float)((double)d_metronome::_4277 * dVar11)) <<
                     0x10;
          uVar3 = local_5c >> 8;
          dVar12 = (double)d_metronome::_4275;
          uVar2 = CONCAT21(CONCAT11(0xff,(char)(int)(dVar12 - (double)(float)((double)d_metronome::
                                                                                      _4278 * dVar11
                                                                             ))),
                           (char)(int)(dVar12 - (double)(float)(dVar12 * dVar11)));
        }
        local_5c = uVar3 << 8;
        iVar5 = *(int *)(iVar6 + 0x938);
        local_84 = (undefined)(local_5c >> 0x18);
        *(undefined *)(iVar5 + 0x108) = local_84;
        uStack131 = (undefined)(local_5c >> 0x10);
        *(undefined *)(iVar5 + 0x109) = uStack131;
        uStack130 = (undefined)uVar3;
        *(undefined *)(iVar5 + 0x10a) = uStack130;
        *(undefined *)(iVar5 + 0x10b) = 0;
        iVar6 = *(int *)(iVar6 + 0x938);
        local_88 = (undefined)((uint3)uVar2 >> 0x10);
        *(undefined *)(iVar6 + 0x104) = local_88;
        uStack135 = (undefined)((uint3)uVar2 >> 8);
        *(undefined *)(iVar6 + 0x105) = uStack135;
        uStack134 = (undefined)uVar2;
        *(undefined *)(iVar6 + 0x106) = uStack134;
        *(undefined *)(iVar6 + 0x107) = 0xff;
      }
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar8 < 0x15);
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dMetronome_c::melodyInit(unsigned char) */

void __thiscall dMetronome_c::melodyInit(dMetronome_c *this,uchar param_1)

{
  uint uVar1;
  int iVar2;
  fopMsgM_pane_class *this_00;
  int iVar3;
  fopMsgM_pane_class *this_01;
  int iVar4;
  double dVar5;
  
  *(undefined2 *)&this->field_0x236 = 0;
  *(undefined2 *)&this->field_0x26e = 0;
  this->field_0x2a6 = 0;
  *(undefined2 *)&this->field_0x2de = 0;
  *(undefined2 *)&this->field_0xe06 = 10;
  dVar5 = (double)daPy_lk_c::getTactMetronomeRate
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  *(int *)&this->field_0xe34 = (int)((double)d_metronome::_4270 * dVar5);
  if (*(int *)&this->field_0xe34 < 0x15) {
    if (*(int *)&this->field_0xe34 < 0) {
      *(undefined4 *)&this->field_0xe34 = 0;
    }
  }
  else {
    *(undefined4 *)&this->field_0xe34 = 0x14;
  }
  iVar2 = 0;
  iVar4 = 0x15;
  do {
    *(undefined2 *)(&this->field_0x96e + iVar2) = 0;
    iVar2 = iVar2 + 0x38;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar1 = (uint)param_1;
  if (uVar1 != 5) {
    if (uVar1 < 5) {
      if (uVar1 == 3) {
        *(float *)&this->field_0xe10 =
             (*(float *)&this->field_0x7fc + *(float *)&this->field_0x834) * d_metronome::_4322;
      }
      else {
        if (2 < uVar1) {
          *(undefined4 *)&this->field_0xe10 = *(undefined4 *)&this->field_0x7fc;
        }
      }
    }
    else {
      if (uVar1 < 7) {
        *(undefined4 *)&this->field_0xe10 = *(undefined4 *)&this->field_0x7c4;
      }
    }
  }
  iVar2 = 0;
  iVar4 = 0;
  do {
    iVar3 = (int)&this->vtbl + iVar4;
    *(undefined2 *)(iVar3 + 0x7e6) = 0;
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)&this->field_0xe10;
    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar3 + 0x1ac) = *(undefined4 *)&this->field_0xe10;
    *(undefined4 *)(iVar3 + 0x334) = *(undefined4 *)&this->field_0xe10;
    *(undefined4 *)(iVar3 + 0x644) = *(undefined4 *)&this->field_0xe10;
    *(undefined4 *)(iVar3 + 0x4bc) = *(undefined4 *)&this->field_0xe10;
    *(undefined4 *)(iVar3 + 0x7cc) = *(undefined4 *)&this->field_0xe10;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 8));
    this_00 = (fopMsgM_pane_class *)(iVar3 + 400);
    f_op_msg_mng::fopMsgM_cposMove(this_00);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x318));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x628));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x4a0));
    this_01 = (fopMsgM_pane_class *)(iVar3 + 0x7b0);
    f_op_msg_mng::fopMsgM_cposMove(this_01);
    if (iVar2 < (int)uVar1) {
      f_op_msg_mng::fopMsgM_setInitAlpha(this_00);
      f_op_msg_mng::fopMsgM_setInitAlpha(this_01);
    }
    else {
      f_op_msg_mng::fopMsgM_setNowAlphaZero(this_00);
      f_op_msg_mng::fopMsgM_setNowAlphaZero(this_01);
    }
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x318));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x628));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x4a0));
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 7);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802225e0) */
/* WARNING: Removing unreachable block (ram,0x802225e8) */
/* __thiscall dMetronome_c::melodyMove(void) */

void __thiscall dMetronome_c::melodyMove(dMetronome_c *this)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,(int)*(short *)&this->field_0x1fe,0);
  dVar6 = (double)(float)(dVar6 * (double)(*(float *)&this->field_0x834 -
                                          *(float *)&this->field_0x7fc));
  if (*(short *)&this->field_0x1fe < 3) {
    if (*(short *)&this->field_0x1fe < 1) {
      *(undefined *)&this->field_0xe3a = 0;
    }
  }
  else {
    *(undefined *)&this->field_0xe3a = 2;
  }
  uVar2 = 0;
  iVar4 = 0;
  dVar7 = d_metronome::_4341;
  do {
    fVar1 = *(float *)&this->field_0xe10 +
            (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - dVar7)
                   );
    iVar3 = (int)&this->vtbl + iVar4;
    *(float *)(iVar3 + 0x24) = fVar1;
    *(float *)(iVar3 + 0x1ac) = fVar1;
    *(float *)(iVar3 + 0x334) = fVar1;
    *(float *)(iVar3 + 0x644) = fVar1;
    *(float *)(iVar3 + 0x4bc) = fVar1;
    *(float *)(iVar3 + 0x7cc) = fVar1;
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 8));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 400));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x318));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x628));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x4a0));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x7b0));
    uVar2 = uVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while ((int)uVar2 < 7);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMetronome_c::melodyGuideShow(long,
                                            short) */

void __thiscall dMetronome_c::melodyGuideShow(dMetronome_c *this,long param_1,short param_2)

{
  float fVar1;
  undefined **ppuVar2;
  int *piVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  double local_28;
  double local_20;
  
  local_38 = d_metronome::_4345;
  local_34 = DAT_80362480;
  local_30 = DAT_80362484;
  if (param_1 == 3) {
    ppuVar2 = &this->vtbl + param_2 * 0xe;
    local_20 = (double)(longlong)(int)((float)ppuVar2[0x196] * d_metronome::_4364);
    local_28 = (double)CONCAT44(0x43300000,
                                (int)(short)(int)((float)ppuVar2[0x196] * d_metronome::_4364) ^
                                0x80000000);
    ppuVar2[10] = (undefined *)((float)ppuVar2[10] + (float)(local_28 - d_metronome::_4341));
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        ppuVar2 = &this->vtbl + param_2 * 0xe;
        local_28 = (double)(longlong)(int)((float)ppuVar2[0x196] * d_metronome::_4364);
        local_20 = (double)CONCAT44(0x43300000,
                                    (int)(short)(int)((float)ppuVar2[0x196] * d_metronome::_4364) ^
                                    0x80000000);
        ppuVar2[10] = (undefined *)((float)ppuVar2[10] - (float)(local_20 - d_metronome::_4341));
      }
      else {
        if (0 < param_1) {
          ppuVar2 = &this->vtbl + param_2 * 0xe;
          local_20 = (double)(longlong)(int)((float)ppuVar2[0x195] * d_metronome::_4364);
          *(short *)((int)ppuVar2 + 0x3e) = (short)(int)((float)ppuVar2[0x195] * d_metronome::_4364)
          ;
          local_28 = (double)CONCAT44(0x43300000,(int)*(short *)((int)ppuVar2 + 0x3e) ^ 0x80000000);
          ppuVar2[9] = (undefined *)((float)ppuVar2[9] + (float)(local_28 - d_metronome::_4341));
        }
      }
    }
    else {
      if (param_1 < 5) {
        ppuVar2 = &this->vtbl + param_2 * 0xe;
        local_20 = (double)(longlong)(int)((float)ppuVar2[0x195] * d_metronome::_4364);
        *(short *)((int)ppuVar2 + 0x3e) = (short)(int)((float)ppuVar2[0x195] * d_metronome::_4364);
        local_28 = (double)CONCAT44(0x43300000,(int)*(short *)((int)ppuVar2 + 0x3e) ^ 0x80000000);
        ppuVar2[9] = (undefined *)((float)ppuVar2[9] - (float)(local_28 - d_metronome::_4341));
      }
    }
  }
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(&this->field_0x8 + param_2 * 0x38));
  ppuVar2 = &this->vtbl + param_2 * 0xe;
  fVar1 = (float)ppuVar2[0x196] * d_metronome::_4322;
  piVar3 = (int *)ppuVar2[0x18a];
  piVar3[0x27] = (int)((float)ppuVar2[0x195] * d_metronome::_4322);
  piVar3[0x28] = (int)fVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  local_20 = (double)CONCAT44(0x43300000,(int)*(short *)((int)&local_38 + param_1 * 2) ^ 0x80000000)
  ;
  piVar3[0x29] = (int)(float)(local_20 - d_metronome::_4341);
  (**(code **)(*piVar3 + 0x20))();
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80222c2c) */
/* __thiscall dMetronome_c::melodyShow(void) */

void __thiscall dMetronome_c::melodyShow(dMetronome_c *this)

{
  bool bVar1;
  JPABaseEmitter *pJVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  cXyz local_58;
  cXyz local_4c;
  cXyz acStack64 [2];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a4 & 0x1000000
      ) != 0) {
    local_58.x = d_metronome::_4271;
    local_58.y = d_metronome::_4271;
    local_58.z = d_metronome::_4271;
    iVar3 = (int)(short)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x34d6;
    if ((int)*(short *)&this->field_0x1c6 < (int)(uint)*(byte *)&this->field_0xe39) {
      *(int *)(&this->field_0xe18 + *(short *)&this->field_0x1c6 * 4) = iVar3;
      melodyGuideShow(this,iVar3,*(short *)&this->field_0x1c6);
      *(undefined2 *)(&this->field_0x7e6 + *(short *)&this->field_0x1c6 * 0x38) = 1;
      local_58.x = (float)(&this->vtbl + *(short *)&this->field_0x1c6 * 0xe)[0x6b] -
                   d_metronome::_4472;
      local_58.y = (float)(&this->vtbl + *(short *)&this->field_0x1c6 * 0xe)[0x6c] -
                   d_metronome::_4473;
      *(short *)&this->field_0x1c6 = *(short *)&this->field_0x1c6 + 1;
    }
    else {
      *(int *)(&this->field_0xe14 + (uint)*(byte *)&this->field_0xe39 * 4) = iVar3;
      melodyGuideShow(this,iVar3,*(byte *)&this->field_0xe39 - 1);
      *(undefined2 *)(&this->field_0x7ae + (uint)*(byte *)&this->field_0xe39 * 0x38) = 1;
      local_58.x = (float)(&this->vtbl + (uint)*(byte *)&this->field_0xe39 * 0xe)[0x5d] -
                   d_metronome::_4472;
      local_58.y = (float)(&this->vtbl + (uint)*(byte *)&this->field_0xe39 * 0xe)[0x5e] -
                   d_metronome::_4473;
    }
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x23e,&local_58,
                       (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
    iVar3 = daPy_lk_c::getTactTopPos(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor,acStack64)
    ;
    if (iVar3 != 0) {
      m_Do_lib::mDoLib_project(acStack64,&local_4c);
      local_4c.x = local_4c.x - d_metronome::_4472;
      local_4c.y = local_4c.y - d_metronome::_4473;
      pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x23f,
                                  &local_4c,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      *(JPABaseEmitter **)&this->field_0xe08 = pJVar2;
      *(uint *)(*(int *)&this->field_0xe08 + 0x20c) =
           *(uint *)(*(int *)&this->field_0xe08 + 0x20c) | 0x40;
    }
    iVar3 = daPy_lk_c::checkTactLastInput(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
    if (iVar3 != 0) {
      *(undefined2 *)&this->field_0x34e = 1;
      *(undefined2 *)&this->field_0x386 = 0;
      *(undefined2 *)&this->field_0x26e = 1;
    }
  }
  iVar3 = *(int *)&this->field_0xe08;
  if (iVar3 != 0) {
    bVar1 = false;
    if (((*(uint *)(iVar3 + 0x20c) & 8) != 0) &&
       (*(int *)(iVar3 + 0x184) + *(int *)(iVar3 + 400) == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) & 0xffffffbf;
      *(undefined4 *)&this->field_0xe08 = 0;
    }
    else {
      iVar3 = daPy_lk_c::getTactTopPos
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor,acStack64);
      if (iVar3 != 0) {
        m_Do_lib::mDoLib_project(acStack64,&local_4c);
        local_4c.x = local_4c.x - d_metronome::_4472;
        local_4c.y = local_4c.y - d_metronome::_4473;
        iVar3 = *(int *)&this->field_0xe08;
        *(float *)(iVar3 + 0x1e4) = local_4c.x;
        *(float *)(iVar3 + 0x1e8) = local_4c.y;
        *(float *)(iVar3 + 0x1ec) = local_4c.z;
      }
    }
  }
  uVar6 = 0;
  iVar5 = 0;
  iVar3 = 0;
  do {
    iVar4 = (int)&this->vtbl + iVar3;
    if (*(short *)(iVar4 + 0x7e6) != 0) {
      dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(iVar4 + 0x7e6),0);
      if (uVar6 == *(byte *)&this->field_0xe39) {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar4 + 400),(float)dVar8);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar4 + 0x7b0),(float)dVar8);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar4 + 8));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar4 + 0x628));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar4 + 0x4a0));
      }
      else {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar4 + 8),(float)dVar8);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar4 + 0x628),(float)dVar8);
        if (*(int *)(&this->field_0xe18 + iVar5) == 0) {
          f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar4 + 0x4a0),(float)dVar8);
        }
      }
      if (*(short *)(iVar4 + 0x7e6) < 5) {
        *(short *)(iVar4 + 0x7e6) = *(short *)(iVar4 + 0x7e6) + 1;
      }
      else {
        *(undefined2 *)(iVar4 + 0x7e6) = 0;
      }
      if ((((int)(uint)*(byte *)&this->field_0xe39 <= (int)*(short *)&this->field_0x1c6) &&
          (*(short *)&this->field_0x26e == 0)) &&
         (*(short *)(&this->field_0x7ae + (uint)*(byte *)&this->field_0xe39 * 0x38) == 5)) {
        *(undefined2 *)&this->field_0x236 = 5;
        *(undefined2 *)&this->field_0x1c6 = 0;
        *(undefined2 *)&this->field_0x316 = 0;
        *(undefined *)&this->field_0xe3a = 3;
      }
    }
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 4;
    iVar3 = iVar3 + 0x38;
  } while ((int)uVar6 < 7);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80222d94) */
/* __thiscall dMetronome_c::melodyDemo(void) */

void __thiscall dMetronome_c::melodyDemo(dMetronome_c *this)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  short local_68 [8];
  long alStack88 [6];
  undefined4 local_40;
  uint uStack60;
  longlong local_38;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->field_0x2a6 == 0) {
    iVar3 = daPy_lk_c::checkTactPlayMelody(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
    if (iVar3 != 0) {
      this->field_0x2a6 = 1;
    }
  }
  else {
    lVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->vtbl->getTactMusic)();
    local_68[0] = 1;
    iVar5 = 0;
    iVar4 = 0;
    dVar8 = d_metronome::_4341;
    for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)&this->field_0xe39; iVar3 = iVar3 + 1) {
      dVar7 = (double)JAIZelInst::getMelodyPattern
                                (&mDoAud_zelAudio_c::mTact,lVar2,iVar3,
                                 (long *)((int)alStack88 + iVar4));
      uStack60 = (int)*(short *)((int)local_68 + iVar5) ^ 0x80000000;
      local_40 = 0x43300000;
      iVar1 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack60) - dVar8) + dVar7);
      local_38 = (longlong)iVar1;
      *(short *)((int)local_68 + iVar5 + 2) = (short)iVar1;
      iVar5 = iVar5 + 2;
      iVar4 = iVar4 + 4;
    }
    iVar3 = (int)*(short *)&this->field_0x2de;
    if (iVar3 < (int)(uint)*(byte *)&this->field_0xe39) {
      if (this->field_0x2a6 == local_68[iVar3]) {
        *(undefined2 *)(&this->field_0x7e6 + iVar3 * 0x38) = 1;
        *(short *)&this->field_0x2de = *(short *)&this->field_0x2de + 1;
      }
      this->field_0x2a6 = this->field_0x2a6 + 1;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80222ed0) */
/* __thiscall dMetronome_c::melodyFlash(void) */

void __thiscall dMetronome_c::melodyFlash(dMetronome_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)d_metronome::_4271;
  *(short *)&this->field_0x386 = *(short *)&this->field_0x386 + 1;
  iVar2 = (int)*(short *)&this->field_0x386;
  iVar1 = (int)DAT_803e7006;
  if (iVar2 < iVar1) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar2,0);
  }
  else {
    if (iVar2 < iVar1 * 2) {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1,iVar1 * 2 - iVar2,0);
    }
    else {
      iVar1 = 0;
      *(undefined2 *)&this->field_0x386 = 0;
      *(short *)&this->field_0x34e = *(short *)&this->field_0x34e + 1;
      if (2 < *(short *)&this->field_0x34e) {
        *(undefined2 *)&this->field_0x34e = 0;
        for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)&this->field_0xe39; iVar2 = iVar2 + 1) {
          iVar3 = (int)&this->vtbl + iVar1;
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 8));
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x628));
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar3 + 0x4a0));
          iVar1 = iVar1 + 0x38;
        }
        *(undefined *)&this->field_0xe3a = 4;
      }
    }
  }
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)&this->field_0xe39; iVar1 = iVar1 + 1) {
    iVar3 = (int)&this->vtbl + iVar2;
    *(undefined *)(iVar3 + 0x34c) = DAT_803e7018;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(iVar3 + 0x318),(float)dVar5);
    iVar2 = iVar2 + 0x38;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80222fe4) */
/* WARNING: Removing unreachable block (ram,0x80222fec) */
/* __thiscall dMetronome_c::melodyShift(void) */

void __thiscall dMetronome_c::melodyShift(dMetronome_c *this)

{
  float fVar1;
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
  if (*(short *)&this->field_0x316 < DAT_803e7004) {
    *(short *)&this->field_0x316 = *(short *)&this->field_0x316 + 1;
  }
  else {
    melodyInit(this,*(uchar *)&this->field_0xe39);
    dVar6 = (double)(*(float *)&this->field_0x834 - *(float *)&this->field_0x7fc);
    uVar2 = 0;
    iVar4 = 0;
    dVar7 = d_metronome::_4341;
    do {
      fVar1 = *(float *)&this->field_0xe10 +
              (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                                             dVar7));
      iVar3 = (int)&this->vtbl + iVar4;
      *(float *)(iVar3 + 0x24) = fVar1;
      *(float *)(iVar3 + 0x1ac) = fVar1;
      *(float *)(iVar3 + 0x334) = fVar1;
      *(float *)(iVar3 + 0x644) = fVar1;
      *(float *)(iVar3 + 0x4bc) = fVar1;
      *(float *)(iVar3 + 0x7cc) = fVar1;
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 8));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 400));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x318));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x628));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x4a0));
      f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar3 + 0x7b0));
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x38;
    } while ((int)uVar2 < 7);
    *(undefined *)&this->field_0xe3a = 2;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dMetronome_c::initialize(void) */

void __thiscall dMetronome_c::initialize(dMetronome_c *this)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)daPy_lk_c::getTactMetronomeRate
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  *(float *)&this->field_0xe0c = (float)dVar3;
  *(float *)&this->field_0xe10 = d_metronome::_4271;
  *(undefined *)&this->field_0xe38 = 0;
  *(undefined *)&this->field_0xe39 = DAT_803a2caf;
  *(undefined *)&this->field_0xe3a = 0;
  *(undefined4 *)&this->field_0xe14 = 0;
  iVar1 = 0;
  iVar2 = 7;
  do {
    *(undefined4 *)(&this->field_0xe18 + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)&this->field_0xe3b = 0;
  *(undefined4 *)&this->field_0xe34 = 0;
  *(undefined4 *)&this->field_0xe08 = 0;
  return;
}


/* __thiscall dMetronome_c::_create(void) */

void __thiscall dMetronome_c::_create(dMetronome_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_metronome::_4271;
    local_18.mTL.y = d_metronome::_4271;
    local_18.mBR.x = d_metronome::_4581;
    local_18.mBR.y = d_metronome::_4582;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)&this->field_0x4 = this_00;
  if (*(int *)&this->field_0x4 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_metronome.cpp",0x2db,"scrn != 0");
    m_Do_printf::OSPanic("d_metronome.cpp",0x2db,&DAT_803624a2);
  }
  J2DScreen::set(*(J2DScreen **)&this->field_0x4,"baton_input.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTmsgArchive);
  screenSet(this);
  initialize(this);
  return;
}


/* __thiscall dMetronome_c::_delete(void) */

void __thiscall dMetronome_c::_delete(dMetronome_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)&this->field_0x4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTmsgArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  return;
}


/* __thiscall dMetronome_c::_move(void) */

void __thiscall dMetronome_c::_move(dMetronome_c *this)

{
  char cVar1;
  
  metronomeMove(this);
  if ((*(short *)&this->field_0x26e == 0) && (*(char *)&this->field_0xe39 != DAT_803a2caf)) {
    *(char *)&this->field_0xe39 = DAT_803a2caf;
    *(undefined2 *)&this->field_0x1c6 = 0;
    *(undefined *)&this->field_0xe3a = 5;
  }
  cVar1 = *(char *)&this->field_0xe3a;
  if (cVar1 == '\0') {
    *(undefined *)&this->field_0xe3a = 1;
    *(undefined2 *)&this->field_0x1fe = 0;
    *(undefined2 *)&this->field_0x1c6 = 0;
    melodyInit(this,*(uchar *)&this->field_0xe39);
  }
  else {
    if (cVar1 == '\x01') {
      *(short *)&this->field_0x1fe = *(short *)&this->field_0x1fe + 1;
      melodyMove(this);
    }
    else {
      if (cVar1 == '\x05') {
        *(short *)&this->field_0x1fe = *(short *)&this->field_0x1fe + -1;
        melodyMove(this);
      }
      else {
        if (cVar1 == '\x03') {
          melodyShift(this);
        }
        else {
          if (cVar1 == '\x04') {
            melodyDemo(this);
          }
        }
      }
    }
  }
  if (*(short *)&this->field_0x1fe != 0) {
    melodyShow(this);
  }
  if (*(short *)&this->field_0x34e != 0) {
    melodyFlash(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMetronome_c::_draw(void) */

void __thiscall dMetronome_c::_draw(dMetronome_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = (int)&this->vtbl + iVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 400));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x318));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x628));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x4a0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x7b0));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 7);
  iVar1 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0x938);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x15);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)&this->field_0xdd0);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)&this->field_0x4,d_metronome::_4271,d_metronome::_4271,
                  &pCtx->parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMetronome_c::_open(void) */

undefined4 __thiscall dMetronome_c::_open(dMetronome_c *this)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)&this->field_0xe3b == '\0') {
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(&this->field_0x938 + iVar2);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 0x15);
    *(undefined *)&this->field_0xe39 = DAT_803a2caf;
    *(undefined2 *)&this->field_0x1fe = 0;
    *(undefined2 *)&this->field_0x1c6 = 0;
    melodyInit(this,*(uchar *)&this->field_0xe39);
  }
  *(undefined *)&this->field_0xe3b = 1;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMetronome_c::_close(void) */

undefined4 __thiscall dMetronome_c::_close(dMetronome_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *(undefined *)&this->field_0xe3b = 0;
  if (*(char *)&this->field_0xe3b == '\0') {
    iVar1 = 0;
    do {
      iVar2 = (int)&this->vtbl + iVar3;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 400));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 0x318));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 0x628));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 0x4a0));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar2 + 0x7b0));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 7);
    iVar3 = 0;
    iVar1 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(&this->field_0x938 + iVar1));
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x38;
    } while (iVar3 < 0x15);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&this->field_0xdd0);
  }
  return 1;
}


/* __thiscall dMn_HIO_c::~dMn_HIO_c(void) */

void __thiscall dMn_HIO_c::_dMn_HIO_c(dMn_HIO_c *this)

{
  short in_r4;
  
  if (this != (dMn_HIO_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMn_HIO_c *)0x0) {
      *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_metronome {

void __sinit_d_metronome_cpp(void)

{
  ::dMn_HIO_c::dMn_HIO_c((dMn_HIO_c *)&g_mnHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

