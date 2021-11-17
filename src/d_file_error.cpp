#include <d_file_error.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_ext.h>
#include <m_Do_hostIO.h>
#include <d_file_error.h>
#include <f_op_msg_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_drawlist.h>
#include <J2DGraph/J2DPicture.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <MyScreen.h>
#include <dDlst_FileErr_c.h>
#include <J2DScreen.h>
#include <J2DPane.h>
#include <dFe_HIO_c.h>
#include <dFile_error_c.h>


namespace d_file_error {
undefined g_feHIO;
}

/* __thiscall dFe_HIO_c::dFe_HIO_c(void) */

void __thiscall dFe_HIO_c::dFe_HIO_c(dFe_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[8] = (dFe_HIO_c)0x5;
  this[9] = (dFe_HIO_c)0x5;
  this[10] = (dFe_HIO_c)0x0;
  *(undefined2 *)(this + 6) = 0xfe0c;
  this[0xc] = (dFe_HIO_c)0x7;
  this[0xd] = (dFe_HIO_c)0xa0;
  this[0xe] = (dFe_HIO_c)0x50;
  this[0xf] = (dFe_HIO_c)0xe;
  *(undefined2 *)(this + 0x10) = 0xfffb;
  *(undefined2 *)(this + 0x12) = 0;
  *(float *)(this + 0x14) = d_file_error::_4004;
  *(float *)(this + 0x18) = d_file_error::_4005;
  return;
}


/* __thiscall dFile_error_c::_create(void) */

void __thiscall dFile_error_c::_create(dFile_error_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  JUTFont *pJVar2;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_file_error::_4036;
    local_18.mTL.y = d_file_error::_4036;
    local_18.mBR.x = d_file_error::_4037;
    local_18.mBR.y = d_file_error::_4038;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
    this_00->vtbl = (J2DPane__vtable *)&MyScreen::__vt;
  }
  *(J2DPane **)(this + 0xc) = this_00;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_error.cpp",0x74,"fileErr.Scr != 0");
    m_Do_printf::OSPanic("d_file_error.cpp",0x74,&DAT_8035ed52);
  }
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_file_error::_4039,d_file_error::_4040,0,0x2000);
  }
  *(STControl **)(this + 0x2f0) = this_01;
  if (*(int *)(this + 0x2f0) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_error.cpp",0x79,"stick != 0");
    m_Do_printf::OSPanic("d_file_error.cpp",0x79,&DAT_8035ed52);
  }
  *(JKRArchive **)(this + 4) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpErrorResArchive;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_error.cpp",0x7d,"archive != 0");
    m_Do_printf::OSPanic("d_file_error.cpp",0x7d,&DAT_8035ed52);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"file_error.blo",*(JKRArchive **)(this + 4));
  pJVar2 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0x10) = pJVar2;
  if (*(int *)(this + 0x10) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_error.cpp",0x83,"fileErr.font != 0");
    m_Do_printf::OSPanic("d_file_error.cpp",0x83,&DAT_8035ed52);
  }
  DAT_803e4a28 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"エラー表示画面",
                            (JORReflexible *)&d_file_error::g_feHIO);
  screenSet(this);
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dFile_error_c::initial(void) */

void __thiscall dFile_error_c::initial(dFile_error_c *this)

