#include <d_operate_wind.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <J2DGraph/J2DScreen.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <f_op_msg_mng.h>
#include <d_operate_wind.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_kankyo_wether.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <SComponent/c_math.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <d_meter.h>
#include <d_drawlist.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_Ow_mask_c.h>
#include <dOperate_wind_c.h>
#include <dDlst_Ow_main_c.h>
#include <dOw_c.h>
#include <dOw_HIO_c.h>


namespace d_operate_wind {
undefined g_owHIO;
undefined1 wind_flag$5173;
undefined1 init$5174;
}

/* __thiscall dOw_HIO_c::dOw_HIO_c(void) */

void __thiscall dOw_HIO_c::dOw_HIO_c(dOw_HIO_c *this)

{
  *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
  *(undefined1 **)this = &__vt;
  *(undefined2 *)(this + 8) = 0x1e;
  *(undefined2 *)(this + 10) = 0x5f;
  *(undefined2 *)(this + 0xc) = 0x9b;
  *(undefined2 *)(this + 0xe) = 0x10;
  this[0x18] = (dOw_HIO_c)0x64;
  *(undefined2 *)(this + 0x10) = 0x78;
  *(undefined2 *)(this + 0x12) = 0x32;
  *(float *)(this + 4) = d_operate_wind::_4010;
  *(undefined2 *)(this + 0x14) = 0x14;
  *(undefined2 *)(this + 0x16) = 0x28;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_Ow_main_c::draw(void) */

void __thiscall dDlst_Ow_main_c::draw(dDlst_Ow_main_c *this)

{
  J2DOrthoGraph *pCtx;
  dDlst_Ow_main_c *pdVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18 [2];
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < *(int *)(this + 0xc); iVar2 = iVar2 + 1) {
    local_18[0] = *(undefined4 *)(this + 8);
    pdVar1 = this + iVar3;
    J2DGraph::J2DDrawLine
              ((double)*(float *)(pdVar1 + 0x10),(double)*(float *)(pdVar1 + 0xd8),
               (double)*(float *)(pdVar1 + 0x1a0),(double)*(float *)(pdVar1 + 0x268),local_18,6);
    iVar3 = iVar3 + 4;
  }
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_operate_wind::_4027,d_operate_wind::_4027,
                  &pCtx->parent);
  return;
}


/* __thiscall dDlst_Ow_mask_c::draw(void) */

void __thiscall dDlst_Ow_mask_c::draw(dDlst_Ow_mask_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_operate_wind::_4027,d_operate_wind::_4027,
                  &pCtx->parent);
  return;
}


/* __thiscall dOperate_wind_c::dOw_angleRegular(float) */

dOperate_wind_c * __thiscall dOperate_wind_c::dOw_angleRegular(dOperate_wind_c *this,float param_1)

{
  if (param_1 < d_operate_wind::_4069) {
    return (dOperate_wind_c *)0x5a;
  }
  if (param_1 < d_operate_wind::_4070) {
    return (dOperate_wind_c *)0x87;
  }
  if (param_1 < d_operate_wind::_4071) {
    return (dOperate_wind_c *)0xb4;
  }
  if (param_1 < d_operate_wind::_4072) {
    return (dOperate_wind_c *)0xe1;
  }
  if (param_1 < d_operate_wind::_4073) {
    return (dOperate_wind_c *)0x10e;
  }
  if (param_1 < d_operate_wind::_4074) {
    return (dOperate_wind_c *)0x13b;
  }
  if (param_1 < d_operate_wind::_4075) {
    return (dOperate_wind_c *)0x0;
  }
  if (param_1 < d_operate_wind::_4076) {
    return (dOperate_wind_c *)0x2d;
  }
  if (param_1 < d_operate_wind::_4077) {
    return (dOperate_wind_c *)0x5a;
  }
  if (param_1 < d_operate_wind::_4078) {
    return (dOperate_wind_c *)0x87;
  }
  if (d_operate_wind::_4079 <= param_1) {
    return this;
  }
  return (dOperate_wind_c *)0xb4;
}


/* __thiscall dOperate_wind_c::dOw_stickControl(int,
                                                short) */

int __thiscall dOperate_wind_c::dOw_stickControl(dOperate_wind_c *this,int param_1,short param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = MSL_C.PPCEABI.bare.H::abs((int)param_2);
  if (param_1 == 0) {
    if (iVar1 < 0x7001) {
      uVar2 = SEXT24(param_2);
      if ((int)uVar2 < 0x5000) {
        if ((int)uVar2 < -0x4fff) {
          param_1 = 8;
        }
        else {
          if ((int)uVar2 < 0x3000) {
            if ((int)uVar2 < -0x2fff) {
              param_1 = 7;
            }
            else {
              if ((int)uVar2 < 0x1000) {
                param_1 = ((uint)(uVar2 < 0xfffff001) - ((int)uVar2 >> 0x1f)) + 4;
              }
              else {
                param_1 = 4;
              }
            }
          }
          else {
            param_1 = 3;
          }
        }
      }
      else {
        param_1 = 2;
      }
    }
    else {
      param_1 = 1;
    }
  }
  else {
    if (iVar1 < 0x7f81) {
      if ((param_2 < 0x5800) || (0x6800 < param_2)) {
        if ((param_2 < -0x57ff) && (-0x6801 < param_2)) {
          param_1 = 8;
        }
        else {
          if ((param_2 < 0x3f80) || (0x4080 < param_2)) {
            if ((param_2 < -0x3f7f) && (-0x4081 < param_2)) {
              param_1 = 7;
            }
            else {
              if ((param_2 < 0x1800) || (0x2800 < param_2)) {
                if ((param_2 < -0x17ff) && (-0x2801 < param_2)) {
                  param_1 = 6;
                }
                else {
                  if (iVar1 < 0x80) {
                    param_1 = 5;
                  }
                }
              }
              else {
                param_1 = 4;
              }
            }
          }
          else {
            param_1 = 3;
          }
        }
      }
      else {
        param_1 = 2;
      }
    }
    else {
      param_1 = 1;
    }
  }
  return param_1;
}


/* __thiscall dOperate_wind_c::screenSet(void) */

void __thiscall dOperate_wind_c::screenSet(dOperate_wind_c *this)

