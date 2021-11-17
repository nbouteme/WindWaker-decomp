#include <d_s_open_sub.h>
#include <m_Do_ext.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_op_msg_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_s_open_sub.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <d_resorce.h>
#include <J2DGraph/J2DScreen.h>
#include <f_op_overlap_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <dScnOpen_proc_c.h>
#include <dScnOpen_message_c.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8023332c) */
/* __thiscall dScnOpen_message_c::set_message(unsigned long,
                                              int) */

void __thiscall dScnOpen_message_c::set_message(dScnOpen_message_c *this,ulong param_1,int param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  mesg_header *pmVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 in_f31;
  double dVar10;
  undefined1 *local_88;
  undefined4 local_84;
  undefined2 local_80;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  undefined2 local_72;
  undefined2 local_70;
  undefined2 local_6e;
  dScnOpen_message_c local_6c;
  dScnOpen_message_c local_6b;
  dScnOpen_message_c local_6a;
  dScnOpen_message_c local_69;
  dScnOpen_message_c local_68;
  dScnOpen_message_c local_67;
  dScnOpen_message_c local_66;
  dScnOpen_message_c local_65;
  dScnOpen_message_c local_64;
  dScnOpen_message_c local_63;
  dScnOpen_message_c local_62;
  dScnOpen_message_c local_61;
  double local_60;
  double local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  undefined4 local_30;
  uint uStack44;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x22d4));
  local_88 = &fopMsgM_msgGet_c::__vt;
  local_84 = 0;
  local_80 = 0;
  local_7e = 0;
  local_7c = 0;
  this[0x22bc] = (dScnOpen_message_c)0x6;
  if (param_1 == 0) {
    *(undefined4 *)(this + 0x22e4) = 4;
    *(undefined4 *)(this + 0x22c0) = 0x579;
  }
  else {
    *(undefined4 *)(this + 0x22e4) = 0;
    *(ulong *)(this + 0x22c0) = param_1;
  }
  if (param_2 != 0) {
    *(int *)(this + 0x22ec) = param_2 + -1;
  }
  *(float *)(this + 0x22d8) = d_s_open_sub::0_0;
  *(undefined4 *)(this + 0x22dc) = 0;
  *(int *)(this + 0x22e0) = *(char *)((int)&DAT_80394144 + *(int *)(this + 0x22c0) + 3) * 0x1e;
  this[0x22e8] = (dScnOpen_message_c)0x0;
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 4),"");
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x804),"");
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x1004),"");
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x1804),"");
  fVar3 = d_s_open_sub::_4143;
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar1 = local_60 - d_s_open_sub::_4147;
  fVar2 = (float)dVar1;
  local_58 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
  dVar10 = local_58 - d_s_open_sub::_4147;
  *(float *)(*(int *)(this + 0x22c4) + 0xe4) = d_s_open_sub::_4143;
  *(float *)(*(int *)(this + 0x22c8) + 0xe4) = fVar3;
  iVar5 = *(int *)(this + 0x22c4);
  fVar3 = d_s_open_sub::0_0;
  if (d_s_open_sub::0_0 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar5 + 0xe8) = fVar3;
  fVar2 = d_s_open_sub::0_0;
  if (d_s_open_sub::0_0 < (float)dVar10) {
    fVar2 = (float)dVar10;
  }
  *(float *)(iVar5 + 0xec) = fVar2;
  dVar10 = (double)*(float *)(*(int *)(this + 0x22c8) + 0xe8);
  pmVar6 = (mesg_header *)
           fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_88,*(ulong *)(this + 0x22c0));
  if (pmVar6 == (mesg_header *)0x0) {
    uVar7 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar7,"d_s_open_sub.cpp",0x5d,"head_p");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0x5d,&DAT_80362fb1);
  }
  uVar8 = fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_88,pmVar6);
  fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_78,(mesg_header *)&local_88);
  *(undefined4 *)(this + 0x22a4) = local_78;
  *(undefined2 *)(this + 0x22a8) = local_74;
  *(undefined2 *)(this + 0x22aa) = local_72;
  *(undefined2 *)(this + 0x22ac) = local_70;
  *(undefined2 *)(this + 0x22ae) = local_6e;
  this[0x22b0] = local_6c;
  this[0x22b1] = local_6b;
  this[0x22b2] = local_6a;
  this[0x22b3] = local_69;
  this[0x22b4] = local_68;
  this[0x22b5] = local_67;
  this[0x22b6] = local_66;
  this[0x22b7] = local_65;
  this[0x22b8] = local_64;
  this[0x22b9] = local_63;
  this[0x22ba] = local_62;
  this[0x22bb] = local_61;
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(this + 0x2004));
  *(undefined4 *)(this + 0x2040) = uVar8;
  *(dScnOpen_message_c **)(this + 0x2064) = this + 4;
  *(dScnOpen_message_c **)(this + 0x2044) = this + 4;
  *(dScnOpen_message_c **)(this + 0x2068) = this + 0x804;
  *(dScnOpen_message_c **)(this + 0x2048) = this + 0x804;
  *(dScnOpen_message_c **)(this + 0x206c) = this + 0x1004;
  *(dScnOpen_message_c **)(this + 0x204c) = this + 0x1004;
  *(dScnOpen_message_c **)(this + 0x2070) = this + 0x1804;
  *(dScnOpen_message_c **)(this + 0x2050) = this + 0x1804;
  *(undefined4 *)(this + 0x2008) = *(undefined4 *)(this + 0x22cc);
  *(undefined4 *)(this + 0x200c) = *(undefined4 *)(this + 0x22d0);
  local_58 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x22c4) + 0xe0);
  *(int *)(this + 0x2120) = (int)*(float *)(*(int *)(this + 0x22c4) + 0xe0);
  local_60 = (double)(longlong)(int)*(float *)(*(int *)(this + 0x22c8) + 0xe0);
  *(int *)(this + 0x2128) = (int)*(float *)(*(int *)(this + 0x22c8) + 0xe0);
  local_50 = (longlong)(int)*(float *)(*(int *)(this + 0x22c4) + 0xe4);
  *(int *)(this + 0x2124) = (int)*(float *)(*(int *)(this + 0x22c4) + 0xe4);
  *(dScnOpen_message_c **)(this + 0x2010) = this + 0x22a4;
  iVar5 = (int)dVar1;
  local_48 = (longlong)iVar5;
  *(int *)(this + 0x2148) = iVar5;
  local_40 = (longlong)(int)dVar10;
  *(int *)(this + 0x2150) = (int)dVar10;
  iVar5 = (int)(*(float *)(*(int *)(this + 0x22c4) + 0x14) -
               *(float *)(*(int *)(this + 0x22c4) + 0xc));
  local_38 = (longlong)iVar5;
  *(int *)(this + 0x212c) = iVar5;
  *(undefined4 *)(this + 0x2130) = 0x1e6;
  *(undefined4 *)(this + 0x2164) = 2;
  *(undefined4 *)(this + 0x2160) = 0;
  fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)(this + 0x2004));
  fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)(this + 0x2004));
  uVar8 = *(undefined4 *)(this + 0x2134);
  *(undefined4 *)(this + 0x2134) = 0;
  fVar3 = d_s_open_sub::0_0;
  iVar5 = *(int *)(this + 0x22c4);
  uStack44 = ((uint)(byte)this[0x22ba] - (int)(short)uVar8) - 1 ^ 0x80000000;
  local_30 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack44) - d_s_open_sub::_4147) *
          *(float *)(iVar5 + 0xe4) * d_s_open_sub::_4144;
  *(float *)(iVar5 + 0xd8) = d_s_open_sub::0_0;
  *(float *)(iVar5 + 0xdc) = fVar2;
  iVar5 = *(int *)(this + 0x22c8);
  *(float *)(iVar5 + 0xd8) = fVar3;
  *(float *)(iVar5 + 0xdc) = fVar2 - d_s_open_sub::_4145;
  m_Do_ext::mDoExt_setCurrentHeap(uVar4);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* __thiscall dScnOpen_message_c::exec(void) */