{
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dFile_error_c::_delete(void) */

void __thiscall dFile_error_c::_delete(dFile_error_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  m_Do_ext::mDoExt_removeMesgFont();
  JKernel::operator_delete(*(JKRHeap **)(this + 0x2f0));
  (**(code **)(**(int **)(this + 4) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e4a28);
  return;
}


/* __thiscall MyScreen::~MyScreen(void) */

void __thiscall MyScreen::_MyScreen(MyScreen *this)

{
  short in_r4;
  
  if (this != (MyScreen *)0x0) {
    *(undefined1 **)this = &__vt;
    J2DScreen::_J2DScreen((J2DScreen *)this,0);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dFile_error_c::setErrMessage(unsigned long,
                                           int) */

void __thiscall dFile_error_c::setErrMessage(dFile_error_c *this,ulong param_1,int param_2)

{
  int iVar1;
  char acStack520 [512];
  
  this[0x2fa] = SUB41(param_2,0);
  initial(this);
  f_op_msg_mng::fopMsgM_messageGet(acStack520,param_1);
  iVar1 = getLineCount(this,acStack520);
  if (iVar1 + 2 < 0xc) {
    resizeMsgBoard(this,iVar1 + 2);
  }
  *(float *)(this + 0x300) =
       (*(float *)(this + 0x94) + *(float *)(this + 0xb4)) -
       d_file_error::_4081 * *(float *)(*(int *)(this + 0x84) + 0xe4);
  *(float *)(this + 0x300) = *(float *)(this + 0x300) - *(float *)(this + 0x24);
  if (7 < iVar1) {
    *(float *)(this + 0x300) = *(float *)(this + 0x300) + d_file_error::_4082;
  }
  ynCursorInit(this);
  setMessage(this,acStack520);
  *(undefined2 *)(this + 0x2fe) = 0;
  this[0x2f5] = (dFile_error_c)0x1;
  this[0x2f4] = (dFile_error_c)0x1;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x897,(cXyz *)0x0,0,0,d_file_error::_4083,d_file_error::_4083,
             d_file_error::_4084,d_file_error::_4084,0);
  return;
}


/* __thiscall dFile_error_c::closeMessage(void) */

void __thiscall dFile_error_c::closeMessage(dFile_error_c *this)

{
  *(undefined2 *)(this + 0x2fe) = 0;
  this[0x2f4] = (dFile_error_c)0x2;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x898,(cXyz *)0x0,0,0,d_file_error::_4083,d_file_error::_4083,
             d_file_error::_4084,d_file_error::_4084,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8017e20c) */
/* __thiscall dFile_error_c::resizeMsgBoard(int) */

void __thiscall dFile_error_c::resizeMsgBoard(dFile_error_c *this,int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = *(float *)(*(int *)(this + 0x84) + 0x18) - *(float *)(*(int *)(this + 0x84) + 0x10);
  dVar3 = (double)(((fVar1 / d_file_error::_4098) *
                   (float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - d_file_error::_4101))
                  / fVar1);
  f_op_msg_mng::fopMsgM_paneScaleY(dVar3,this + 0x84);
  f_op_msg_mng::fopMsgM_paneScaleY(dVar3,this + 0xbc);
  (**(code **)(**(int **)(this + 300) + 0x18))
            ((double)*(float *)(this + 0x158),
             (double)(d_file_error::_4099 + *(float *)(this + 0xec)));
  (**(code **)(**(int **)(this + 0x19c) + 0x18))
            ((double)*(float *)(this + 0x1c8),
             (double)(d_file_error::_4099 + *(float *)(this + 0xec)));
  f_op_msg_mng::fopMsgM_paneScaleY(dVar3,this + 0x1d4);
  (**(code **)(**(int **)(this + 0x20c) + 0x18))
            ((double)*(float *)(this + 0x238),(double)*(float *)(this + 0x204));
  (**(code **)(**(int **)(this + 0x2b4) + 0x18))
            ((double)*(float *)(this + 0x2e0),(double)*(float *)(this + 0x204));
  (**(code **)(**(int **)(this + 0xf4) + 0x10))
            ((double)*(float *)(this + 0x100),(double)*(float *)(this + 0xec));
  (**(code **)(**(int **)(this + 300) + 0x10))
            ((double)*(float *)(this + 0x130),(double)*(float *)(this + 0x134));
  (**(code **)(**(int **)(this + 0x19c) + 0x10))
            ((double)*(float *)(this + 0x1a0),(double)*(float *)(this + 0x1a4));
  (**(code **)(**(int **)(this + 0x20c) + 0x10))
            ((double)*(float *)(this + 0x210),(double)*(float *)(this + 0x214));
  (**(code **)(**(int **)(this + 0x2b4) + 0x10))
            ((double)*(float *)(this + 0x2b8),(double)*(float *)(this + 700));
  (**(code **)(**(int **)(this + 0x244) + 0x10))
            ((double)*(float *)(this + 0x250),(double)*(float *)(this + 0x204));
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8017e24c) */
/* __thiscall dFile_error_c::setMessage(char *) */

void __thiscall dFile_error_c::setMessage(dFile_error_c *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_r9;
  int iVar4;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 2) {
LAB_8017e25c:
    in_r9 = 3;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage < 2) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 0) goto LAB_8017e25c;
    }
    else {
      if (4 < d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage) goto LAB_8017e268;
    }
    in_r9 = 2;
  }