{
  int iVar1;
  
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc),*(J2DScreen **)(this + 4),0x77646e);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x44),*(J2DScreen **)(this + 4),0x776473);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x7c),*(J2DScreen **)(this + 4),0x776477);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xb4),*(J2DScreen **)(this + 4),0x776465);
  f_op_msg_mng::fopMsgM_setPaneData(this + 0x54c,*(undefined4 *)(this + 4),0x77696e);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xec),*(J2DScreen **)(this + 4),0x776962);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x124),*(J2DScreen **)(this + 4),0x77693231);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x15c),*(J2DScreen **)(this + 4),0x77693232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x194),*(J2DScreen **)(this + 4),0x77693262);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1cc),*(J2DScreen **)(this + 4),0x6e32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x204),*(J2DScreen **)(this + 4),0x7332);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x23c),*(J2DScreen **)(this + 4),0x7732);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x274),*(J2DScreen **)(this + 4),0x6532);
  *(undefined *)(*(int *)(this + 0x1cc) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x204) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x23c) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x274) + 0xaa) = 0;
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2ac),*(J2DScreen **)(this + 4),0x73747231);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2e4),*(J2DScreen **)(this + 4),0x73747232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x31c),*(J2DScreen **)(this + 4),0x73747233);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x354),*(J2DScreen **)(this + 4),0x73747234);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x38c),*(J2DScreen **)(this + 4),0x73747235);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x3c4),*(J2DScreen **)(this + 4),0x73747236);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x3fc),*(J2DScreen **)(this + 4),0x73747237);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x434),*(J2DScreen **)(this + 4),0x73747238);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x46c),*(J2DScreen **)(this + 4),0x63693034);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x4a4),*(J2DScreen **)(this + 4),0x63693035);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x4dc),*(J2DScreen **)(this + 4),0x63693036);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x514),*(J2DScreen **)(this + 4),0x63693037);
  f_op_msg_mng::fopMsgM_setPaneData(this + 0x554,*(undefined4 *)(this + 8),0x6d61736b);
  this[0x558] = (dOperate_wind_c)0x82;
  iVar1 = *(int *)(this + 0x54c);
  this[0x568] = *(dOperate_wind_c *)(iVar1 + 0x10c);
  this[0x569] = *(dOperate_wind_c *)(iVar1 + 0x10d);
  this[0x56a] = *(dOperate_wind_c *)(iVar1 + 0x10e);
  this[0x56b] = *(dOperate_wind_c *)(iVar1 + 0x10f);
  this[0x56c] = *(dOperate_wind_c *)(iVar1 + 0x110);
  this[0x56d] = *(dOperate_wind_c *)(iVar1 + 0x111);
  this[0x56e] = *(dOperate_wind_c *)(iVar1 + 0x112);
  this[0x56f] = *(dOperate_wind_c *)(iVar1 + 0x113);
  this[0x570] = *(dOperate_wind_c *)(iVar1 + 0x114);
  this[0x571] = *(dOperate_wind_c *)(iVar1 + 0x115);
  this[0x572] = *(dOperate_wind_c *)(iVar1 + 0x116);
  this[0x573] = *(dOperate_wind_c *)(iVar1 + 0x117);
  this[0x574] = *(dOperate_wind_c *)(iVar1 + 0x118);
  this[0x575] = *(dOperate_wind_c *)(iVar1 + 0x119);
  this[0x576] = *(dOperate_wind_c *)(iVar1 + 0x11a);
  this[0x577] = *(dOperate_wind_c *)(iVar1 + 0x11b);
  iVar1 = *(int *)(this + 0x124);
  this[0x578] = *(dOperate_wind_c *)(iVar1 + 0x10c);
  this[0x579] = *(dOperate_wind_c *)(iVar1 + 0x10d);
  this[0x57a] = *(dOperate_wind_c *)(iVar1 + 0x10e);
  this[0x57b] = *(dOperate_wind_c *)(iVar1 + 0x10f);
  this[0x57c] = *(dOperate_wind_c *)(iVar1 + 0x110);
  this[0x57d] = *(dOperate_wind_c *)(iVar1 + 0x111);
  this[0x57e] = *(dOperate_wind_c *)(iVar1 + 0x112);
  this[0x57f] = *(dOperate_wind_c *)(iVar1 + 0x113);
  this[0x580] = *(dOperate_wind_c *)(iVar1 + 0x114);
  this[0x581] = *(dOperate_wind_c *)(iVar1 + 0x115);
  this[0x582] = *(dOperate_wind_c *)(iVar1 + 0x116);
  this[0x583] = *(dOperate_wind_c *)(iVar1 + 0x117);
  this[0x584] = *(dOperate_wind_c *)(iVar1 + 0x118);
  this[0x585] = *(dOperate_wind_c *)(iVar1 + 0x119);
  this[0x586] = *(dOperate_wind_c *)(iVar1 + 0x11a);
  this[0x587] = *(dOperate_wind_c *)(iVar1 + 0x11b);
  iVar1 = *(int *)(this + 0x554);
  this[0x588] = *(dOperate_wind_c *)(iVar1 + 0x10c);
  this[0x589] = *(dOperate_wind_c *)(iVar1 + 0x10d);
  this[0x58a] = *(dOperate_wind_c *)(iVar1 + 0x10e);
  this[0x58b] = *(dOperate_wind_c *)(iVar1 + 0x10f);
  this[0x58c] = *(dOperate_wind_c *)(iVar1 + 0x110);
  this[0x58d] = *(dOperate_wind_c *)(iVar1 + 0x111);
  this[0x58e] = *(dOperate_wind_c *)(iVar1 + 0x112);
  this[0x58f] = *(dOperate_wind_c *)(iVar1 + 0x113);
  this[0x590] = *(dOperate_wind_c *)(iVar1 + 0x114);
  this[0x591] = *(dOperate_wind_c *)(iVar1 + 0x115);
  this[0x592] = *(dOperate_wind_c *)(iVar1 + 0x116);
  this[0x593] = *(dOperate_wind_c *)(iVar1 + 0x117);
  this[0x594] = *(dOperate_wind_c *)(iVar1 + 0x118);
  this[0x595] = *(dOperate_wind_c *)(iVar1 + 0x119);
  this[0x596] = *(dOperate_wind_c *)(iVar1 + 0x11a);
  this[0x597] = *(dOperate_wind_c *)(iVar1 + 0x11b);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8021ee7c) */
/* __thiscall dOperate_wind_c::alphaSet(float) */

void __thiscall dOperate_wind_c::alphaSet(dOperate_wind_c *this,float param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc),param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x44),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x7c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb4),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0x54c);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x124),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 2);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x194),(float)dVar4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1cc),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x2ac),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x46c),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0x554);
  this[0x8d4] = SUB41((int)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e6fec) -
                                           d_operate_wind::_4199) * dVar4),0);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall dOperate_wind_c::arrowColor1(void) */

void __thiscall dOperate_wind_c::arrowColor1(dOperate_wind_c *this)