void __thiscall dScnOpen_message_c::exec(dScnOpen_message_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  ___ in_r5;
  
  uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x22d4));
  if ((this[0x22bc] != (dScnOpen_message_c)0xa) && (this[0x22bc] != (dScnOpen_message_c)0xe)) {
    fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(this + 0x2004));
    this[0x22bc] = this[0x2280];
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x22c4),(char *)(this + 4),in_r5);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x22c8),(char *)(this + 0x804),in_r5);
    *(undefined *)(*(int *)(this + 0x22c8) + 0xaa) = 0;
  }
  fVar2 = d_s_open_sub::_4145;
  fVar1 = d_s_open_sub::0_0;
  iVar3 = *(int *)(this + 0x22e4);
  if (iVar3 == 2) {
    if (d_s_open_sub::0_0 < *(float *)(this + 0x22d8)) {
      *(float *)(this + 0x22d8) = *(float *)(this + 0x22d8) - d_s_open_sub::_4190;
    }
    else {
      *(undefined4 *)(this + 0x22dc) = 0;
      *(float *)(this + 0x22d8) = fVar1;
      if (*(int *)(this + 0x22ec) == 0) {
        this[0x22e8] = (dScnOpen_message_c)0x1;
        *(undefined4 *)(this + 0x22e4) = 4;
      }
      else {
        *(undefined4 *)(this + 0x22e4) = 3;
        *(int *)(this + 0x22ec) = *(int *)(this + 0x22ec) + -1;
      }
    }
  }
  else {
    if (iVar3 < 2) {
      if (iVar3 == 0) {
        if (*(float *)(this + 0x22d8) < d_s_open_sub::_4145) {
          *(float *)(this + 0x22d8) = *(float *)(this + 0x22d8) + d_s_open_sub::_4190;
        }
        else {
          *(undefined4 *)(this + 0x22dc) = 0;
          *(undefined4 *)(this + 0x22e4) = 1;
          *(float *)(this + 0x22d8) = fVar2;
        }
      }
      else {
        if (-1 < iVar3) {
          if (*(int *)(this + 0x22dc) < *(int *)(this + 0x22e0)) {
            *(int *)(this + 0x22dc) = *(int *)(this + 0x22dc) + 1;
          }
          else {
            *(undefined4 *)(this + 0x22dc) = 0;
            *(undefined4 *)(this + 0x22e4) = 2;
            *(float *)(this + 0x22d8) = d_s_open_sub::_4145;
          }
        }
      }
    }
    else {
      if ((iVar3 != 4) && (iVar3 < 4)) {
        if (*(int *)(this + 0x22dc) < 0x2d) {
          *(int *)(this + 0x22dc) = *(int *)(this + 0x22dc) + 1;
        }
        else {
          set_message(this,*(int *)(this + 0x22c0) + 1,0);
          *(undefined4 *)(this + 0x22e4) = 0;
          *(undefined4 *)(this + 0x22dc) = 0;
        }
      }
    }
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar4);
  return;
}