LAB_8017e268:
  pcVar3 = *(char **)(this + 0x2ec);
  this[0x2f7] = (dFile_error_c)0x0;
  while (cVar1 = *param_1, cVar1 != '\0') {
    if (cVar1 == '\x1a') {
      this[0x2f7] = (dFile_error_c)0x1;
      *(undefined *)(*(int *)(this + 0x14) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0x4c) + 0xaa) = 1;
      param_1 = param_1 + 1;
      iVar4 = in_r9;
      if (0 < in_r9) {
        do {
          *pcVar3 = *param_1;
          pcVar3 = pcVar3 + 1;
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      for (pcVar2 = &d_file_error::txt_4112; *pcVar2 != '\0'; pcVar2 = pcVar2 + 1) {
        *pcVar3 = *pcVar2;
        pcVar3 = pcVar3 + 1;
      }
    }
    else {
      *pcVar3 = cVar1;
      pcVar3 = pcVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  *pcVar3 = '\0';
  return;
}


/* __thiscall dFile_error_c::getLineCount(char *) */

int __thiscall dFile_error_c::getLineCount(dFile_error_c *this,char *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == '\n') {
      if (param_1[1] != '\0') {
        iVar1 = iVar1 + 1;
      }
    }
  }
  return iVar1 + 1;
}


/* __thiscall dFile_error_c::_move(void) */

void __thiscall dFile_error_c::_move(dFile_error_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_file_error::FileErrProc + (uint)(byte)this[0x2f4] * 3),this,&DAT_80390000);
  return;
}


/* __thiscall dFile_error_c::ProcWait(void) */

void __thiscall dFile_error_c::ProcWait(dFile_error_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_error_c::ShowMsgBoard(void) */

void __thiscall dFile_error_c::ShowMsgBoard(dFile_error_c *this)

{
  int iVar1;
  int unaff_r28;
  
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x2fe),DAT_803e4a2c,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a2a ^ 0x80000000) -
                                d_file_error::_4101),d_file_error::_4188,
                         *(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                         *(float *)(this + 0x18),
                         *(float *)(this + 0x300) +
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                                d_file_error::_4101),'\x01',0);
  if (iVar1 == 1) {
    unaff_r28 = PaneTranceBase(this,*(short *)(this + 0x2fe) - (ushort)DAT_803e4a2c,DAT_803e4a2c,
                               d_file_error::_4188,d_file_error::_4036,
                               *(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                               *(float *)(this + 0x18),
                               *(float *)(this + 0x300) +
                               (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                                      d_file_error::_4101),'\x04',2);
  }
  *(short *)(this + 0x2fe) = *(short *)(this + 0x2fe) + 1;
  if ((iVar1 == 1) && (unaff_r28 == 1)) {
    if (this[0x2fa] == (dFile_error_c)0x0) {
      if (this[0x2f7] == (dFile_error_c)0x0) {
        this[0x2f4] = (dFile_error_c)0x3;
      }
      else {
        this[0x2f4] = (dFile_error_c)0x4;
      }
    }
    else {
      this[0x2f4] = (dFile_error_c)0x0;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_error_c::ynCursorInit(void) */

void __thiscall dFile_error_c::ynCursorInit(dFile_error_c *this)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneScaleX
              ((double)*(float *)(&DAT_803e4a38 + (uint)(byte)this[0x2f6] * 4),this + iVar6 + 0x14);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 2);
  fVar2 = *(float *)(this + 0x304);
  dVar1 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
  fVar3 = *(float *)(this + 0x44) * d_file_error::_4040;
  piVar4 = *(int **)(this + 0x14);
  piVar4[0x27] = (int)(*(float *)(this + 0x40) * d_file_error::_4040);
  piVar4[0x28] = (int)fVar3;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(fVar2 - (float)dVar1);
  (**(code **)(*piVar4 + 0x20))();
  fVar2 = *(float *)(this + 0x308);
  dVar1 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
  fVar3 = *(float *)(this + 0x7c) * d_file_error::_4040;
  piVar4 = *(int **)(this + 0x4c);
  piVar4[0x27] = (int)(*(float *)(this + 0x78) * d_file_error::_4040);
  piVar4[0x28] = (int)fVar3;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(fVar2 + (float)dVar1);
  (**(code **)(*piVar4 + 0x20))();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_error_c::HideMsgBoard(void) */

void __thiscall dFile_error_c::HideMsgBoard(dFile_error_c *this)

{
  int iVar1;
  int unaff_r28;
  
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x2fe),DAT_803e4a2d,d_file_error::_4036,
                         d_file_error::_4188,
                         *(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                         *(float *)(this + 0x18),
                         *(float *)(this + 0x300) +
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                                d_file_error::_4101),'\x04',2);
  if (iVar1 == 1) {
    unaff_r28 = PaneTranceBase(this,*(short *)(this + 0x2fe) - (ushort)DAT_803e4a2d,DAT_803e4a2d,
                               d_file_error::_4188,
                               (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a2a ^ 0x80000000) -
                                      d_file_error::_4101),
                               *(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                               *(float *)(this + 0x18),
                               *(float *)(this + 0x300) +
                               (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                                      d_file_error::_4101),'\x01',1);
  }
  *(short *)(this + 0x2fe) = *(short *)(this + 0x2fe) + 1;
  if ((iVar1 == 1) && (unaff_r28 == 1)) {
    this[0x2fc] = (dFile_error_c)0x0;
    this[0x2fb] = (dFile_error_c)0x5a;
    this[0x2f5] = (dFile_error_c)0x2;
    this[0x2f4] = (dFile_error_c)0x0;
  }
  return;
}