{
  int iVar1;
  double dVar2;
  undefined local_78;
  undefined uStack119;
  undefined uStack118;
  undefined uStack117;
  undefined local_74;
  undefined uStack115;
  undefined uStack114;
  undefined uStack113;
  uint local_70;
  uint local_6c;
  double local_68;
  double local_58;
  double local_50;
  double local_40;
  double local_38;
  double local_28;
  double local_20;
  double local_10;
  
  *(short *)(this + 0x122) = *(short *)(this + 0x122) + 1;
  if (0x1e < *(short *)(this + 0x122)) {
    *(undefined2 *)(this + 0x122) = 0;
  }
  iVar1 = (int)*(short *)(this + 0x122);
  if (iVar1 < 10) {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1,0);
    local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56c]);
    local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56d]);
    local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56e]);
    local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56f]);
    local_70 = (int)((float)(local_20 - d_operate_wind::_4199) +
                    (float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000,
                                                                     (uint)(byte)this[0x56b] -
                                                                     (uint)(byte)this[0x56f] ^
                                                                     0x80000000) -
                                                   d_operate_wind::_4282))) & 0xffU |
               (uint)CONCAT21(CONCAT11((char)(int)((float)(local_68 - d_operate_wind::_4199) +
                                                  (float)(dVar2 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x568] - (uint)(byte)this[0x56c]
                                                  ^ 0x80000000) - d_operate_wind::_4282))),
                                       (char)(int)((float)(local_50 - d_operate_wind::_4199) +
                                                  (float)(dVar2 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x569] - (uint)(byte)this[0x56d]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))),
                              (char)(int)((float)(local_38 - d_operate_wind::_4199) +
                                         (float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000
                                                                                          ,(uint)(
                                                  byte)this[0x56a] - (uint)(byte)this[0x56e] ^
                                                  0x80000000) - d_operate_wind::_4282)))) << 8;
  }
  else {
    if (iVar1 < 0xf) {
      local_70 = *(uint *)(this + 0x568);
    }
    else {
      if (iVar1 < 0x19) {
        dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,0x19 - iVar1,0);
        local_10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56c]);
        local_28 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56d]);
        local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56e]);
        local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56f]);
        local_70 = (int)((float)(local_58 - d_operate_wind::_4199) +
                        (float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000,
                                                                         (uint)(byte)this[0x56b] -
                                                                         (uint)(byte)this[0x56f] ^
                                                                         0x80000000) -
                                                       d_operate_wind::_4282))) & 0xffU |
                   (uint)CONCAT21(CONCAT11((char)(int)((float)(local_10 - d_operate_wind::_4199) +
                                                      (float)(dVar2 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x568] -
                                                           (uint)(byte)this[0x56c] ^ 0x80000000) -
                                                  d_operate_wind::_4282))),
                                           (char)(int)((float)(local_28 - d_operate_wind::_4199) +
                                                      (float)(dVar2 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x569] -
                                                           (uint)(byte)this[0x56d] ^ 0x80000000) -
                                                  d_operate_wind::_4282)))),
                                  (char)(int)((float)(local_40 - d_operate_wind::_4199) +
                                             (float)(dVar2 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x56a] - (uint)(byte)this[0x56e]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))) << 8;
      }
      else {
        local_70 = *(uint *)(this + 0x56c);
      }
    }
  }
  iVar1 = (int)*(short *)(this + 0x122);
  if (iVar1 < 5) {
    local_6c = *(uint *)(this + 0x568);
  }
  else {
    if (iVar1 < 0xf) {
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,0xf - iVar1,0);
      local_10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56c]);
      local_28 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56d]);
      local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56e]);
      local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56f]);
      local_6c = (int)((float)(local_58 - d_operate_wind::_4199) +
                      (float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000,
                                                                       (uint)(byte)this[0x56b] -
                                                                       (uint)(byte)this[0x56f] ^
                                                                       0x80000000) -
                                                     d_operate_wind::_4282))) & 0xffU |
                 (uint)CONCAT21(CONCAT11((char)(int)((float)(local_10 - d_operate_wind::_4199) +
                                                    (float)(dVar2 * (double)(float)((double)CONCAT44
                                                  (0x43300000,
                                                   (uint)(byte)this[0x568] - (uint)(byte)this[0x56c]
                                                   ^ 0x80000000) - d_operate_wind::_4282))),
                                         (char)(int)((float)(local_28 - d_operate_wind::_4199) +
                                                    (float)(dVar2 * (double)(float)((double)CONCAT44
                                                  (0x43300000,
                                                   (uint)(byte)this[0x569] - (uint)(byte)this[0x56d]
                                                   ^ 0x80000000) - d_operate_wind::_4282)))),
                                (char)(int)((float)(local_40 - d_operate_wind::_4199) +
                                           (float)(dVar2 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x56a] - (uint)(byte)this[0x56e]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))) << 8;
    }
    else {
      if (iVar1 < 0x14) {
        local_6c = *(uint *)(this + 0x56c);
      }
      else {
        dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1 + -0x14,0);
        local_10 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56c]);
        local_28 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56d]);
        local_40 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56e]);
        local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x56f]);
        local_6c = (int)((float)(local_58 - d_operate_wind::_4199) +
                        (float)(dVar2 * (double)(float)((double)CONCAT44(0x43300000,
                                                                         (uint)(byte)this[0x56b] -
                                                                         (uint)(byte)this[0x56f] ^
                                                                         0x80000000) -
                                                       d_operate_wind::_4282))) & 0xffU |
                   (uint)CONCAT21(CONCAT11((char)(int)((float)(local_10 - d_operate_wind::_4199) +
                                                      (float)(dVar2 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x568] -
                                                           (uint)(byte)this[0x56c] ^ 0x80000000) -
                                                  d_operate_wind::_4282))),
                                           (char)(int)((float)(local_28 - d_operate_wind::_4199) +
                                                      (float)(dVar2 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x569] -
                                                           (uint)(byte)this[0x56d] ^ 0x80000000) -
                                                  d_operate_wind::_4282)))),
                                  (char)(int)((float)(local_40 - d_operate_wind::_4199) +
                                             (float)(dVar2 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x56a] - (uint)(byte)this[0x56e]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))) << 8;
      }
    }
  }
  iVar1 = *(int *)(this + 0x54c);
  local_74 = (undefined)(local_70 >> 0x18);
  *(undefined *)(iVar1 + 0x10c) = local_74;
  uStack115 = (undefined)(local_70 >> 0x10);
  *(undefined *)(iVar1 + 0x10d) = uStack115;
  uStack114 = (undefined)(local_70 >> 8);
  *(undefined *)(iVar1 + 0x10e) = uStack114;
  uStack113 = (undefined)local_70;
  *(undefined *)(iVar1 + 0x10f) = uStack113;
  local_78 = (undefined)(local_6c >> 0x18);
  *(undefined *)(iVar1 + 0x110) = local_78;
  uStack119 = (undefined)(local_6c >> 0x10);
  *(undefined *)(iVar1 + 0x111) = uStack119;
  uStack118 = (undefined)(local_6c >> 8);
  *(undefined *)(iVar1 + 0x112) = uStack118;
  uStack117 = (undefined)local_6c;
  *(undefined *)(iVar1 + 0x113) = uStack117;
  *(undefined *)(iVar1 + 0x114) = local_74;
  *(undefined *)(iVar1 + 0x115) = uStack115;
  *(undefined *)(iVar1 + 0x116) = uStack114;
  *(undefined *)(iVar1 + 0x117) = uStack113;
  *(undefined *)(iVar1 + 0x118) = local_78;
  *(undefined *)(iVar1 + 0x119) = uStack119;
  *(undefined *)(iVar1 + 0x11a) = uStack118;
  *(undefined *)(iVar1 + 0x11b) = uStack117;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dOperate_wind_c::arrowColor2(void) */

void __thiscall dOperate_wind_c::arrowColor2(dOperate_wind_c *this)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  undefined local_70;
  undefined uStack111;
  undefined uStack110;
  undefined local_6c;
  undefined uStack107;
  undefined uStack106;
  int local_68;
  undefined3 local_64;
  double local_60;
  double local_50;
  double local_48;
  double local_38;
  double local_30;
  double local_20;
  
  sVar1 = DAT_803e6fea;
  iVar5 = (int)DAT_803e6fe8;
  iVar4 = (int)DAT_803e6fea;
  *(short *)(this + 0x15a) = *(short *)(this + 0x15a) + 1;
  iVar3 = iVar5 + 0x14;
  if ((short)(sVar1 + (short)iVar3) < *(short *)(this + 0x15a)) {
    *(undefined2 *)(this + 0x15a) = 0;
  }
  iVar2 = (int)*(short *)(this + 0x15a);
  if (iVar2 < 10) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar2,0);
    local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x578]);
    local_48 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x579]);
    local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x57a]);
    local_68 = (uint)CONCAT21(CONCAT11((char)(int)((float)(local_60 - d_operate_wind::_4199) +
                                                  (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57c] - (uint)(byte)this[0x578]
                                                  ^ 0x80000000) - d_operate_wind::_4282))),
                                       (char)(int)((float)(local_48 - d_operate_wind::_4199) +
                                                  (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57d] - (uint)(byte)this[0x579]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))),
                              (char)(int)((float)(local_30 - d_operate_wind::_4199) +
                                         (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000
                                                                                          ,(uint)(
                                                  byte)this[0x57e] - (uint)(byte)this[0x57a] ^
                                                  0x80000000) - d_operate_wind::_4282)))) << 8;
  }
  else {
    if (iVar2 < iVar5 + 10) {
      local_68 = *(int *)(this + 0x57c);
    }
    else {
      if (iVar2 < iVar3) {
        dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar3 - iVar2,0);
        local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x578]);
        local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x579]);
        local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x57a]);
        local_68 = (uint)CONCAT21(CONCAT11((char)(int)((float)(local_20 - d_operate_wind::_4199) +
                                                      (float)(dVar6 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x57c] -
                                                           (uint)(byte)this[0x578] ^ 0x80000000) -
                                                  d_operate_wind::_4282))),
                                           (char)(int)((float)(local_38 - d_operate_wind::_4199) +
                                                      (float)(dVar6 * (double)(float)((double)
                                                  CONCAT44(0x43300000,
                                                           (uint)(byte)this[0x57d] -
                                                           (uint)(byte)this[0x579] ^ 0x80000000) -
                                                  d_operate_wind::_4282)))),
                                  (char)(int)((float)(local_50 - d_operate_wind::_4199) +
                                             (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57e] - (uint)(byte)this[0x57a]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))) << 8;
      }
      else {
        local_68 = *(int *)(this + 0x578);
      }
    }
  }
  iVar3 = (int)*(short *)(this + 0x15a);
  if (iVar3 < iVar5) {
    local_64 = *(undefined3 *)(this + 0x57c);
  }
  else {
    iVar5 = iVar5 + 10;
    if (iVar3 < iVar5) {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar5 - iVar3,0);
      local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x578]);
      local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x579]);
      local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x57a]);
      local_64 = CONCAT21(CONCAT11((char)(int)((float)(local_20 - d_operate_wind::_4199) +
                                              (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57c] - (uint)(byte)this[0x578]
                                                  ^ 0x80000000) - d_operate_wind::_4282))),
                                   (char)(int)((float)(local_38 - d_operate_wind::_4199) +
                                              (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57d] - (uint)(byte)this[0x579]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))),
                          (char)(int)((float)(local_50 - d_operate_wind::_4199) +
                                     (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                      (uint)(byte)
                                                  this[0x57e] - (uint)(byte)this[0x57a] ^ 0x80000000
                                                  ) - d_operate_wind::_4282))));
    }
    else {
      if (iVar3 < iVar4 + iVar5) {
        local_64 = *(undefined3 *)(this + 0x578);
      }
      else {
        dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar3 - (iVar4 + iVar5),0);
        local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x578]);
        local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x579]);
        local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x57a]);
        local_64 = CONCAT21(CONCAT11((char)(int)((float)(local_20 - d_operate_wind::_4199) +
                                                (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57c] - (uint)(byte)this[0x578]
                                                  ^ 0x80000000) - d_operate_wind::_4282))),
                                     (char)(int)((float)(local_38 - d_operate_wind::_4199) +
                                                (float)(dVar6 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)(byte)this[0x57d] - (uint)(byte)this[0x579]
                                                  ^ 0x80000000) - d_operate_wind::_4282)))),
                            (char)(int)((float)(local_50 - d_operate_wind::_4199) +
                                       (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                        (uint)(byte)
                                                  this[0x57e] - (uint)(byte)this[0x57a] ^ 0x80000000
                                                  ) - d_operate_wind::_4282))));
      }
    }
  }
  iVar5 = *(int *)(this + 0x124);
  local_6c = (undefined)((uint3)local_64 >> 0x10);
  *(undefined *)(iVar5 + 0x10c) = local_6c;
  uStack107 = (undefined)((uint3)local_64 >> 8);
  *(undefined *)(iVar5 + 0x10d) = uStack107;
  uStack106 = (undefined)local_64;
  *(undefined *)(iVar5 + 0x10e) = uStack106;
  *(undefined *)(iVar5 + 0x10f) = 0x96;
  local_70 = (undefined)((uint)local_68 >> 0x18);
  *(undefined *)(iVar5 + 0x110) = local_70;
  uStack111 = (undefined)((uint)local_68 >> 0x10);
  *(undefined *)(iVar5 + 0x111) = uStack111;
  uStack110 = (undefined)((uint)local_68 >> 8);
  *(undefined *)(iVar5 + 0x112) = uStack110;
  *(undefined *)(iVar5 + 0x113) = 0xff;
  *(undefined *)(iVar5 + 0x114) = local_6c;
  *(undefined *)(iVar5 + 0x115) = uStack107;
  *(undefined *)(iVar5 + 0x116) = uStack106;
  *(undefined *)(iVar5 + 0x117) = 0x96;
  *(undefined *)(iVar5 + 0x118) = local_70;
  *(undefined *)(iVar5 + 0x119) = uStack111;
  *(undefined *)(iVar5 + 0x11a) = uStack110;
  *(undefined *)(iVar5 + 0x11b) = 0xff;
  iVar5 = *(int *)(this + 0x15c);
  *(undefined *)(iVar5 + 0x10c) = local_6c;
  *(undefined *)(iVar5 + 0x10d) = uStack107;
  *(undefined *)(iVar5 + 0x10e) = uStack106;
  *(undefined *)(iVar5 + 0x10f) = 0x96;
  *(undefined *)(iVar5 + 0x110) = local_70;
  *(undefined *)(iVar5 + 0x111) = uStack111;
  *(undefined *)(iVar5 + 0x112) = uStack110;
  *(undefined *)(iVar5 + 0x113) = 0xff;
  *(undefined *)(iVar5 + 0x114) = local_6c;
  *(undefined *)(iVar5 + 0x115) = uStack107;
  *(undefined *)(iVar5 + 0x116) = uStack106;
  *(undefined *)(iVar5 + 0x117) = 0x96;
  *(undefined *)(iVar5 + 0x118) = local_70;
  *(undefined *)(iVar5 + 0x119) = uStack111;
  *(undefined *)(iVar5 + 0x11a) = uStack110;
  *(undefined *)(iVar5 + 0x11b) = 0xff;
  return;
}