/* __thiscall dScnOpen_message_c::dScnOpen_message_c(JKRExpHeap *) */

void __thiscall dScnOpen_message_c::dScnOpen_message_c(dScnOpen_message_c *this,JKRExpHeap *param_1)

{
  undefined4 uVar1;
  JUTFont *pJVar2;
  ulong uVar3;
  
  *(undefined1 **)this = &__vt;
  fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(this + 0x2004));
  *(JKRExpHeap **)(this + 0x22d4) = param_1;
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x22d4));
  pJVar2 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0x22cc) = pJVar2;
  if (*(int *)(this + 0x22cc) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_s_open_sub.cpp",0xcd,"tFont != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xcd,&DAT_80362fb1);
  }
  pJVar2 = m_Do_ext::mDoExt_getRubyFont();
  *(JUTFont **)(this + 0x22d0) = pJVar2;
  if (*(int *)(this + 0x22d0) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_s_open_sub.cpp",0xd0,"rFont != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xd0,&DAT_80362fb1);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __thiscall dScnOpen_message_c::~dScnOpen_message_c(void) */

void __thiscall dScnOpen_message_c::_dScnOpen_message_c(dScnOpen_message_c *this)

{
  short in_r4;
  
  if (this != (dScnOpen_message_c *)0x0) {
    *(undefined1 **)this = &__vt;
    m_Do_ext::mDoExt_removeMesgFont();
    m_Do_ext::mDoExt_removeRubyFont();
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x22d4));
    m_Do_ext::mDoExt_setCurrentHeap();
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(this + 0x2004));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dScnOpen_proc_c::dScnOpen_proc_c(void) */

void __thiscall dScnOpen_proc_c::dScnOpen_proc_c(dScnOpen_proc_c *this)