/* __thiscall dFile_error_c::msgDispWait(void) */

void __thiscall dFile_error_c::msgDispWait(dFile_error_c *this)

{
  if ((this[0x2fc] == (dFile_error_c)0x1) && (this[0x2fb] != (dFile_error_c)0x0)) {
    this[0x2fb] = (dFile_error_c)((char)this[0x2fb] + -1);
  }
  if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
      (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) &&
     (this[0x2fb] != (dFile_error_c)0x0)) {
    return;
  }
  *(undefined2 *)(this + 0x2fe) = 0;
  this[0x2f4] = (dFile_error_c)0x2;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x898,(cXyz *)0x0,0,0,d_file_error::_4083,d_file_error::_4083,
             d_file_error::_4084,d_file_error::_4084,0);
  return;
}


/* __thiscall dFile_error_c::yesNoSelectWait(void) */

void __thiscall dFile_error_c::yesNoSelectWait(dFile_error_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0x2f0));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      this[0x2f6] = (dFile_error_c)0x1;
      ynCursorMove(this);
      *(undefined2 *)(this + 0x2fe) = 0;
      this[0x2f4] = (dFile_error_c)0x2;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x898,(cXyz *)0x0,0,0,d_file_error::_4083,
                 d_file_error::_4083,d_file_error::_4084,d_file_error::_4084,0);
    }
    else {
      cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0x2f0));
      if (cVar1 == '\0') {
        cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0x2f0));
        if ((cVar1 != '\0') && (this[0x2f6] != (dFile_error_c)0x1)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_error::_4083,
                     d_file_error::_4083,d_file_error::_4084,d_file_error::_4084,0);
          this[0x2f6] = (dFile_error_c)0x1;
          ynCursorMove(this);
        }
      }
      else {
        if (this[0x2f6] != (dFile_error_c)0x0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_error::_4083,
                     d_file_error::_4083,d_file_error::_4084,d_file_error::_4084,0);
          this[0x2f6] = (dFile_error_c)0x0;
          ynCursorMove(this);
        }
      }
    }
  }
  else {
    if (this[0x2f6] == (dFile_error_c)0x0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_error::_4083,
                 d_file_error::_4083,d_file_error::_4084,d_file_error::_4084,0);
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_error::_4083,
                 d_file_error::_4083,d_file_error::_4084,d_file_error::_4084,0);
    }
    *(undefined *)(*(int *)(this + 0x14) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x4c) + 0xaa) = 0;
    *(undefined2 *)(this + 0x2fe) = 0;
    this[0x2f4] = (dFile_error_c)0x2;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x898,(cXyz *)0x0,0,0,d_file_error::_4083,d_file_error::_4083,
               d_file_error::_4084,d_file_error::_4084,0);
  }
  ynCursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8017ec3c) */
/* __thiscall dFile_error_c::ynCursorMove(void) */