/* __thiscall dOperate_wind_c::maskColor(void) */

void __thiscall dOperate_wind_c::maskColor(dOperate_wind_c *this)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar6;
  undefined uVar7;
  uint uVar5;
  undefined uVar8;
  undefined uVar9;
  undefined uVar10;
  undefined uVar11;
  uint uVar12;
  undefined uVar14;
  int iVar13;
  uint uVar15;
  undefined uVar16;
  uint uVar17;
  undefined uVar19;
  uint uVar18;
  uint uVar20;
  uint uVar21;
  undefined uVar22;
  uint uVar23;
  undefined uVar24;
  uint uVar25;
  undefined uVar26;
  int iVar27;
  double dVar28;
  
  iVar27 = (int)DAT_803e6fe4;
  *(short *)(this + 0x4a2) = *(short *)(this + 0x4a2) + 1;
  if ((short)(iVar27 << 2) <= *(short *)(this + 0x4a2)) {
    *(undefined2 *)(this + 0x4a2) = 0;
  }
  dVar28 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                             (iVar27,(int)*(short *)(this + 0x4a2) -
                                     ((int)*(short *)(this + 0x4a2) / iVar27) * iVar27,2);
  uVar20 = (uint)(byte)this[0x588];
  uVar17 = (uint)(byte)this[0x590];
  uVar1 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar20) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar17 - uVar20 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar21 = (uint)(byte)this[0x589];
  uVar15 = (uint)(byte)this[0x591];
  uVar6 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar21) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar15 - uVar21 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar23 = (uint)(byte)this[0x58a];
  uVar12 = (uint)(byte)this[0x592];
  uVar7 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar23) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar12 - uVar23 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar25 = (uint)(byte)this[0x58b];
  uVar5 = (uint)(byte)this[0x593];
  uVar19 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar25) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar5 - uVar25 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar18 = (uint)(byte)this[0x58c];
  uVar2 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar18) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar20 - uVar18 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar20 = (uint)(byte)this[0x58d];
  uVar22 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar20) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar21 - uVar20 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar21 = (uint)(byte)this[0x58e];
  uVar24 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar21) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar23 - uVar21 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar23 = (uint)(byte)this[0x58f];
  uVar26 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar23) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar25 - uVar23 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar25 = (uint)(byte)this[0x594];
  uVar3 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar17) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar25 - uVar17 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar17 = (uint)(byte)this[0x595];
  uVar16 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar15) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar17 - uVar15 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar15 = (uint)(byte)this[0x596];
  uVar14 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar12) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar15 - uVar12 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar12 = (uint)(byte)this[0x597];
  uVar8 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar5) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar12 - uVar5 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar4 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar25) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar18 - uVar25 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar9 = (undefined)
          (int)((float)((double)CONCAT44(0x43300000,uVar17) - d_operate_wind::_4199) +
               (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                 uVar20 - uVar17 ^ 0x80000000) -
                                               d_operate_wind::_4282)));
  uVar10 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar15) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar21 - uVar15 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  uVar11 = (undefined)
           (int)((float)((double)CONCAT44(0x43300000,uVar12) - d_operate_wind::_4199) +
                (float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  uVar23 - uVar12 ^ 0x80000000) -
                                                d_operate_wind::_4282)));
  iVar13 = (int)*(short *)(this + 0x4a2);
  if (iVar13 < iVar27) {
    iVar27 = *(int *)(this + 0x554);
    *(undefined *)(iVar27 + 0x10c) = uVar1;
    *(undefined *)(iVar27 + 0x10d) = uVar6;
    *(undefined *)(iVar27 + 0x10e) = uVar7;
    *(undefined *)(iVar27 + 0x10f) = uVar19;
    *(undefined *)(iVar27 + 0x110) = uVar2;
    *(undefined *)(iVar27 + 0x111) = uVar22;
    *(undefined *)(iVar27 + 0x112) = uVar24;
    *(undefined *)(iVar27 + 0x113) = uVar26;
    *(undefined *)(iVar27 + 0x114) = uVar3;
    *(undefined *)(iVar27 + 0x115) = uVar16;
    *(undefined *)(iVar27 + 0x116) = uVar14;
    *(undefined *)(iVar27 + 0x117) = uVar8;
    *(undefined *)(iVar27 + 0x118) = uVar4;
    *(undefined *)(iVar27 + 0x119) = uVar9;
    *(undefined *)(iVar27 + 0x11a) = uVar10;
    *(undefined *)(iVar27 + 0x11b) = uVar11;
  }
  else {
    if (iVar13 < iVar27 << 1) {
      iVar27 = *(int *)(this + 0x554);
      *(undefined *)(iVar27 + 0x10c) = uVar3;
      *(undefined *)(iVar27 + 0x10d) = uVar16;
      *(undefined *)(iVar27 + 0x10e) = uVar14;
      *(undefined *)(iVar27 + 0x10f) = uVar8;
      *(undefined *)(iVar27 + 0x110) = uVar1;
      *(undefined *)(iVar27 + 0x111) = uVar6;
      *(undefined *)(iVar27 + 0x112) = uVar7;
      *(undefined *)(iVar27 + 0x113) = uVar19;
      *(undefined *)(iVar27 + 0x114) = uVar4;
      *(undefined *)(iVar27 + 0x115) = uVar9;
      *(undefined *)(iVar27 + 0x116) = uVar10;
      *(undefined *)(iVar27 + 0x117) = uVar11;
      *(undefined *)(iVar27 + 0x118) = uVar2;
      *(undefined *)(iVar27 + 0x119) = uVar22;
      *(undefined *)(iVar27 + 0x11a) = uVar24;
      *(undefined *)(iVar27 + 0x11b) = uVar26;
    }
    else {
      if (iVar13 < iVar27 * 3) {
        iVar27 = *(int *)(this + 0x554);
        *(undefined *)(iVar27 + 0x10c) = uVar4;
        *(undefined *)(iVar27 + 0x10d) = uVar9;
        *(undefined *)(iVar27 + 0x10e) = uVar10;
        *(undefined *)(iVar27 + 0x10f) = uVar11;
        *(undefined *)(iVar27 + 0x110) = uVar3;
        *(undefined *)(iVar27 + 0x111) = uVar16;
        *(undefined *)(iVar27 + 0x112) = uVar14;
        *(undefined *)(iVar27 + 0x113) = uVar8;
        *(undefined *)(iVar27 + 0x114) = uVar2;
        *(undefined *)(iVar27 + 0x115) = uVar22;
        *(undefined *)(iVar27 + 0x116) = uVar24;
        *(undefined *)(iVar27 + 0x117) = uVar26;
        *(undefined *)(iVar27 + 0x118) = uVar1;
        *(undefined *)(iVar27 + 0x119) = uVar6;
        *(undefined *)(iVar27 + 0x11a) = uVar7;
        *(undefined *)(iVar27 + 0x11b) = uVar19;
      }
      else {
        iVar27 = *(int *)(this + 0x554);
        *(undefined *)(iVar27 + 0x10c) = uVar2;
        *(undefined *)(iVar27 + 0x10d) = uVar22;
        *(undefined *)(iVar27 + 0x10e) = uVar24;
        *(undefined *)(iVar27 + 0x10f) = uVar26;
        *(undefined *)(iVar27 + 0x110) = uVar4;
        *(undefined *)(iVar27 + 0x111) = uVar9;
        *(undefined *)(iVar27 + 0x112) = uVar10;
        *(undefined *)(iVar27 + 0x113) = uVar11;
        *(undefined *)(iVar27 + 0x114) = uVar1;
        *(undefined *)(iVar27 + 0x115) = uVar6;
        *(undefined *)(iVar27 + 0x116) = uVar7;
        *(undefined *)(iVar27 + 0x117) = uVar19;
        *(undefined *)(iVar27 + 0x118) = uVar3;
        *(undefined *)(iVar27 + 0x119) = uVar16;
        *(undefined *)(iVar27 + 0x11a) = uVar14;
        *(undefined *)(iVar27 + 0x11b) = uVar8;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802207a8) */
/* __thiscall dOperate_wind_c::arrowDirection(void) */

void __thiscall dOperate_wind_c::arrowDirection(dOperate_wind_c *this)

{
  float fVar1;
  short sVar2;
  short sVar4;
  int iVar3;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f31;
  double local_38;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)(**(code **)(**(int **)(this + 0x55c) + 8))();
  fVar1 = *(float *)(*(int *)(this + 0xec) + 0xa4);
  dVar7 = (double)(**(code **)(**(int **)(this + 0x55c) + 8))();
  if ((dVar7 < (double)d_operate_wind::_4764) ||
     (ABS(dVar6) - ABS((double)*(float *)(this + 0x8b8)) < d_operate_wind::_4765)) {
    dVar7 = (double)(**(code **)(**(int **)(this + 0x55c) + 8))();
    if ((dVar7 < (double)d_operate_wind::_4764) &&
       (ABS(dVar6) - ABS((double)*(float *)(this + 0x8b8)) < d_operate_wind::_4765)) {
      *(undefined4 *)(this + 0x8d0) = 0;
    }
  }
  else {
    sVar4 = (**(code **)(**(int **)(this + 0x55c) + 0xc))();
    iVar3 = dOw_stickControl(this,*(int *)(this + 0x8d0),sVar4);
    if ((*(short *)(this + 0x8ca) == 0) && (iVar3 != *(int *)(this + 0x8d0))) {
      *(int *)(this + 0x8d0) = iVar3;
      switch(iVar3) {
      case 1:
        if (*(short *)(this + 0x8cc) != 0x10e) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0x10e;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 2:
        if (*(short *)(this + 0x8cc) != 0xe1) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0xe1;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 3:
        if (*(short *)(this + 0x8cc) != 0xb4) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0xb4;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 4:
        if (*(short *)(this + 0x8cc) != 0x87) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0x87;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 5:
        if (*(short *)(this + 0x8cc) != 0x5a) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0x5a;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 6:
        if (*(short *)(this + 0x8cc) != 0x2d) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0x2d;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 7:
        if (*(short *)(this + 0x8cc) != 0) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
        break;
      case 8:
        if (*(short *)(this + 0x8cc) != 0x13b) {
          *(undefined2 *)(this + 0x8ca) = 7;
          *(undefined2 *)(this + 0x8cc) = 0x13b;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x874,(cXyz *)0x0,0,0,d_operate_wind::_4766,
                     d_operate_wind::_4766,d_operate_wind::_4767,d_operate_wind::_4767,0);
        }
      }
    }
  }
  *(float *)(this + 0x8b8) = (float)dVar6;
  if (0 < *(short *)(this + 0x8ca)) {
    *(short *)(this + 0x8ca) = *(short *)(this + 0x8ca) + -1;
  }
  sVar4 = (short)(int)fVar1;
  sVar2 = *(short *)(this + 0x8cc) - sVar4;
  if (sVar2 < 0xb5) {
    if (sVar2 < -0xb4) {
      sVar2 = sVar2 + 0x168;
    }
  }
  else {
    sVar2 = sVar2 + -0x168;
  }
  iVar3 = MSL_C.PPCEABI.bare.H::abs((int)sVar2);
  if (iVar3 < 0x10) {
    *(undefined2 *)(this + 0x8ca) = 0;
  }
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(7,(int)*(short *)(this + 0x8ca),0);
  local_38 = (double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000);
  arrowRotate(this,(fopMsgM_pane_class *)(this + 0xec),
              sVar4 + (short)(int)((float)(local_38 - d_operate_wind::_4282) *
                                  (float)((double)d_operate_wind::_4766 - dVar6)));
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dOperate_wind_c::windSet(void) */

void __thiscall dOperate_wind_c::windSet(dOperate_wind_c *this)

{
  short sVar1;
  
  sVar1 = *(short *)(this + 0x8cc);
  if (sVar1 == 0xb4) {
    d_kankyo_wether::dKyw_tact_wind_set(0,0);
  }
  else {
    if (sVar1 < 0xb4) {
      if (sVar1 == 0x5a) {
        d_kankyo_wether::dKyw_tact_wind_set(0,0x4000);
      }
      else {
        if (sVar1 < 0x5a) {
          if (sVar1 == 0x2d) {
            d_kankyo_wether::dKyw_tact_wind_set(0,0x6000);
          }
          else {
            if ((sVar1 < 0x2d) && (sVar1 == 0)) {
              d_kankyo_wether::dKyw_tact_wind_set(0,-0x8000);
            }
          }
        }
        else {
          if (sVar1 == 0x87) {
            d_kankyo_wether::dKyw_tact_wind_set(0,0x2000);
          }
        }
      }
    }
    else {
      if (sVar1 == 0x10e) {
        d_kankyo_wether::dKyw_tact_wind_set(0,-0x4000);
      }
      else {
        if (sVar1 < 0x10e) {
          if (sVar1 == 0xe1) {
            d_kankyo_wether::dKyw_tact_wind_set(0,-0x2000);
          }
        }
        else {
          if (sVar1 == 0x13b) {
            d_kankyo_wether::dKyw_tact_wind_set(0,-0x6000);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8022096c) */
/* __thiscall dOperate_wind_c::ringScale(float) */

void __thiscall dOperate_wind_c::ringScale(dOperate_wind_c *this,float param_1)

{
  dOperate_wind_c *pdVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar5 = (double)param_1;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = 0;
  iVar3 = 0;
  do {
    if (iVar2 == 0) {
      pdVar1 = this + iVar3;
      *(float *)(pdVar1 + 0x488) =
           *(float *)(this + 0x8c0) +
           (float)(dVar5 * (double)(*(float *)(pdVar1 + 0x480) - *(float *)(this + 0x8c0)));
      *(float *)(pdVar1 + 0x48c) =
           *(float *)(this + 0x8c4) +
           (float)(dVar5 * (double)(*(float *)(pdVar1 + 0x484) - *(float *)(this + 0x8c4)));
    }
    else {
      pdVar1 = this + iVar3;
      *(float *)(pdVar1 + 0x488) = (float)((double)*(float *)(pdVar1 + 0x480) * dVar5);
      *(float *)(pdVar1 + 0x48c) = (float)((double)*(float *)(pdVar1 + 0x484) * dVar5);
    }
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + iVar3 + 0x46c),(float)dVar5);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 4);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80220a3c) */
/* WARNING: Removing unreachable block (ram,0x80220a44) */
/* __thiscall dOperate_wind_c::directionTrans(float) */

void __thiscall dOperate_wind_c::directionTrans(dOperate_wind_c *this,float param_1)

{
  undefined4 uVar1;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double y_00;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  y = (double)(d_operate_wind::_4805 * param_1);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc),(double)d_operate_wind::_4027,y);
  y_00 = -y;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x44),(double)d_operate_wind::_4027,y_00);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x7c),y,(double)d_operate_wind::_4027);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xb4),y_00,(double)d_operate_wind::_4027);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x1cc),(double)d_operate_wind::_4027,y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x204),(double)d_operate_wind::_4027,y_00);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x23c),y,(double)d_operate_wind::_4027);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x274),y_00,(double)d_operate_wind::_4027);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80220cb0) */