{
  JKRExpHeap *pJVar1;
  ulong uVar2;
  undefined4 uVar3;
  J2DScreen *pScreen;
  dScnOpen_message_c *pdVar4;
  dRes_info_c *pdVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  TBox2_float_ local_28;
  
  this->vtbl = (undefined *)&dDlst_base_c::__vt;
  this->vtbl = &__vt;
  pJVar1 = (JKRExpHeap *)f_op_msg_mng::fopMsgM_createExpHeap(0x20000);
  this->mpHeap = pJVar1;
  if (this->mpHeap == (JKRExpHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_open_sub.cpp",0xe2,"exp_heap != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xe2,&DAT_80362fb1);
  }
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  pScreen = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pScreen != (J2DScreen *)0x0) {
    local_28.mTL.x = d_s_open_sub::0_0;
    local_28.mTL.y = d_s_open_sub::0_0;
    local_28.mBR.x = d_s_open_sub::640_0;
    local_28.mBR.y = d_s_open_sub::480_0;
    J2DPane::J2DPane((J2DPane *)pScreen,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    (pScreen->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pScreen->field_0xd0 = (_GXColor)0xffffffff;
    pScreen->mbClipToParent = 0;
  }
  this->mpScreen = pScreen;
  if (this->mpScreen == (J2DScreen *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_open_sub.cpp",0xe7,"m_Screen != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xe7,&DAT_80362fb1);
  }
  pdVar4 = (dScnOpen_message_c *)JKernel::operator_new(0x22f0);
  if (pdVar4 != (dScnOpen_message_c *)0x0) {
    dScnOpen_message_c::dScnOpen_message_c(pdVar4,this->mpHeap);
  }
  this->mpMessage = pdVar4;
  if (this->mpMessage == (dScnOpen_message_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_open_sub.cpp",0xe9,"m_message != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xe9,&DAT_80362fb1);
  }
  pdVar5 = dRes_control_c::getResInfo
                     ("Opening",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pdVar5 == (dRes_info_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_open_sub.cpp",0xeb,"resInfo != 0");
    m_Do_printf::OSPanic("d_s_open_sub.cpp",0xeb,&DAT_80362fb1);
  }
  J2DScreen::set(this->mpScreen,"Opening.blo",pdVar5->mpArchive);
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6431);
  *(undefined4 *)&this->field_0x10 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6432);
  *(undefined4 *)&this->field_0x14 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6433);
  *(undefined4 *)&this->field_0x18 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6434);
  *(undefined4 *)&this->field_0x1c = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x643432);
  *(undefined4 *)&this->field_0x20 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6435);
  *(undefined4 *)&this->field_0x24 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6436);
  *(undefined4 *)&this->field_0x28 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6d616b31);
  *(undefined4 *)&this->field_0x2c = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x6d616b32);
  *(undefined4 *)&this->field_0x30 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x747831);
  *(undefined4 *)&this->field_0x34 = uVar6;
  uVar6 = (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x747832);
  *(undefined4 *)&this->field_0x38 = uVar6;
  (**(code **)(**(int **)&this->field_0x34 + 0x10))
            ((double)(float)(*(int **)&this->field_0x34)[3],(double)d_s_open_sub::_4264);
  uVar6 = *(undefined4 *)&this->field_0x38;
  pdVar4 = this->mpMessage;
  *(undefined4 *)(pdVar4 + 0x22c4) = *(undefined4 *)&this->field_0x34;
  *(undefined4 *)(pdVar4 + 0x22c8) = uVar6;
  J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0x22c4),*(JUTFont **)(pdVar4 + 0x22cc));
  J2DTextBox::setFont(*(J2DTextBox **)(pdVar4 + 0x22c8),*(JUTFont **)(pdVar4 + 0x22d0));
  *(undefined4 *)(*(int *)(pdVar4 + 0x22c8) + 0xe4) =
       *(undefined4 *)(*(int *)(pdVar4 + 0x22c4) + 0xe4);
  iVar7 = 0;
  iVar9 = 0;
  iVar8 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(&this->field_0x3c + iVar8),
               *(J2DScreen **)(&this->field_0x10 + iVar9));
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(&this->field_0x3c + iVar8),d_s_open_sub::0_0);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x3c + iVar8));
    iVar7 = iVar7 + 1;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 0x38;
  } while (iVar7 < 0xb);
  iVar7 = 7;
  iVar8 = 0x188;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(&this->field_0x3c + iVar8),d_s_open_sub::_4145);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x3c + iVar8));
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x38;
  } while (iVar7 < 9);
  dScnOpen_message_c::set_message(this->mpMessage,0,0);
  *(undefined4 *)&this->field_0x2b0 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dScnOpen_proc_c::~dScnOpen_proc_c(void) */