void __thiscall dFile_error_c::ynCursorMove(dFile_error_c *this)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  dFile_error_c *pdVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this[0x49] = DAT_803e4a31;
  this[0x81] = DAT_803e4a32;
  *(ushort *)(this + 0x4a) = (ushort)DAT_803e4a30;
  *(ushort *)(this + 0x82) = (ushort)DAT_803e4a33;
  this[0x2f8] = (dFile_error_c)0x0;
  this[0x2f9] = (dFile_error_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x4c));
  iVar4 = 0;
  iVar6 = 0;
  dVar8 = d_file_error::_4101;
  do {
    pdVar5 = this + iVar6;
    f_op_msg_mng::fopMsgM_paneScaleX
              ((double)*(float *)(&DAT_803e4a38 + (uint)(byte)this[0x2f6] * 4),
               (fopMsgM_pane_class *)(pdVar5 + 0x14));
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar5 + 0x14),
               (double)(*(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                       *(float *)(pdVar5 + 0x18)),
               (double)(*(float *)(this + 0x300) +
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) - dVar8))
              );
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar4 < 2);
  fVar1 = *(float *)(this + 0x304);
  dVar8 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
  fVar2 = *(float *)(this + 0x44) * d_file_error::_4040;
  piVar3 = *(int **)(this + 0x14);
  piVar3[0x27] = (int)(*(float *)(this + 0x40) * d_file_error::_4040);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(fVar1 - (float)dVar8);
  (**(code **)(*piVar3 + 0x20))();
  fVar1 = *(float *)(this + 0x308);
  dVar8 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
  fVar2 = *(float *)(this + 0x7c) * d_file_error::_4040;
  piVar3 = *(int **)(this + 0x4c);
  piVar3[0x27] = (int)(*(float *)(this + 0x78) * d_file_error::_4040);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(fVar1 + (float)dVar8);
  (**(code **)(*piVar3 + 0x20))();
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_error_c::ynCursorAnime(void) */