/* WARNING: Removing unreachable block (ram,0x80220ca0) */
/* WARNING: Removing unreachable block (ram,0x80220c90) */
/* WARNING: Removing unreachable block (ram,0x80220c80) */
/* WARNING: Removing unreachable block (ram,0x80220c70) */
/* WARNING: Removing unreachable block (ram,0x80220c78) */
/* WARNING: Removing unreachable block (ram,0x80220c88) */
/* WARNING: Removing unreachable block (ram,0x80220c98) */
/* WARNING: Removing unreachable block (ram,0x80220ca8) */
/* WARNING: Removing unreachable block (ram,0x80220cb8) */
/* __thiscall dOperate_wind_c::lineInit(float) */

void __thiscall dOperate_wind_c::lineInit(dOperate_wind_c *this,float param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  dOperate_wind_c *pdVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f22;
  undefined8 in_f23;
  double dVar9;
  undefined8 in_f24;
  double dVar10;
  undefined8 in_f25;
  double dVar11;
  undefined8 in_f26;
  double dVar12;
  double dVar13;
  undefined8 in_f27;
  double dVar14;
  undefined8 in_f28;
  double dVar15;
  undefined8 in_f29;
  double dVar16;
  undefined8 in_f30;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
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
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  dVar16 = -(double)((d_operate_wind::_4836 - d_s_play::g_regHIO.mChild[6].mFloats[5]) * param_1);
  dVar15 = (double)((*(float *)(this + 0x2b4) - *(float *)(this + 0x1ac)) * param_1);
  dVar11 = (double)(d_operate_wind::_4837 /
                   (float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x8ce) ^ 0x80000000) -
                          d_operate_wind::_4282));
  iVar6 = 0;
  dVar17 = (double)d_operate_wind::_4839;
  dVar18 = (double)d_operate_wind::_4841;
  dVar9 = (double)d_operate_wind::_4843;
  fVar1 = d_operate_wind::_4838;
  for (uVar4 = 0; dVar10 = (double)fVar1, (int)uVar4 < (int)*(short *)(this + 0x8ce);
      uVar4 = uVar4 + 1) {
    uVar2 = uVar4 >> 0x1f;
    uVar3 = uVar4 & 1 ^ uVar2;
    if (uVar3 == uVar2) {
      dVar12 = (double)(d_operate_wind::_4839 *
                       ((float)((double)d_operate_wind::_4842 + dVar10) / d_operate_wind::_4841));
      dVar8 = MSL_C.PPCEABI.bare.H::sin(dVar12);
      dVar14 = (double)(*(float *)(this + 0x8c0) + (float)(dVar15 * (double)(float)dVar8));
      dVar8 = MSL_C.PPCEABI.bare.H::cos(dVar12);
      fVar1 = *(float *)(this + 0x8c4) + (float)(dVar15 * (double)(float)dVar8);
    }
    else {
      dVar12 = (double)(d_operate_wind::_4839 *
                       ((float)((double)d_operate_wind::_4840 + dVar10) / d_operate_wind::_4841));
      dVar8 = MSL_C.PPCEABI.bare.H::sin(dVar12);
      dVar14 = (double)(*(float *)(this + 0x8c0) + (float)(dVar15 * (double)(float)dVar8));
      dVar8 = MSL_C.PPCEABI.bare.H::cos(dVar12);
      fVar1 = *(float *)(this + 0x8c4) + (float)(dVar15 * (double)(float)dVar8);
    }
    dVar13 = (double)fVar1;
    dVar12 = (double)(float)(dVar17 * (double)(float)(dVar10 / dVar18));
    dVar8 = MSL_C.PPCEABI.bare.H::sin(dVar12);
    pdVar5 = this + iVar6;
    *(float *)(pdVar5 + 0x598) = (float)(dVar14 + (double)(float)(dVar16 * (double)(float)dVar8));
    dVar8 = MSL_C.PPCEABI.bare.H::cos(dVar12);
    *(float *)(pdVar5 + 0x660) = (float)(dVar13 + (double)(float)(dVar16 * (double)(float)dVar8));
    *(float *)(pdVar5 + 0x728) = (float)(dVar9 * dVar14) - *(float *)(pdVar5 + 0x598);
    *(float *)(pdVar5 + 0x7f0) = (float)(dVar9 * dVar13) - *(float *)(pdVar5 + 0x660);
    if (uVar3 == uVar2) {
      *(float *)(pdVar5 + 0x728) = (float)dVar14;
      *(float *)(pdVar5 + 0x7f0) = (float)dVar13;
    }
    else {
      *(float *)(pdVar5 + 0x598) = (float)dVar14;
      *(float *)(pdVar5 + 0x660) = (float)dVar13;
    }
    fVar1 = (float)(dVar10 + dVar11);
    iVar6 = iVar6 + 4;
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
  __psq_l0(auStack120,uVar7);
  __psq_l1(auStack120,uVar7);
  __psq_l0(auStack136,uVar7);
  __psq_l1(auStack136,uVar7);
  __psq_l0(auStack152,uVar7);
  __psq_l1(auStack152,uVar7);
  return;
}