void __thiscall dScnOpen_proc_c::_dScnOpen_proc_c(dScnOpen_proc_c *this)

{
  undefined4 uVar1;
  J2DScreen *pJVar2;
  int *piVar3;
  short in_r4;
  
  if (this != (dScnOpen_proc_c *)0x0) {
    this->vtbl = &__vt;
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
    pJVar2 = this->mpScreen;
    if (pJVar2 != (J2DScreen *)0x0) {
      (*(code *)((pJVar2->parent).vtbl)->_J2DPane)(pJVar2,1);
    }
    this->mpScreen = (J2DScreen *)0x0;
    piVar3 = (int *)this->mpMessage;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3,1);
    }
    this->mpMessage = (dScnOpen_message_c *)0x0;
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    f_op_msg_mng::fopMsgM_destroyExpHeap(this->mpHeap);
    if (this != (dScnOpen_proc_c *)0x0) {
      this->vtbl = (undefined *)&dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802344b8) */
/* __thiscall dScnOpen_proc_c::proc_execute(void) */

void __thiscall dScnOpen_proc_c::proc_execute(dScnOpen_proc_c *this)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  dScnOpen_message_c::exec(this->mpMessage);
  fVar1 = d_s_open_sub::0_0;
  switch(*(undefined4 *)&this->field_0x2b0) {
  case 0:
    *(undefined4 *)&this->field_0x2ac = 0;
    *(undefined4 *)&this->field_0x2b0 = 1;
  case 1:
    if (*(int *)&this->field_0x2ac < 0x5a) {
      *(int *)&this->field_0x2ac = *(int *)&this->field_0x2ac + 1;
    }
    else {
      *(undefined4 *)&this->field_0x2b0 = 2;
    }
    if ((*(int *)&this->field_0x2ac == 0x28) &&
       (iVar3 = f_op_overlap_mng::fopOvlpM_IsPeek(), iVar3 == 0)) {
      JAIZelBasic::bgmStreamPrepare(JAIZelBasic::zel_basic,0xc0000024);
    }
    break;
  case 2:
    JAIZelBasic::bgmStreamPlay(JAIZelBasic::zel_basic);
    dScnOpen_message_c::set_message(this->mpMessage,0x58e,1);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x234,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::_4406);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x26c,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::_4406);
    *(undefined4 *)&this->field_0x2b0 = 3;
  case 3:
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 4;
    }
    break;
  case 4:
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x234,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::0_0);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x26c,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::0_0);
    *(undefined4 *)&this->field_0x2ac = 0;
    *(undefined4 *)&this->field_0x2b0 = 5;
  case 5:
    if (*(int *)&this->field_0x2ac < 0x3c) {
      *(int *)&this->field_0x2ac = *(int *)&this->field_0x2ac + 1;
    }
    else {
      *(undefined4 *)&this->field_0x2b0 = 6;
    }
    break;
  case 6:
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x3c,d_s_open_sub::0_0);
    fVar1 = d_s_open_sub::0_0;
    *(float *)&this->field_0x2a4 = d_s_open_sub::0_0;
    *(float *)&this->field_0x2a8 = fVar1;
    *(undefined4 *)&this->field_0x2b0 = 7;
  case 7:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4407;
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4408;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 8;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x3c,(double)d_s_open_sub::0_0,
               (double)*(float *)&this->field_0x2a4);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x3c,*(float *)&this->field_0x2a8);
    break;
  case 8:
    dScnOpen_message_c::set_message(this->mpMessage,0x579,2);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x3c,d_s_open_sub::_4145);
    *(undefined4 *)&this->field_0x2b0 = 9;
  case 9:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4407;
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 10;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x3c,(double)d_s_open_sub::0_0,
               (double)*(float *)&this->field_0x2a4);
    break;
  case 10:
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x3c,d_s_open_sub::_4145);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x74,d_s_open_sub::0_0);
    *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
    *(undefined4 *)&this->field_0x2b0 = 0xb;
  case 0xb:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4407;
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4409;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 0xc;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x3c,(double)d_s_open_sub::0_0,
               (double)*(float *)&this->field_0x2a4);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x3c,
               d_s_open_sub::_4145 - *(float *)&this->field_0x2a8);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x74,*(float *)&this->field_0x2a8);
    break;
  case 0xc:
    dScnOpen_message_c::set_message(this->mpMessage,0x57b,3);
    *(undefined4 *)&this->field_0x2b0 = 0xd;
  case 0xd:
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0xe;
    }
    break;
  case 0xe:
    *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
    *(undefined4 *)&this->field_0x2b0 = 0xf;
  case 0xf:
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 - d_s_open_sub::_4408;
    if (*(float *)&this->field_0x2a8 <= d_s_open_sub::0_0) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
      *(undefined4 *)&this->field_0x2b0 = 0x10;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x74,*(float *)&this->field_0x2a8);
    break;
  case 0x10:
    *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
    *(undefined4 *)&this->field_0x2b0 = 0x11;
  case 0x11:
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4408;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 0x12;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0xac,*(float *)&this->field_0x2a8);
    break;
  case 0x12:
    dScnOpen_message_c::set_message(this->mpMessage,0x57e,2);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0xac,d_s_open_sub::_4145);
    *(undefined4 *)&this->field_0x2b0 = 0x13;
  case 0x13:
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0x14;
    }
    break;
  case 0x14:
    *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
    *(undefined4 *)&this->field_0x2b0 = 0x15;
  case 0x15:
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 - d_s_open_sub::_4408;
    if (*(float *)&this->field_0x2a8 <= d_s_open_sub::0_0) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
      *(undefined4 *)&this->field_0x2b0 = 0x16;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0xac,*(float *)&this->field_0x2a8);
    break;
  case 0x16:
    *(float *)&this->field_0x2a4 = d_s_open_sub::0_0;
    *(float *)&this->field_0x2a8 = fVar1;
    *(undefined4 *)&this->field_0x2b0 = 0x17;
  case 0x17:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4410;
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4408;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 0x18;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0xe4,(double)*(float *)&this->field_0x2a4,
               (double)d_s_open_sub::0_0);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0xe4,*(float *)&this->field_0x2a8);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x11c,*(float *)&this->field_0x2a8);
    break;
  case 0x18:
    dScnOpen_message_c::set_message(this->mpMessage,0x580,5);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0xe4,d_s_open_sub::_4145);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x11c,d_s_open_sub::_4145);
    *(undefined4 *)&this->field_0x2b0 = 0x19;
  case 0x19:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4410;
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0x1a;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0xe4,(double)*(float *)&this->field_0x2a4,
               (double)d_s_open_sub::0_0);
    break;
  case 0x1a:
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0xe4,d_s_open_sub::_4145);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x11c,d_s_open_sub::_4145);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x154,d_s_open_sub::0_0);
    *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
    *(undefined4 *)&this->field_0x2b0 = 0x1b;
  case 0x1b:
    *(float *)&this->field_0x2a4 = *(float *)&this->field_0x2a4 - d_s_open_sub::_4410;
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4409;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 0x1c;
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0xe4,(double)*(float *)&this->field_0x2a4,
               (double)d_s_open_sub::0_0);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0xe4,
               d_s_open_sub::_4145 - *(float *)&this->field_0x2a8);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x11c,
               d_s_open_sub::_4145 - *(float *)&this->field_0x2a8);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x154,*(float *)&this->field_0x2a8);
    break;
  case 0x1c:
    dScnOpen_message_c::set_message(this->mpMessage,0x585,4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x154,d_s_open_sub::_4145);
    *(undefined4 *)&this->field_0x2b0 = 0x1d;
  case 0x1d:
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0x1e;
    }
    break;
  case 0x1e:
    *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
    *(undefined4 *)&this->field_0x2b0 = 0x1f;
  case 0x1f:
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 - d_s_open_sub::_4408;
    if (*(float *)&this->field_0x2a8 <= d_s_open_sub::0_0) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
      *(undefined4 *)&this->field_0x2b0 = 0x20;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x154,*(float *)&this->field_0x2a8);
    break;
  case 0x20:
    *(undefined4 *)&this->field_0x2ac = 0;
    *(undefined4 *)&this->field_0x2b0 = 0x21;
  case 0x21:
    if (*(int *)&this->field_0x2ac < 0x5a) {
      *(int *)&this->field_0x2ac = *(int *)&this->field_0x2ac + 1;
    }
    else {
      *(undefined4 *)&this->field_0x2b0 = 0x22;
    }
    break;
  case 0x22:
    dScnOpen_message_c::set_message(this->mpMessage,0x589,1);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x234,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::_4406);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x26c,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::_4406);
    *(undefined4 *)&this->field_0x2b0 = 0x23;
  case 0x23:
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0x24;
    }
    break;
  case 0x24:
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x234,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::0_0);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)&this->field_0x26c,(double)d_s_open_sub::0_0,
               (double)d_s_open_sub::0_0);
    *(undefined4 *)&this->field_0x2ac = 0;
    *(undefined4 *)&this->field_0x2b0 = 0x25;
  case 0x25:
    if (*(int *)&this->field_0x2ac < 0x3c) {
      *(int *)&this->field_0x2ac = *(int *)&this->field_0x2ac + 1;
    }
    else {
      *(undefined4 *)&this->field_0x2b0 = 0x26;
    }
    break;
  case 0x26:
    *(float *)&this->field_0x2b4 = d_s_open_sub::_4411;
    *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
    *(undefined4 *)&this->field_0x2b0 = 0x27;
  case 0x27:
    *(float *)&this->field_0x2b4 = *(float *)&this->field_0x2b4 - d_s_open_sub::_4412;
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 + d_s_open_sub::_4408;
    if (d_s_open_sub::_4145 <= *(float *)&this->field_0x2a8) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
      *(undefined4 *)&this->field_0x2b0 = 0x28;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x18c,*(float *)&this->field_0x2a8);
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)&this->field_0x18c,*(float *)&this->field_0x2b4);
    break;
  case 0x28:
    dScnOpen_message_c::set_message(this->mpMessage,0x58a,4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x18c,d_s_open_sub::_4145);
    *(undefined4 *)&this->field_0x2b0 = 0x29;
  case 0x29:
    *(float *)&this->field_0x2b4 = *(float *)&this->field_0x2b4 - d_s_open_sub::_4412;
    if (*(float *)&this->field_0x2b4 < d_s_open_sub::_4145) {
      *(float *)&this->field_0x2b4 = d_s_open_sub::_4145;
    }
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)&this->field_0x18c,*(float *)&this->field_0x2b4);
    if (this->mpMessage[0x22e8] != (dScnOpen_message_c)0x0) {
      *(undefined4 *)&this->field_0x2b0 = 0x2a;
    }
    break;
  case 0x2a:
    *(float *)&this->field_0x2a8 = d_s_open_sub::_4145;
    *(undefined4 *)&this->field_0x2b0 = 0x2b;
  case 0x2b:
    *(float *)&this->field_0x2a8 = *(float *)&this->field_0x2a8 - d_s_open_sub::_4408;
    if (*(float *)&this->field_0x2a8 <= d_s_open_sub::0_0) {
      *(float *)&this->field_0x2a8 = d_s_open_sub::0_0;
      *(undefined4 *)&this->field_0x2b0 = 0x2c;
    }
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)&this->field_0x18c,*(float *)&this->field_0x2a8);
  }
  dVar6 = (double)*(float *)(this->mpMessage + 0x22d8);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)&this->field_0x234,*(float *)(this->mpMessage + 0x22d8));
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)&this->field_0x26c,(float)dVar6);
  iVar3 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(&this->field_0x3c + iVar4));
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 0xb);
  m_Do_ext::mDoExt_setCurrentHeap(uVar2);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dScnOpen_proc_c::proc_draw(void) */

void __thiscall dScnOpen_proc_c::proc_draw(dScnOpen_proc_c *this)

{
  J2DOrthoGraph *pCtx;
  undefined4 uVar1;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(this->mpScreen,d_s_open_sub::0_0,d_s_open_sub::0_0,&pCtx->parent);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __thiscall dScnOpen_proc_c::draw(void) */

void __thiscall dScnOpen_proc_c::draw(dScnOpen_proc_c *this)

{
  proc_draw(this);
  return;
}