void __thiscall dFile_error_c::ynCursorAnime(dFile_error_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int *piVar5;
  char cVar6;
  double dVar7;
  
  if (*(short *)(this + 0x4a) == 0) {
    *(ushort *)(this + 0x4a) = (ushort)DAT_803e4a30;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x14),
               (double)((*(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                        *(float *)(this + 0x18)) +
                       *(float *)(&d_file_error::xp1_4320 + (uint)(byte)this[0x2f9] * 4)),
               (double)(*(float *)(this + 0x300) +
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                              d_file_error::_4101)));
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x4c),
               (double)((*(float *)(&d_file_error::curxp + (uint)(byte)this[0x2f6] * 4) -
                        *(float *)(this + 0x50)) +
                       *(float *)(&d_file_error::xp2_4322 + (uint)(byte)this[0x2f9] * 4)),
               (double)(*(float *)(this + 0x300) +
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a36 ^ 0x80000000) -
                              d_file_error::_4101)));
    fVar1 = *(float *)(this + 0x304);
    dVar7 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
    fVar2 = *(float *)(&d_file_error::rt1_4321 + (uint)(byte)this[0x2f9] * 4);
    fVar3 = *(float *)(this + 0x44) * d_file_error::_4040;
    piVar5 = *(int **)(this + 0x14);
    piVar5[0x27] = (int)(*(float *)(this + 0x40) * d_file_error::_4040);
    piVar5[0x28] = (int)fVar3;
    *(undefined *)(piVar5 + 0x2a) = 0x7a;
    piVar5[0x29] = (int)((fVar1 - (float)dVar7) + fVar2);
    (**(code **)(*piVar5 + 0x20))();
    fVar1 = *(float *)(this + 0x308);
    dVar7 = (double)CONCAT44(0x43300000,(int)DAT_803e4a34 ^ 0x80000000) - d_file_error::_4101;
    fVar2 = *(float *)(&d_file_error::rt2_4323 + (uint)(byte)this[0x2f9] * 4);
    fVar3 = *(float *)(this + 0x7c) * d_file_error::_4040;
    piVar5 = *(int **)(this + 0x4c);
    piVar5[0x27] = (int)(*(float *)(this + 0x78) * d_file_error::_4040);
    piVar5[0x28] = (int)fVar3;
    *(undefined *)(piVar5 + 0x2a) = 0x7a;
    piVar5[0x29] = (int)(fVar1 + (float)dVar7 + fVar2);
    (**(code **)(*piVar5 + 0x20))();
    this[0x2f9] = (dFile_error_c)((char)this[0x2f9] + '\x01');
    if (2 < (byte)this[0x2f9]) {
      this[0x2f9] = (dFile_error_c)0x0;
    }
  }
  else {
    *(short *)(this + 0x4a) = *(short *)(this + 0x4a) + -1;
  }
  dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e4a33,(int)*(short *)(this + 0x82),0);
  bVar4 = DAT_803e4a32;
  if (this[0x2f8] != (dFile_error_c)0x0) {
    dVar7 = (double)(float)((double)d_file_error::_4083 - dVar7);
  }
  cVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e4a31 -
                                                                      (uint)DAT_803e4a32 ^
                                                                      0x80000000) -
                                                    d_file_error::_4101) * dVar7));
  this[0x49] = (dFile_error_c)(bVar4 + cVar6);
  this[0x81] = (dFile_error_c)(DAT_803e4a32 + cVar6);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x4c));
  if (*(short *)(this + 0x82) == 0) {
    *(ushort *)(this + 0x82) = (ushort)DAT_803e4a33;
    this[0x2f8] = (dFile_error_c)((byte)this[0x2f8] ^ 1);
  }
  else {
    *(short *)(this + 0x82) = *(short *)(this + 0x82) + -1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dFile_error_c::screenSet(void) */

void __thiscall dFile_error_c::screenSet(dFile_error_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  J2DScreen *pJVar4;
  char *pcVar5;
  undefined4 uVar6;
  ___ in_r5;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char local_218 [511];
  undefined local_19;
  
  pJVar4 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63757231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x14),pJVar4);
  pJVar4 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63757232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4c),pJVar4);
  *(undefined4 *)(this + 0x304) = *(undefined4 *)(*(int *)(this + 0x14) + 0xa4);
  *(undefined4 *)(this + 0x308) = *(undefined4 *)(*(int *)(this + 0x4c) + 0xa4);
  iVar8 = 0x63633030;
  iVar7 = 0x62303030;
  iVar9 = 0;
  iVar10 = 0;
  do {
    pJVar4 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar8);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar10 + 0xbc),pJVar4);
    pJVar4 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar7);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar10 + 0x1d4),pJVar4);
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0x38;
  } while (iVar9 < 5);
  *(undefined *)(*(int *)(this + 0xf4) + 0x134) = 1;
  fVar1 = d_file_error::_4036;
  *(float *)(*(int *)(this + 0xf4) + 0x124) = d_file_error::_4036;
  *(float *)(*(int *)(this + 0xf4) + 0x128) = fVar1;
  fVar2 = d_file_error::_4389;
  *(float *)(*(int *)(this + 0xf4) + 300) = d_file_error::_4389;
  fVar3 = d_file_error::_4083;
  *(float *)(*(int *)(this + 0xf4) + 0x130) = d_file_error::_4083;
  *(undefined *)(*(int *)(this + 0x164) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x164) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x164) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 0x164) + 300) = fVar2;
  *(float *)(*(int *)(this + 0x164) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 300) + 0x134) = 1;
  *(float *)(*(int *)(this + 300) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 300) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 300) + 300) = fVar2;
  *(float *)(*(int *)(this + 300) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 0x19c) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x19c) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x19c) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 0x19c) + 300) = fVar2;
  *(float *)(*(int *)(this + 0x19c) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 0x244) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x244) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x244) + 0x128) = fVar1;
  fVar2 = d_file_error::_4081;
  *(float *)(*(int *)(this + 0x244) + 300) = d_file_error::_4081;
  *(float *)(*(int *)(this + 0x244) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 0x27c) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x27c) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x27c) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 0x27c) + 300) = fVar2;
  *(float *)(*(int *)(this + 0x27c) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 0x20c) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x20c) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x20c) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 0x20c) + 300) = fVar2;
  *(float *)(*(int *)(this + 0x20c) + 0x130) = fVar3;
  *(undefined *)(*(int *)(this + 0x2b4) + 0x134) = 1;
  *(float *)(*(int *)(this + 0x2b4) + 0x124) = fVar1;
  *(float *)(*(int *)(this + 0x2b4) + 0x128) = fVar1;
  *(float *)(*(int *)(this + 0x2b4) + 300) = fVar2;
  *(float *)(*(int *)(this + 0x2b4) + 0x130) = fVar3;
  pJVar4 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6d6573)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x84),pJVar4);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x84),*(JUTFont **)(this + 0x10));
  pcVar5 = local_218;
  iVar7 = 0x200;
  do {
    *pcVar5 = 'A';
    pcVar5 = pcVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  local_19 = 0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x84),local_218,in_r5);
  uVar6 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x84));
  *(undefined4 *)(this + 0x2ec) = uVar6;
  **(undefined **)(this + 0x2ec) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_error_c::paneTransInit(void) */