/* __thiscall dOperate_wind_c::lineDraw(void) */

void __thiscall dOperate_wind_c::lineDraw(dOperate_wind_c *this)

{
  dOperate_wind_c dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  dOperate_wind_c *pdVar6;
  int iVar7;
  int iVar8;
  
  dVar1 = this[0x8d4];
  iVar5 = *(int *)(this + 0x560);
  *(undefined *)(iVar5 + 8) = 0xff;
  *(undefined *)(iVar5 + 9) = 0xff;
  *(undefined *)(iVar5 + 10) = 0xff;
  *(dOperate_wind_c *)(iVar5 + 0xb) = dVar1;
  *(int *)(*(int *)(this + 0x560) + 0xc) = (int)*(short *)(this + 0x8ce);
  iVar5 = 0;
  for (iVar8 = 0; iVar8 < *(short *)(this + 0x8ce); iVar8 = iVar8 + 1) {
    pdVar6 = this + iVar5;
    uVar2 = *(undefined4 *)(pdVar6 + 0x7f0);
    uVar3 = *(undefined4 *)(pdVar6 + 0x728);
    uVar4 = *(undefined4 *)(pdVar6 + 0x660);
    iVar7 = *(int *)(this + 0x560) + iVar5;
    *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(pdVar6 + 0x598);
    *(undefined4 *)(iVar7 + 0xd8) = uVar4;
    *(undefined4 *)(iVar7 + 0x1a0) = uVar3;
    *(undefined4 *)(iVar7 + 0x268) = uVar2;
    iVar5 = iVar5 + 4;
  }
  return;
}