void __thiscall dFile_error_c::paneTransInit(dFile_error_c *this)

{
  int iVar1;
  dFile_error_c *pdVar2;
  int iVar3;
  
  iVar3 = 0;
  *(undefined2 *)(this + 0x2fe) = 0;
  iVar1 = 0;
  do {
    pdVar2 = this + iVar3;
    *(undefined4 *)(pdVar2 + 0xd8) = *(undefined4 *)(pdVar2 + 0xd0);
    *(undefined4 *)(pdVar2 + 0xdc) = *(undefined4 *)(pdVar2 + 0xd4);
    *(undefined4 *)(pdVar2 + 0xe8) = *(undefined4 *)(pdVar2 + 0xe0);
    *(undefined4 *)(pdVar2 + 0xec) = *(undefined4 *)(pdVar2 + 0xe4);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 0xbc));
    *(undefined4 *)(pdVar2 + 0x1f0) = *(undefined4 *)(pdVar2 + 0x1e8);
    *(undefined4 *)(pdVar2 + 500) = *(undefined4 *)(pdVar2 + 0x1ec);
    *(undefined4 *)(pdVar2 + 0x200) = *(undefined4 *)(pdVar2 + 0x1f8);
    *(undefined4 *)(pdVar2 + 0x204) = *(undefined4 *)(pdVar2 + 0x1fc);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 0x1d4));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 5);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    *(undefined4 *)(pdVar2 + 0x30) = *(undefined4 *)(pdVar2 + 0x28);
    *(undefined4 *)(pdVar2 + 0x34) = *(undefined4 *)(pdVar2 + 0x2c);
    *(undefined4 *)(pdVar2 + 0x40) = *(undefined4 *)(pdVar2 + 0x38);
    *(undefined4 *)(pdVar2 + 0x44) = *(undefined4 *)(pdVar2 + 0x3c);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 0x14));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 2);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0x98);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(this + 0x9c);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(this + 0xa8);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(this + 0xac);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x84));
  this[0x49] = DAT_803e4a31;
  this[0x81] = DAT_803e4a32;
  *(ushort *)(this + 0x4a) = (ushort)DAT_803e4a30;
  *(ushort *)(this + 0x82) = (ushort)DAT_803e4a33;
  this[0x2f8] = (dFile_error_c)0x0;
  this[0x2f9] = (dFile_error_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x4c));
  this[0x2f6] = (dFile_error_c)0x1;
  PaneTranceBase(this,*(short *)(this + 0x2fe),DAT_803e4a2c,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a2a ^ 0x80000000) -
                        d_file_error::_4101),d_file_error::_4036,d_file_error::_4036,
                 d_file_error::_4036,'\x01',1);
  *(undefined *)(*(int *)(this + 0x14) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x4c) + 0xaa) = 0;
  return;
}


/* __thiscall dFile_error_c::displayInit(void) */

void __thiscall dFile_error_c::displayInit(dFile_error_c *this)

{
  this[0x2fc] = (dFile_error_c)0x0;
  this[0x2fb] = (dFile_error_c)0x5a;
  this[0x2f5] = (dFile_error_c)0x0;
  this[0x2f4] = (dFile_error_c)0x0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8017f57c) */
/* WARNING: Removing unreachable block (ram,0x8017f56c) */
/* WARNING: Removing unreachable block (ram,0x8017f564) */
/* WARNING: Removing unreachable block (ram,0x8017f574) */
/* WARNING: Removing unreachable block (ram,0x8017f584) */
/* __thiscall dFile_error_c::PaneTranceBase(short,
                                            unsigned char,
                                            float,
                                            float,
                                            float,
                                            float,
                                            unsigned char,
                                            int) */