/* __thiscall dOperate_wind_c::arrowRotate(fopMsgM_pane_class *,
                                           short) */

void __thiscall
dOperate_wind_c::arrowRotate(dOperate_wind_c *this,fopMsgM_pane_class *param_1,short param_2)

{
  float fVar1;
  J2DScreen *pJVar2;
  
  if (param_2 < 0) {
    param_2 = param_2 + 0x168;
  }
  if (0x168 < param_2) {
    param_2 = param_2 + -0x168;
  }
  fVar1 = (param_1->mSizeOrig).y * d_operate_wind::_4888;
  pJVar2 = param_1->mpPane;
  (pJVar2->parent).mBasePosition.x = (param_1->mSizeOrig).x * d_operate_wind::_4888;
  (pJVar2->parent).mBasePosition.y = fVar1;
  (pJVar2->parent).mRotationAxis = 'z';
  (pJVar2->parent).mRotation =
       (float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - d_operate_wind::_4282);
  (*(code *)((pJVar2->parent).vtbl)->calcMtx)();
  return;
}


/* __thiscall dOperate_wind_c::initialize(void) */

void __thiscall dOperate_wind_c::initialize(dOperate_wind_c *this)

{
  cXyz *pcVar1;
  undefined2 uVar2;
  int iVar3;
  double dVar4;
  
  *(undefined2 *)(this + 0x8c8) = 0;
  *(undefined2 *)(this + 0x8ca) = 0;
  *(undefined2 *)(this + 0x8ce) = DAT_803e6fe2;
  this[0x8d4] = (dOperate_wind_c)0x0;
  *(undefined4 *)(this + 0x8d0) = 0;
  *(undefined2 *)(this + 0x122) = 0;
  *(undefined2 *)(this + 0x4a2) = 0;
  *(undefined2 *)(this + 0x15a) = 0x1e;
  *(undefined2 *)(this + 0x192) = 0x23;
  iVar3 = *(int *)(this + 0x124);
  *(undefined *)(iVar3 + 0x10c) = 0xff;
  *(undefined *)(iVar3 + 0x10d) = 0xff;
  *(undefined *)(iVar3 + 0x10e) = 0xff;
  *(undefined *)(iVar3 + 0x10f) = 0x96;
  *(undefined *)(iVar3 + 0x110) = 0;
  *(undefined *)(iVar3 + 0x111) = 0xff;
  *(undefined *)(iVar3 + 0x112) = 0xff;
  *(undefined *)(iVar3 + 0x113) = 0xff;
  *(undefined *)(iVar3 + 0x114) = 0xff;
  *(undefined *)(iVar3 + 0x115) = 0xff;
  *(undefined *)(iVar3 + 0x116) = 0xff;
  *(undefined *)(iVar3 + 0x117) = 0x96;
  *(undefined *)(iVar3 + 0x118) = 0;
  *(undefined *)(iVar3 + 0x119) = 0xff;
  *(undefined *)(iVar3 + 0x11a) = 0xff;
  *(undefined *)(iVar3 + 0x11b) = 0xff;
  iVar3 = *(int *)(this + 0x15c);
  *(undefined *)(iVar3 + 0x10c) = 0xff;
  *(undefined *)(iVar3 + 0x10d) = 0xff;
  *(undefined *)(iVar3 + 0x10e) = 0xff;
  *(undefined *)(iVar3 + 0x10f) = 0x96;
  *(undefined *)(iVar3 + 0x110) = 0;
  *(undefined *)(iVar3 + 0x111) = 0xff;
  *(undefined *)(iVar3 + 0x112) = 0xff;
  *(undefined *)(iVar3 + 0x113) = 0xff;
  *(undefined *)(iVar3 + 0x114) = 0xff;
  *(undefined *)(iVar3 + 0x115) = 0xff;
  *(undefined *)(iVar3 + 0x116) = 0xff;
  *(undefined *)(iVar3 + 0x117) = 0x96;
  *(undefined *)(iVar3 + 0x118) = 0;
  *(undefined *)(iVar3 + 0x119) = 0xff;
  *(undefined *)(iVar3 + 0x11a) = 0xff;
  *(undefined *)(iVar3 + 0x11b) = 0xff;
  *(float *)(this + 0x8c0) = *(float *)(this + 0x470) + *(float *)(this + 0x490);
  *(undefined4 *)(this + 0x8c4) = *(undefined4 *)(this + 0x474);
  pcVar1 = d_kankyo_wether::dKyw_get_wind_vec();
  iVar3 = SComponent::cM_atan2s(pcVar1->x,pcVar1->z);
  uVar2 = dOw_angleRegular(this,(d_operate_wind::_4841 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(short)((short)iVar3 + -0x8000) ^
                                                         0x80000000) - d_operate_wind::_4282)) /
                                d_operate_wind::_4949 - d_operate_wind::_4950);
  *(undefined2 *)(this + 0x8cc) = uVar2;
  arrowRotate(this,(fopMsgM_pane_class *)(this + 0xec),*(short *)(this + 0x8cc));
  arrowRotate(this,(fopMsgM_pane_class *)(this + 0x194),*(short *)(this + 0x8cc) + 0x5a);
  dVar4 = (double)(**(code **)(**(int **)(this + 0x55c) + 8))();
  *(float *)(this + 0x8b8) = (float)dVar4;
  lineInit(this,d_operate_wind::_4027);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dOperate_wind_c::_create(void) */

void __thiscall dOperate_wind_c::_create(dOperate_wind_c *this)

{
  J2DPane *pJVar1;
  ulong uVar2;
  STControl *this_00;
  undefined **ppuVar3;
  TBox2_float_ local_38;
  TBox2_float_ local_28;
  
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_28.mTL.x = d_operate_wind::_4027;
    local_28.mTL.y = d_operate_wind::_4027;
    local_28.mBR.x = d_operate_wind::_5016;
    local_28.mBR.y = d_operate_wind::_5017;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = pJVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x3de,"scrn1 != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x3de,"Halt");
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"operate_wind.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWindResArchive);
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_38.mTL.x = d_operate_wind::_4027;
    local_38.mTL.y = d_operate_wind::_4027;
    local_38.mBR.x = d_operate_wind::_5016;
    local_38.mBR.y = d_operate_wind::_5017;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_38);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 8) = pJVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x3e2,"scrn2 != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x3e2,"Halt");
  }
  J2DScreen::set(*(J2DScreen **)(this + 8),"operate_wind_mask.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWindResArchive);
  this_00 = (STControl *)JKernel::operator_new(0x28);
  if (this_00 != (STControl *)0x0) {
    STControl::STControl(this_00,5,2,3,2,d_operate_wind::_4766,d_operate_wind::_4766,0x1000,0x2000);
  }
  *(STControl **)(this + 0x55c) = this_00;
  if (*(int *)(this + 0x55c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x3e6,"stick != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x3e6,"Halt");
  }
  ppuVar3 = (undefined **)JKernel::operator_new(0x330);
  if (ppuVar3 != (undefined **)0x0) {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = &dDlst_Ow_main_c::__vt;
    ppuVar3[2] = (undefined *)0xffffffff;
  }
  *(undefined ***)(this + 0x560) = ppuVar3;
  if (*(int *)(this + 0x560) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x3e9,"mMain != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x3e9,"Halt");
  }
  *(undefined4 *)(*(int *)(this + 0x560) + 4) = *(undefined4 *)(this + 4);
  ppuVar3 = (undefined **)JKernel::operator_new(8);
  if (ppuVar3 != (undefined **)0x0) {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = &dDlst_Ow_mask_c::__vt;
  }
  *(undefined ***)(this + 0x564) = ppuVar3;
  if (*(int *)(this + 0x564) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x3ed,"mMask != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x3ed,"Halt");
  }
  *(undefined4 *)(*(int *)(this + 0x564) + 4) = *(undefined4 *)(this + 8);
  screenSet(this);
  initialize(this);
  return;
}


/* __thiscall dOperate_wind_c::_delete(void) */

void __thiscall dOperate_wind_c::_delete(dOperate_wind_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0x55c));
  piVar1 = *(int **)(this + 0x560);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 0x564);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWindResArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  return;
}


/* __thiscall dOperate_wind_c::_move(void) */

void __thiscall dOperate_wind_c::_move(dOperate_wind_c *this)

{
  byte bVar1;
  
  bVar1 = d_meter::dMenu_flag();
  if (bVar1 == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
        d_com_inf_game::g_dComIfG_gameInfo._23526_1_ = 0;
      }
    }
    else {
      windSet(this);
      d_com_inf_game::g_dComIfG_gameInfo._23526_1_ = 1;
    }
    arrowColor1(this);
    arrowColor2(this);
    maskColor(this);
    arrowDirection(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dOperate_wind_c::_draw(void) */

void __thiscall dOperate_wind_c::_draw(dOperate_wind_c *this)

{
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x44));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x7c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb4));
  f_op_msg_mng::fopMsgM_setAlpha(this + 0x54c);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x124));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 2);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x194));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1cc));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x2ac));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x46c));
  f_op_msg_mng::fopMsgM_setAlpha(this + 0x554);
  lineDraw(this);
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0x564));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0x560));
  return;
}


/* __thiscall dOperate_wind_c::_open(void) */

bool __thiscall dOperate_wind_c::_open(dOperate_wind_c *this)

{
  double dVar1;
  double dVar2;
  
  if (*(short *)(this + 0x8c8) < 10) {
    *(short *)(this + 0x8c8) = *(short *)(this + 0x8c8) + 1;
    dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x8c8),0);
    alphaSet(this,(float)dVar1);
    ringScale(this,(float)dVar1);
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - *(short *)(this + 0x8c8),0);
    directionTrans(this,(float)dVar2);
    lineInit(this,(float)dVar1);
  }
  return 9 < *(short *)(this + 0x8c8);
}


/* __thiscall dOperate_wind_c::_close(void) */

bool __thiscall dOperate_wind_c::_close(dOperate_wind_c *this)

{
  undefined uVar1;
  double dVar2;
  
  uVar1 = DAT_803e6fec;
  if (0 < *(short *)(this + 0x8c8)) {
    *(short *)(this + 0x8c8) = *(short *)(this + 0x8c8) + -1;
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(uVar1,(int)*(short *)(this + 0x8c8),0);
    alphaSet(this,(float)dVar2);
  }
  return *(short *)(this + 0x8c8) < 1;
}


/* __thiscall dOw_c::_create(void) */

void __thiscall dOw_c::_create(dOw_c *this)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  puVar1 = (undefined4 *)JKernel::operator_new(0x8d8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &dOperate_wind_c::__vt;
    puVar1[0x15a] = 0xffffffff;
    puVar1[0x15b] = 0xffffffff;
    puVar1[0x15c] = 0xffffffff;
    puVar1[0x15d] = 0xffffffff;
    puVar1[0x15e] = 0xffffffff;
    puVar1[0x15f] = 0xffffffff;
    puVar1[0x160] = 0xffffffff;
    puVar1[0x161] = 0xffffffff;
    puVar1[0x162] = 0xffffffff;
    puVar1[0x163] = 0xffffffff;
    puVar1[0x164] = 0xffffffff;
    puVar1[0x165] = 0xffffffff;
  }
  *(undefined4 **)(this + 0x100) = puVar1;
  if (*(int *)(this + 0x100) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x478,"dOw_scrn != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x478,"Halt");
  }
  dOperate_wind_c::_create(*(dOperate_wind_c **)(this + 0x100));
  return;
}


/* __thiscall dOw_c::_delete(void) */

void __thiscall dOw_c::_delete(dOw_c *this)

{
  int *piVar1;
  
  dOperate_wind_c::_delete(*(dOperate_wind_c **)(this + 0x100));
  piVar1 = *(int **)(this + 0x100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  return;
}


namespace d_operate_wind {

/* __stdcall dOw_Draw(dOw_c *) */

undefined4 dOw_Draw(int param_1)

{
  if (*(char *)(param_1 + 0x104) != '\0') {
    ::dOperate_wind_c::_draw(*(dOperate_wind_c **)(param_1 + 0x100));
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dOw_Execute(dOw_c *) */

undefined4 dOw_Execute(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  if (init_5174 == '\0') {
    wind_flag_5173 = d_com_inf_game::g_dComIfG_gameInfo._23526_1_;
    init_5174 = '\x01';
  }
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  if (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02') {
    cVar2 = ::dOperate_wind_c::_open(*(dOperate_wind_c **)(param_1 + 0x100));
    if (cVar2 != '\0') {
      ::dOperate_wind_c::_move(*(dOperate_wind_c **)(param_1 + 0x100));
    }
  }
  else {
    if (wind_flag_5173 == '\x02') {
      *(undefined2 *)(*(int *)(param_1 + 0x100) + 0x8c8) = DAT_803e6fdc;
    }
    cVar2 = ::dOperate_wind_c::_close(*(dOperate_wind_c **)(param_1 + 0x100));
    if (cVar2 == '\0') {
      ::dOperate_wind_c::_move(*(dOperate_wind_c **)(param_1 + 0x100));
    }
    else {
      *(undefined *)(param_1 + 0x104) = 0;
      f_op_msg_mng::fopMsgM_Delete(param_1);
    }
  }
  wind_flag_5173 = d_com_inf_game::g_dComIfG_gameInfo._23526_1_;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return 1;
}


/* __stdcall dOw_IsDelete(dOw_c *) */

undefined4 dOw_IsDelete(void)

{
  return 1;
}


/* __stdcall dOw_Delete(dOw_c *) */

undefined4 dOw_Delete(dOw_c *param_1)

{
  undefined4 uVar1;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  ::dOw_c::_delete(param_1);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  f_op_msg_mng::fopMsgM_destroyExpHeap(*(undefined4 *)(param_1 + 0xfc));
  return 1;
}


/* __stdcall dOw_Create(msg_class *) */

undefined4 dOw_Create(dOw_c *param_1)

{
  JKRHeap *pJVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  pJVar1 = f_op_msg_mng::fopMsgM_createExpHeap(20000);
  if (pJVar1 == (JKRHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_operate_wind.cpp",0x547,"heap != 0");
    m_Do_printf::OSPanic("d_operate_wind.cpp",0x547,"Halt");
  }
  *(JKRHeap **)(param_1 + 0xfc) = pJVar1;
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  param_1[0x104] = (dOw_c)0x1;
  ::dOw_c::_create(param_1);
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  return 4;
}

}

/* __thiscall dDlst_Ow_mask_c::~dDlst_Ow_mask_c(void) */

void __thiscall dDlst_Ow_mask_c::_dDlst_Ow_mask_c(dDlst_Ow_mask_c *this)

{
  short in_r4;
  
  if (this != (dDlst_Ow_mask_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_Ow_mask_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_Ow_main_c::~dDlst_Ow_main_c(void) */

void __thiscall dDlst_Ow_main_c::_dDlst_Ow_main_c(dDlst_Ow_main_c *this)

{
  short in_r4;
  
  if (this != (dDlst_Ow_main_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_Ow_main_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dOperate_wind_c::~dOperate_wind_c(void) */

void __thiscall dOperate_wind_c::_dOperate_wind_c(dOperate_wind_c *this)

{
  short in_r4;
  
  if ((this != (dOperate_wind_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dOw_HIO_c::~dOw_HIO_c(void) */

void __thiscall dOw_HIO_c::_dOw_HIO_c(dOw_HIO_c *this)

{
  short in_r4;
  
  if (this != (dOw_HIO_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dOw_HIO_c *)0x0) {
      *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_operate_wind {

void __sinit_d_operate_wind_cpp(void)

{
  ::dOw_HIO_c::dOw_HIO_c((dOw_HIO_c *)&g_owHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