undefined4 __thiscall
dFile_error_c::PaneTranceBase
          (dFile_error_c *this,short param_1,uchar param_2,float param_3,float param_4,float param_5
          ,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double x;
  double dVar5;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar6;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_6;
  x = (double)param_5;
  dVar4 = (double)param_4;
  dVar6 = (double)param_3;
  uVar2 = 0;
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
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      dVar6 = (double)(float)(dVar6 + (double)(float)(dVar3 * (double)(float)(dVar4 - dVar6)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x84),(double)d_file_error::_4036,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xbc),(double)d_file_error::_4036,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1d4),(double)d_file_error::_4036,dVar6);
      dVar6 = (double)(float)(dVar5 + dVar6);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x14),x,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x4c),x,dVar6);
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar3 = (double)(float)((double)d_file_error::_4083 - dVar3);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x84),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xbc),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1d4),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x14),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x4c),(float)dVar3);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x84));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xbc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1d4));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x4c));
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
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  return uVar1;
}


/* __thiscall dFile_error_c::_draw(void) */

void __thiscall dFile_error_c::_draw(dFile_error_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 8));
  return;
}


/* __thiscall dFile_error_c::draw2(void) */

void __thiscall dFile_error_c::draw2(dFile_error_c *this)

{
  J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_file_error::_4036,d_file_error::_4036,
                  &(d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent);
  return;
}


/* __thiscall dDlst_FileErr_c::draw(void) */

void __thiscall dDlst_FileErr_c::draw(dDlst_FileErr_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_file_error::_4036,d_file_error::_4036,&pCtx->parent);
  return;
}


/* __thiscall dDlst_FileErr_c::~dDlst_FileErr_c(void) */

void __thiscall dDlst_FileErr_c::_dDlst_FileErr_c(dDlst_FileErr_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FileErr_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_FileErr_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall MyScreen::createPane(J2DPane::J2DScrnBlockHeader const &,
                                   JSURandomInputStream *,
                                   J2DPane *) */

J2DPane * __thiscall
MyScreen::createPane
          (MyScreen *this,J2DScrnBlockHeader *pHeader,JSURandomInputStream *pStream,J2DPane *pParent
          )

{
  MyPicture *this_00;
  
  if (pHeader->mMagic == 0x50494331) {
    this_00 = (MyPicture *)JKernel::operator_new(0x138);
    if (this_00 != (MyPicture *)0x0) {
      J2DPicture::J2DPicture((J2DPicture *)this_00,pParent,pStream);
      (this_00->parent).parent.vtbl = (J2DPane__vtable *)&MyPicture::__vt;
      this_00->field_0x134 = 0;
    }
  }
  else {
    this_00 = (MyPicture *)J2DScreen::createPane((J2DScreen *)this,pHeader,pStream,pParent);
  }
  return (J2DPane *)this_00;
}


/* __thiscall J2DScreen::getTypeID(void) */

J2DTypeID __thiscall J2DScreen::getTypeID(J2DScreen *this)

{
  return J2DScreen;
}


/* __thiscall J2DScreen::calcMtx(void) */

void __thiscall J2DScreen::calcMtx(J2DScreen *this)

{
  (*(code *)((this->parent).vtbl)->makeMatrix)
            ((double)(this->parent).mPosTL.x,(double)(this->parent).mPosTL.y);
  return;
}


/* __thiscall dFe_HIO_c::~dFe_HIO_c(void) */

void __thiscall dFe_HIO_c::_dFe_HIO_c(dFe_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dFe_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_file_error {

void __sinit_d_file_error_cpp(void)

{
  ::dFe_HIO_c::dFe_HIO_c((dFe_HIO_c *)&g_feHIO);
  Runtime.PPCEABI.H::__register_global_object();
  FileErrProc = _4157;
  DAT_803912d8 = DAT_8039129c;
  DAT_803912dc = PTR_ProcWait_803912a0;
  DAT_803912e0 = _4158;
  DAT_803912e4 = DAT_803912a8;
  DAT_803912e8 = PTR_ShowMsgBoard_803912ac;
  DAT_803912ec = _4159;
  DAT_803912f0 = DAT_803912b4;
  DAT_803912f4 = PTR_HideMsgBoard_803912b8;
  DAT_803912f8 = _4160;
  DAT_803912fc = DAT_803912c0;
  DAT_80391300 = PTR_msgDispWait_803912c4;
  DAT_80391304 = _4161;
  DAT_80391308 = DAT_803912cc;
  DAT_8039130c = PTR_yesNoSelectWait_803912d0;
  return;
}

