#include <d_name.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_ext.h>
#include <m_Do_hostIO.h>
#include <d_name.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DTextBox.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dNm_HIO_c.h>
#include <dDlst_NameIN_c.h>
#include <dName_c.h>


namespace d_name {
}

namespace d_name {
undefined g_nmHIO;
}

/* __thiscall dNm_HIO_c::dNm_HIO_c(void) */

void __thiscall dNm_HIO_c::dNm_HIO_c(dNm_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined2 *)(this + 0x42) = 0xff6a;
  *(undefined2 *)(this + 0x44) = 0x15e;
  *(undefined2 *)(this + 0x46) = 0x1ea;
  *(undefined2 *)(this + 0x48) = 0x78;
  this[6] = (dNm_HIO_c)0x6;
  this[7] = (dNm_HIO_c)0x6;
  this[8] = (dNm_HIO_c)0x6;
  this[9] = (dNm_HIO_c)0x6;
  this[10] = (dNm_HIO_c)0x6;
  this[0xb] = (dNm_HIO_c)0x6;
  this[0xc] = (dNm_HIO_c)0x6;
  this[0xd] = (dNm_HIO_c)0x6;
  this[0xe] = (dNm_HIO_c)0x0;
  this[0xf] = (dNm_HIO_c)0x0;
  this[0x10] = (dNm_HIO_c)0x0;
  this[0x11] = (dNm_HIO_c)0x0;
  this[0x12] = (dNm_HIO_c)0x2;
  this[0x13] = (dNm_HIO_c)0x4;
  this[0x14] = (dNm_HIO_c)0x4;
  this[0x15] = (dNm_HIO_c)0x6;
  this[0x1f] = (dNm_HIO_c)0xe;
  this[0x20] = (dNm_HIO_c)0x8c;
  this[0x21] = (dNm_HIO_c)0x46;
  this[0x1b] = (dNm_HIO_c)0xf;
  this[0x1d] = (dNm_HIO_c)0xff;
  this[0x1e] = (dNm_HIO_c)0x40;
  this[0x1c] = (dNm_HIO_c)0x1f;
  *(undefined2 *)(this + 0x28) = 0;
  *(undefined2 *)(this + 0x26) = 0;
  this[0x16] = (dNm_HIO_c)0x7;
  this[0x17] = (dNm_HIO_c)0xa0;
  this[0x18] = (dNm_HIO_c)0x50;
  this[0x19] = (dNm_HIO_c)0xe;
  this[0x1a] = (dNm_HIO_c)0x0;
  *(undefined2 *)(this + 0x2a) = 0;
  *(undefined2 *)(this + 0x2c) = 1;
  *(undefined2 *)(this + 0x2e) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x32) = 0;
  *(undefined2 *)(this + 0x34) = 0;
  *(undefined2 *)(this + 0x36) = 0;
  *(undefined2 *)(this + 0x38) = 0xffff;
  *(undefined2 *)(this + 0x3a) = 0xffff;
  *(undefined2 *)(this + 0x3c) = 0;
  *(undefined2 *)(this + 0x3e) = 0;
  *(undefined2 *)(this + 0x40) = 0;
  this[0x23] = (dNm_HIO_c)0x5;
  this[0x22] = (dNm_HIO_c)0x14;
  this[5] = (dNm_HIO_c)0x0;
  return;
}


/* __thiscall dName_c::_create(void) */

void __thiscall dName_c::_create(dName_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  JUTFont *pJVar2;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_name::_4034;
    local_18.mTL.y = d_name::_4034;
    local_18.mBR.x = d_name::_4035;
    local_18.mBR.y = d_name::_4036;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0xc) = this_00;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_name.cpp",0xd4,"nameIn.NameInScr != 0");
    m_Do_printf::OSPanic("d_name.cpp",0xd4,&DAT_803620e9);
  }
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_name::_4037,d_name::_4038,0,0x2000);
  }
  *(STControl **)(this + 0x28fc) = this_01;
  if (*(int *)(this + 0x28fc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_name.cpp",0xd8,"stick != 0");
    m_Do_printf::OSPanic("d_name.cpp",0xd8,&DAT_803620e9);
  }
  STControl::setWaitParm(*(STControl **)(this + 0x28fc),5,2,3,2,d_name::_4037,d_name::_4038,0,0x800)
  ;
  *(JKRArchive **)(this + 4) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpNameResArchive;
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"name_input.blo",*(JKRArchive **)(this + 4));
  pJVar2 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0x10) = pJVar2;
  if (*(int *)(this + 0x10) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_name.cpp",0xe2,"nameIn.font != 0");
    m_Do_printf::OSPanic("d_name.cpp",0xe2,&DAT_803620e9);
  }
  DAT_803e6f80 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"名前登録画面",
                            (JORReflexible *)&d_name::g_nmHIO);
  screenSet(this);
  this[0x2ad0] = (dName_c)0x0;
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dName_c::initial(void) */

void __thiscall dName_c::initial(dName_c *this)

{
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dName_c::_delete(void) */

void __thiscall dName_c::_delete(dName_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  m_Do_ext::mDoExt_removeMesgFont();
  JKernel::operator_delete(*(JKRHeap **)(this + 0x28fc));
  (**(code **)(**(int **)(this + 4) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6f80);
  return;
}


/* __thiscall dName_c::_move(void) */

void __thiscall dName_c::_move(dName_c *this)

{
  NameInMain(this);
  return;
}


/* __thiscall dName_c::nameCheck(void) */

int __thiscall dName_c::nameCheck(dName_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 7;
  iVar1 = 0x38;
  iVar3 = 8;
  do {
    if (*(int *)(this + iVar1 + 0x2a74) != 0x20) {
      return iVar2 + 1;
    }
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + -8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}


/* __thiscall dName_c::playNameSet(int) */

void __thiscall dName_c::playNameSet(dName_c *this,int param_1)

{
  dName_c *pdVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(this + 0x2a5c);
  iVar2 = 0;
  if (0 < param_1) {
    do {
      pdVar1 = this + iVar2;
      if (pdVar1[0x2a72] == (dName_c)0x2) {
        *(char *)puVar3 = (char)*(undefined4 *)(pdVar1 + 0x2a74);
        puVar3 = (undefined2 *)((int)puVar3 + 1);
      }
      else {
        *puVar3 = (short)*(undefined4 *)(pdVar1 + 0x2a74);
        puVar3 = puVar3 + 1;
      }
      iVar2 = iVar2 + 8;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  *(undefined *)puVar3 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dName_c::_open(void) */

undefined4 __thiscall dName_c::_open(dName_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  
  iVar1 = PaneTranceBase0(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8c,DAT_803e6f84,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) -
                                 d_name::_4113),d_name::_4034,'\x01',0);
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8a,DAT_803e6f82,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fbe ^ 0x80000000) -
                                 d_name::_4113),d_name::_4034,'\x01',0);
  iVar3 = PaneTranceName(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8b,DAT_803e6f83,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc0 ^ 0x80000000) -
                                d_name::_4113),d_name::_4034,'\x01',0);
  iVar4 = PaneTranceBase(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8c,DAT_803e6f84,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) -
                                d_name::_4113),d_name::_4034,'\x01',0);
  iVar5 = PaneTranceKata(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8e,DAT_803e6f86,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),d_name::_4034,'\x01',0);
  iVar6 = PaneTranceHira(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8d,DAT_803e6f85,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),d_name::_4034,'\x01',0);
  iVar7 = PaneTranceEisu(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8f,DAT_803e6f87,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),d_name::_4034,'\x01',0);
  iVar8 = PaneTranceArrow(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f90,DAT_803e6f88,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                 d_name::_4113),d_name::_4034,'\x01',0);
  iVar9 = PaneTranceEnd(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f91,DAT_803e6f91,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                               d_name::_4113),d_name::_4034,'\x01',0);
  *(short *)(this + 0x2910) = *(short *)(this + 0x2910) + 1;
  if ((((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && ((iVar4 == 1 && (iVar5 == 1)))) &&
      ((iVar6 == 1 && ((iVar7 == 1 && (iVar8 == 1)))))) && (iVar9 == 1)) {
    *(undefined2 *)(this + 0x2910) = 0;
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  return uVar10;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dName_c::_close(void) */

undefined4 __thiscall dName_c::_close(dName_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  
  iVar1 = PaneTranceBase0(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8c,DAT_803e6f84,
                          d_name::_4034,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) -
                                 d_name::_4113),'\0',1);
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8a,DAT_803e6f82,
                          d_name::_4034,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fbe ^ 0x80000000) -
                                 d_name::_4113),'\0',1);
  iVar3 = PaneTranceName(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8b,DAT_803e6f83,
                         d_name::_4034,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc0 ^ 0x80000000) -
                                d_name::_4113),'\0',1);
  iVar4 = PaneTranceBase(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8c,DAT_803e6f84,
                         d_name::_4034,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) -
                                d_name::_4113),'\0',1);
  iVar5 = PaneTranceKata(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8e,DAT_803e6f86,
                         d_name::_4034,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),'\0',1);
  iVar6 = PaneTranceHira(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8d,DAT_803e6f85,
                         d_name::_4034,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),'\0',1);
  iVar7 = PaneTranceEisu(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f8f,DAT_803e6f87,
                         d_name::_4034,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                d_name::_4113),'\0',1);
  iVar8 = PaneTranceArrow(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f90,DAT_803e6f88,
                          d_name::_4034,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                                 d_name::_4113),'\0',1);
  iVar9 = PaneTranceEnd(this,*(short *)(this + 0x2910) - (ushort)DAT_803e6f91,DAT_803e6f91,
                        d_name::_4034,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                               d_name::_4113),'\0',1);
  *(short *)(this + 0x2910) = *(short *)(this + 0x2910) + 1;
  if ((((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && ((iVar4 == 1 && (iVar5 == 1)))) &&
      ((iVar6 == 1 && ((iVar7 == 1 && (iVar8 == 1)))))) && (iVar9 == 1)) {
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  return uVar10;
}


/* __thiscall dName_c::NameInMain(void) */

void __thiscall dName_c::NameInMain(dName_c *this)

{
  int iVar1;
  int iVar2;
  
  STControl::checkTrigger(*(STControl **)(this + 0x28fc));
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_name::SelProc + (uint)(byte)this[0x2903] * 3),this,&DAT_80390000);
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 < '\0') {
      if (this[0x2907] != (dName_c)0x0) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8a0,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                   d_name::_4201,d_name::_4201,0);
        this[0x2907] = (dName_c)((char)this[0x2907] + -1);
        nameCursorMove(this);
      }
    }
    else {
      if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
        if (this[0x2907] == (dName_c)0x0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                     d_name::_4201,d_name::_4201,0);
          *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
          this[0x2903] = (dName_c)0x3;
          this[0x290b] = (dName_c)0x2;
        }
        else {
          backSpace(this);
        }
      }
      else {
        if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0) &&
            (this[0x2903] != (dName_c)0x2)) &&
           ((this[0x2903] != (dName_c)0x1 || (this[0x2904] != (dName_c)0x4)))) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                     d_name::_4201,d_name::_4201,0);
          this[0x2903] = (dName_c)0x1;
          this[0x2904] = (dName_c)0x4;
          menuCursorMove(this);
          iVar1 = 0;
          iVar2 = 3;
          do {
            *(undefined *)(*(int *)(this + iVar1 + 0x8d4) + 0xaa) = 0;
            iVar1 = iVar1 + 0x38;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 1;
          selectCursorMove(this);
        }
      }
    }
  }
  else {
    if (this[0x2907] != (dName_c)0x8) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8a0,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                 d_name::_4201,d_name::_4201,0);
      this[0x2907] = (dName_c)((char)this[0x2907] + '\x01');
      nameCursorMove(this);
    }
  }
  nameCursorAnime(this);
  return;
}


/* __thiscall dName_c::nameCursorAnime(void) */

void __thiscall dName_c::nameCursorAnime(dName_c *this)

{
  undefined4 uVar1;
  uint uVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6f9b,(int)*(short *)(this + 0x1c82),0)
  ;
  if (this[0x2906] != (dName_c)0x0) {
    dVar3 = (double)(float)((double)d_name::_4200 - dVar3);
  }
  uVar2 = (uint)DAT_803e6f9a;
  uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      DAT_803e6f99 - uVar2 ^
                                                                      0x80000000) - d_name::_4113) *
                                    dVar3));
  this[0x1c81] = SUB41((int)((float)((double)CONCAT44(0x43300000,uVar2) - d_name::_4214) +
                            (float)((double)CONCAT44(0x43300000,uVar1) - d_name::_4214)),0);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1c4c));
  if (*(short *)(this + 0x1c82) == 0) {
    this[0x2906] = (dName_c)((byte)this[0x2906] ^ 1);
    *(ushort *)(this + 0x1c82) = (ushort)DAT_803e6f97;
  }
  else {
    *(short *)(this + 0x1c82) = *(short *)(this + 0x1c82) + -1;
  }
  return;
}


/* __thiscall dName_c::EndWait(void) */

void __thiscall dName_c::EndWait(dName_c *this)

{
  return;
}


/* __thiscall dName_c::MojiSelect(void) */

void __thiscall dName_c::MojiSelect(dName_c *this)

{
  char cVar1;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0x28fc));
    if (cVar1 == '\0') {
      cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0x28fc));
      if (cVar1 != '\0') {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                   d_name::_4201,d_name::_4201,0);
        if (this[0x2900] == (dName_c)0x0) {
          this[0x2900] = (dName_c)0xc;
        }
        else {
          this[0x2900] = (dName_c)((char)this[0x2900] + -1);
        }
        selectCursorMove(this);
      }
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                 d_name::_4201,d_name::_4201,0);
      this[0x2900] = (dName_c)((char)this[0x2900] + '\x01');
      if (0xc < (byte)this[0x2900]) {
        this[0x2900] = (dName_c)0x0;
      }
      selectCursorMove(this);
    }
  }
  else {
    selectMojiSet(this);
  }
  cVar1 = STControl::checkUpTrigger(*(STControl **)(this + 0x28fc));
  if (cVar1 == '\0') {
    cVar1 = STControl::checkDownTrigger(*(STControl **)(this + 0x28fc));
    if (cVar1 != '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                 d_name::_4201,d_name::_4201,0);
      this[0x2901] = (dName_c)((char)this[0x2901] + '\x01');
      if (4 < (byte)this[0x2901]) {
        this[0x2901] = (dName_c)0x4;
        this[0x2903] = (dName_c)0x1;
        menuCursorPosSet(this);
      }
      selectCursorMove(this);
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
               d_name::_4201,d_name::_4201,0);
    if (this[0x2901] == (dName_c)0x0) {
      this[0x2903] = (dName_c)0x1;
      menuCursorPosSet(this);
    }
    else {
      this[0x2901] = (dName_c)((char)this[0x2901] + -1);
    }
    selectCursorMove(this);
  }
  selectCursorAnime(this);
  return;
}


/* __thiscall dName_c::mojiChange(unsigned char) */

undefined4 __thiscall dName_c::mojiChange(dName_c *this,uchar param_1)

{
  dName_c dVar1;
  dName_c dVar2;
  uint uVar3;
  undefined4 uVar4;
  dName_c *pdVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  pdVar5 = this + (uint)param_1 * 8;
  if (((pdVar5[0x2a73] == (dName_c)0x0) || (dVar1 = pdVar5[0x2a72], dVar1 == (dName_c)0x2)) ||
     (uVar3 = *(uint *)(pdVar5 + 0x2a74), uVar3 == 0x8140)) {
    return 0;
  }
  dVar2 = pdVar5[0x2a70];
  if (((dVar2 == (dName_c)0x4) || (dVar2 == (dName_c)0x6)) || (dVar2 == (dName_c)0x8)) {
LAB_80216f78:
    uVar4 = 0;
  }
  else {
    switch(dVar2) {
    case (dName_c)0x0:
    case (dName_c)0xa:
      if (((uVar3 == 0x8345) || (uVar3 == 0x8344)) || (uVar3 == 0x8394)) {
        *(int *)(pdVar5 + 0x2a74) = *(int *)(pdVar5 + 0x2a74) + 1;
        if (*(int *)(pdVar5 + 0x2a74) == 0x8346) {
          *(undefined4 *)(pdVar5 + 0x2a74) = 0x8394;
        }
        if (*(int *)(pdVar5 + 0x2a74) == 0x8395) {
          *(undefined4 *)(pdVar5 + 0x2a74) = 0x8344;
        }
      }
      else {
        iVar7 = 0x829f;
        if (dVar1 != (dName_c)0x0) {
          iVar7 = 0x8340;
        }
        uVar6 = uVar3 - iVar7 >> 0x1f;
        if ((uVar3 - iVar7 & 1 ^ uVar6) == uVar6) {
          *(int *)(pdVar5 + 0x2a74) = *(int *)(pdVar5 + 0x2a74) + 1;
        }
        else {
          *(int *)(pdVar5 + 0x2a74) = *(int *)(pdVar5 + 0x2a74) + -1;
        }
      }
      break;
    case (dName_c)0x1:
      iVar7 = 0x82a9;
      if (dVar1 != (dName_c)0x0) {
        iVar7 = 0x834a;
      }
      iVar8 = (int)(uVar3 - iVar7) >> 0x1f;
      iVar8 = (uVar3 - iVar7 & 1 ^ -iVar8) + iVar8;
      *(uint *)(pdVar5 + 0x2a74) = (iVar8 + 1U & 1) + (uVar3 - iVar8);
      break;
    case (dName_c)0x2:
      iVar7 = 0x82b3;
      if (dVar1 != (dName_c)0x0) {
        iVar7 = 0x8354;
      }
      iVar8 = (int)(uVar3 - iVar7) >> 0x1f;
      iVar8 = (uVar3 - iVar7 & 1 ^ -iVar8) + iVar8;
      *(uint *)(pdVar5 + 0x2a74) = (iVar8 + 1U & 1) + (uVar3 - iVar8);
      break;
    case (dName_c)0x3:
    case (dName_c)0xc:
      if (uVar3 != 0x815b) {
        uVar6 = 0x82c0;
        if (dVar1 != (dName_c)0x0) {
          uVar6 = 0x8361;
        }
        if (uVar6 < uVar3) {
          uVar6 = 0x82c7;
          if (dVar1 != (dName_c)0x0) {
            uVar6 = 0x8368;
          }
          if (uVar3 <= uVar6) {
            uVar6 = 0x82c4;
            if (dVar1 != (dName_c)0x0) {
              uVar6 = 0x8365;
            }
            if (uVar6 <= uVar3) {
              iVar7 = 0x82c4;
              if (dVar1 != (dName_c)0x0) {
                iVar7 = 0x8365;
              }
              iVar8 = (int)(uVar3 - iVar7) >> 0x1f;
              iVar8 = (uVar3 - iVar7 & 1 ^ -iVar8) + iVar8;
              *(uint *)(pdVar5 + 0x2a74) = (iVar8 + 1U & 1) + (uVar3 - iVar8);
              break;
            }
          }
          iVar7 = 0x82c1;
          if (dVar1 != (dName_c)0x0) {
            iVar7 = 0x8362;
          }
          iVar7 = (int)(uVar3 - iVar7) % 3;
          iVar8 = iVar7 + 1;
          if (2 < iVar8) {
            iVar8 = 0;
          }
          *(uint *)(pdVar5 + 0x2a74) = iVar8 + (uVar3 - iVar7);
        }
        else {
          iVar7 = 0x82bd;
          if (dVar1 != (dName_c)0x0) {
            iVar7 = 0x835e;
          }
          iVar8 = (int)(uVar3 - iVar7) >> 0x1f;
          iVar8 = (uVar3 - iVar7 & 1 ^ -iVar8) + iVar8;
          *(uint *)(pdVar5 + 0x2a74) = (iVar8 + 1U & 1) + (uVar3 - iVar8);
        }
      }
      break;
    case (dName_c)0x4:
    case (dName_c)0x6:
    case (dName_c)0x8:
    case (dName_c)0x9:
      break;
    case (dName_c)0x5:
      iVar7 = 0x82cd;
      if (dVar1 != (dName_c)0x0) {
        iVar7 = 0x836e;
      }
      iVar7 = (int)(uVar3 - iVar7) % 3;
      iVar8 = iVar7 + 1;
      if (2 < iVar8) {
        iVar8 = 0;
      }
      *(uint *)(pdVar5 + 0x2a74) = iVar8 + (uVar3 - iVar7);
      break;
    case (dName_c)0x7:
    case (dName_c)0xb:
      iVar7 = 0x82e1;
      if (dVar1 != (dName_c)0x0) {
        iVar7 = 0x8383;
      }
      iVar8 = (int)(uVar3 - iVar7) >> 0x1f;
      iVar8 = (uVar3 - iVar7 & 1 ^ -iVar8) + iVar8;
      *(uint *)(pdVar5 + 0x2a74) = (iVar8 + 1U & 1) + (uVar3 - iVar8);
      break;
    default:
      goto LAB_80216f78;
    }
    setNameText(this);
    uVar4 = 1;
  }
  return uVar4;
}


/* __thiscall dName_c::selectMojiSet(void) */

void __thiscall dName_c::selectMojiSet(dName_c *this)

{
  int iVar1;
  
  iVar1 = getMoji(this);
  setMoji(this,iVar1);
  setNameText(this);
  nameCursorMove(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80217300) */
/* __thiscall dName_c::getMoji(void) */

uint __thiscall dName_c::getMoji(dName_c *this)

{
  dName_c dVar1;
  byte bVar2;
  J2DTextBox **ppJVar3;
  ushort *puVar4;
  uint uVar5;
  
  dVar1 = this[0x2902];
  if (dVar1 == (dName_c)0x1) {
    ppJVar3 = (J2DTextBox **)(this + (uint)(byte)this[0x2900] * 0x38 + 0x324);
  }
  else {
    if (dVar1 == (dName_c)0x0) {
      ppJVar3 = (J2DTextBox **)(this + (uint)(byte)this[0x2900] * 0x38 + 0x5fc);
    }
    else {
      ppJVar3 = (J2DTextBox **)this;
      if ((byte)dVar1 < 3) {
        ppJVar3 = (J2DTextBox **)(this + (uint)(byte)this[0x2900] * 0x38 + 0x4c);
      }
    }
  }
  puVar4 = (ushort *)J2DTextBox::getStringPtr(*ppJVar3);
  uVar5 = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        bVar2 = *(byte *)puVar4;
        if (bVar2 == 0) {
          return 0xffffffff;
        }
        if ((int)(char)bVar2 != 10) break;
        puVar4 = (ushort *)((int)puVar4 + 1);
      }
      if (((int)(uint)*(byte *)puVar4 >> 4 != 8) && ((int)(uint)*(byte *)puVar4 >> 4 != 9)) break;
      if (uVar5 == (byte)this[0x2901]) {
        return (uint)*puVar4;
      }
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 + 1;
    }
    if (uVar5 == (byte)this[0x2901]) break;
    puVar4 = (ushort *)((int)puVar4 + 1);
    uVar5 = uVar5 + 1;
  }
  return (int)(char)bVar2;
}


/* __thiscall dName_c::setMoji(int) */

void __thiscall dName_c::setMoji(dName_c *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  dName_c *pdVar4;
  uint uVar5;
  
  if ((this[0x2907] == (dName_c)0x8) || (iVar3 = nameCheck(this), iVar3 == 8)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x906,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
               d_name::_4201,d_name::_4201,0);
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89d,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
               d_name::_4201,d_name::_4201,0);
    bVar1 = false;
    uVar5 = (uint)(byte)this[0x2907];
    iVar3 = uVar5 << 3;
    iVar2 = 8 - uVar5;
    if (uVar5 < 8) {
      do {
        if (*(int *)(this + iVar3 + 0x2a74) != 0x20) {
          bVar1 = true;
          break;
        }
        iVar3 = iVar3 + 8;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (bVar1) {
      if (*(int *)(this + 0x2aac) == 0x20) {
        iVar3 = 0x30;
        for (iVar2 = 6; (int)(uint)(byte)this[0x2907] <= iVar2; iVar2 = iVar2 + -1) {
          pdVar4 = this + iVar3;
          pdVar4[0x2a78] = pdVar4[0x2a70];
          pdVar4[0x2a79] = pdVar4[0x2a71];
          pdVar4[0x2a7a] = pdVar4[0x2a72];
          pdVar4[0x2a7b] = pdVar4[0x2a73];
          *(undefined4 *)(pdVar4 + 0x2a7c) = *(undefined4 *)(pdVar4 + 0x2a74);
          iVar3 = iVar3 + -8;
        }
        this[(uint)(byte)this[0x2907] * 8 + 0x2a70] = this[0x2900];
        this[(uint)(byte)this[0x2907] * 8 + 0x2a71] = this[0x2901];
        this[(uint)(byte)this[0x2907] * 8 + 0x2a72] = this[0x2902];
        this[(uint)(byte)this[0x2907] * 8 + 0x2a73] = (dName_c)0x1;
        *(int *)(this + (uint)(byte)this[0x2907] * 8 + 0x2a74) = param_1;
        if (this[0x2907] != (dName_c)0x8) {
          this[0x2907] = (dName_c)((char)this[0x2907] + '\x01');
        }
      }
    }
    else {
      this[uVar5 * 8 + 0x2a70] = this[0x2900];
      this[(uint)(byte)this[0x2907] * 8 + 0x2a71] = this[0x2901];
      this[(uint)(byte)this[0x2907] * 8 + 0x2a72] = this[0x2902];
      this[(uint)(byte)this[0x2907] * 8 + 0x2a73] = (dName_c)0x1;
      *(int *)(this + (uint)(byte)this[0x2907] * 8 + 0x2a74) = param_1;
      if (this[0x2907] != (dName_c)0x8) {
        this[0x2907] = (dName_c)((char)this[0x2907] + '\x01');
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802177bc) */
/* WARNING: Removing unreachable block (ram,0x802177c4) */
/* __thiscall dName_c::setNameText(void) */

void __thiscall dName_c::setNameText(dName_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  dName_c *pdVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined uStack456;
  byte local_1c7;
  char acStack452 [324];
  double local_80;
  double local_78;
  undefined4 local_70;
  uint uStack108;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined4 local_50;
  uint uStack76;
  longlong local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar15 = (double)*(float *)(*(int *)(this + 0x1c14) + 0xe8);
  uVar8 = (**(code **)(**(int **)(this + 0x10) + 0x30))();
  local_80 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
  dVar14 = (double)(float)(dVar15 / (double)(float)(local_80 - d_name::_4113));
  iVar11 = 0;
  **(undefined **)(this + 0x2a58) = 0;
  iVar9 = 0;
  iVar1 = (int)dVar15;
  local_78 = (double)(longlong)iVar1;
  do {
    pdVar10 = this + iVar11;
    if (pdVar10[0x2a73] != (dName_c)0x0) {
      (**(code **)(**(int **)(this + 0x10) + 0x2c))
                (*(int **)(this + 0x10),*(undefined4 *)(pdVar10 + 0x2a74),&uStack456);
      local_78 = (double)CONCAT44(0x43300000,local_1c7 ^ 0x80000000);
      uStack108 = (uint)(d_name::_4581 * (float)((double)(float)(local_78 - d_name::_4113) * dVar14)
                        );
      local_80 = (double)(longlong)(int)uStack108;
      uStack108 = uStack108 ^ 0x80000000;
      local_70 = 0x43300000;
      fVar5 = (float)((double)CONCAT44(0x43300000,uStack108) - d_name::_4113) / d_name::_4581;
      dVar13 = (double)fVar5;
      fVar6 = (float)(dVar15 - dVar13) * d_name::_4038;
      dVar13 = dVar15 - (double)(float)(dVar13 + (double)fVar6);
      fVar4 = (float)dVar13;
      iVar7 = (int)dVar13;
      local_68 = (longlong)iVar7;
      iVar2 = (int)fVar6;
      local_60 = (longlong)iVar2;
      iVar3 = (int)fVar5;
      local_58 = (longlong)iVar3;
      iVar7 = iVar2 + iVar3 + iVar7;
      if (iVar7 < iVar1) {
        uStack76 = iVar1 - iVar7 ^ 0x80000000;
        local_50 = 0x43300000;
        fVar4 = fVar4 + (float)((double)CONCAT44(0x43300000,uStack76) - d_name::_4113);
      }
      local_48 = (longlong)(int)fVar4;
      MSL_C.PPCEABI.bare.H::sprintf
                (acStack452,"\x1bCR[%d]%c\x1bCR[%d]\x1bCR[%d]",iVar2,
                 *(uint *)(pdVar10 + 0x2a74) & 0xff,(int)fVar4,2);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x2a58),acStack452);
    }
    iVar9 = iVar9 + 1;
    iVar11 = iVar11 + 8;
  } while (iVar9 < 8);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  return;
}


/* __thiscall dName_c::nameCursorMove(void) */

void __thiscall dName_c::nameCursorMove(dName_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x1c4c),
             (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6fa4 ^ 0x80000000) -
                             d_name::_4113) +
                     (float)((double)CONCAT44(0x43300000,
                                              (uint)(byte)this[0x2907] * (uint)DAT_803e6f98 ^
                                              0x80000000) - d_name::_4113)),
             (double)(float)((double)CONCAT44(0x43300000,(int)DAT_803e6fa2 ^ 0x80000000) -
                            d_name::_4113));
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80217994) */
/* WARNING: Removing unreachable block (ram,0x8021798c) */
/* WARNING: Removing unreachable block (ram,0x8021799c) */
/* __thiscall dName_c::selectCursorMove(void) */

void __thiscall dName_c::selectCursorMove(dName_c *this)

{
  dName_c dVar1;
  dName_c *pdVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
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
  dVar1 = this[0x2900];
  if (9 < (byte)dVar1) {
    pdVar2 = this;
    if (9 < (byte)dVar1) {
      pdVar2 = (dName_c *)&DAT_00000004;
    }
  }
  else {
    pdVar2 = (dName_c *)&DAT_00000003;
  }
  pdVar2 = this + (int)pdVar2 * 4;
  pdVar2[0x2ab0] = dVar1;
  pdVar2[0x2ab1] = this[0x2901];
  pdVar2[0x2ab2] = (dName_c)0x1;
  iVar3 = 0;
  iVar4 = 0;
  dVar6 = (double)d_name::_4615;
  dVar8 = (double)d_name::_4616;
  dVar7 = d_name::_4214;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar4 + 0x8d4),
               (double)(float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                        (uint)(byte)this[0x2900]) -
                                                      dVar7)),
               (double)(float)(dVar8 * (double)(float)((double)CONCAT44(0x43300000,
                                                                        (uint)(byte)this[0x2901]) -
                                                      dVar7)));
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 2);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x944),
             (double)(d_name::_4615 *
                     (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x2900]) - d_name::_4214))
             ,(double)(d_name::_4616 *
                      (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x2901]) - d_name::_4214)
                      ));
  selectCursorTxtChange(this);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return;
}


/* __thiscall dName_c::selectCursorTxtChange(void) */

void __thiscall dName_c::selectCursorTxtChange(dName_c *this)

{
  int iVar1;
  
  iVar1 = getMoji(this);
  if (iVar1 < 0x100) {
    **(undefined **)(this + 0x2a54) = (char)iVar1;
    *(undefined *)(*(int *)(this + 0x2a54) + 1) = 0;
  }
  else {
    **(undefined **)(this + 0x2a54) = (char)((uint)iVar1 >> 8);
    *(char *)(*(int *)(this + 0x2a54) + 1) = (char)iVar1;
    *(undefined *)(*(int *)(this + 0x2a54) + 2) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dName_c::selectCursorAnime(void) */

void __thiscall dName_c::selectCursorAnime(dName_c *this)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  double dVar4;
  float local_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  local_68[3] = (float)d_name::_4629;
  local_58 = DAT_803620b4;
  local_54 = DAT_803620b8;
  local_68[0] = d_name::_4630;
  local_68[1] = (float)DAT_803620c0;
  local_68[2] = (float)DAT_803620c4;
  if (*(short *)(this + 0x90a) == 0) {
    *(ushort *)(this + 0x90a) = (ushort)DAT_803e6f92;
    uStack76 = (uint)(byte)this[0x2900];
    local_50 = 0x43300000;
    uStack68 = (int)*(short *)(&DAT_803e6fa6 + (uint)(byte)this[0x2905] * 2) ^ 0x80000000;
    local_48 = 0x43300000;
    uStack60 = (uint)(byte)this[0x2901];
    local_40 = 0x43300000;
    uStack52 = (int)*(short *)(&DAT_803e6fac + (uint)(byte)this[0x2905] * 2) ^ 0x80000000;
    local_38 = 0x43300000;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x8d4),
               (double)(d_name::_4615 *
                        (float)((double)CONCAT44(0x43300000,uStack76) - d_name::_4214) +
                       (float)((double)CONCAT44(0x43300000,uStack68) - d_name::_4113)),
               (double)(d_name::_4616 *
                        (float)((double)CONCAT44(0x43300000,uStack60) - d_name::_4214) +
                       (float)((double)CONCAT44(0x43300000,uStack52) - d_name::_4113)));
    uStack44 = (uint)(byte)this[0x2900];
    local_30 = 0x43300000;
    uStack36 = (int)*(short *)(&DAT_803e6fb2 + (uint)(byte)this[0x2905] * 2) ^ 0x80000000;
    local_28 = 0x43300000;
    uStack28 = (uint)(byte)this[0x2901];
    local_20 = 0x43300000;
    uStack20 = (int)*(short *)(&DAT_803e6fb8 + (uint)(byte)this[0x2905] * 2) ^ 0x80000000;
    local_18 = 0x43300000;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x90c),
               (double)(d_name::_4615 *
                        (float)((double)CONCAT44(0x43300000,uStack44) - d_name::_4214) +
                       (float)((double)CONCAT44(0x43300000,uStack36) - d_name::_4113)),
               (double)(d_name::_4616 *
                        (float)((double)CONCAT44(0x43300000,uStack28) - d_name::_4214) +
                       (float)((double)CONCAT44(0x43300000,uStack20) - d_name::_4113)));
    piVar2 = *(int **)(this + 0x8d4);
    piVar2[0x29] = (int)(*(float *)(this + 0x2ac8) + local_68[(byte)this[0x2905] + 3]);
    (**(code **)(*piVar2 + 0x20))();
    piVar2 = *(int **)(this + 0x90c);
    piVar2[0x29] = (int)(*(float *)(this + 0x2acc) + local_68[(byte)this[0x2905]]);
    (**(code **)(*piVar2 + 0x20))();
    this[0x2905] = (dName_c)((char)this[0x2905] + '\x01');
    if (2 < (byte)this[0x2905]) {
      this[0x2905] = (dName_c)0x0;
    }
  }
  else {
    *(short *)(this + 0x90a) = *(short *)(this + 0x90a) + -1;
  }
  if (*(short *)(this + 0x97a) == 0) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                              (DAT_803e6f95,(int)*(short *)(this + 0x942),0);
    bVar1 = DAT_803e6f94;
    if (this[0x2909] != (dName_c)0x0) {
      dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
    }
    uStack20 = (uint)DAT_803e6f93 - (uint)DAT_803e6f94 ^ 0x80000000;
    local_18 = 0x43300000;
    cVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                      ((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack20) -
                                                      d_name::_4113) * dVar4));
    this[0x909] = (dName_c)(bVar1 + cVar3);
    this[0x941] = (dName_c)(DAT_803e6f94 + cVar3);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x8d4));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x90c));
    if (*(short *)(this + 0x942) == 0) {
      *(ushort *)(this + 0x942) = (ushort)DAT_803e6f95;
      this[0x2909] = (dName_c)((byte)this[0x2909] ^ 1);
    }
    else {
      *(short *)(this + 0x942) = *(short *)(this + 0x942) + -1;
    }
    *(ushort *)(this + 0x97a) = (ushort)DAT_803e6f96;
  }
  else {
    *(short *)(this + 0x97a) = *(short *)(this + 0x97a) + -1;
  }
  return;
}


/* __thiscall dName_c::menuCursorPosSet(void) */

void __thiscall dName_c::menuCursorPosSet(dName_c *this)

{
  int iVar1;
  int iVar2;
  
  if (9 < (byte)this[0x2900]) {
    if (9 < (byte)this[0x2900]) {
      this[0x2904] = (dName_c)0x4;
    }
  }
  else {
    this[0x2904] = (dName_c)0x3;
  }
  menuCursorMove(this);
  iVar1 = 0;
  iVar2 = 3;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x8d4) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 1;
  return;
}


/* __thiscall dName_c::MenuSelect(void) */

void __thiscall dName_c::MenuSelect(dName_c *this)

{
  char cVar2;
  int iVar1;
  
  cVar2 = STControl::checkRightTrigger(*(STControl **)(this + 0x28fc));
  if (cVar2 == '\0') {
    cVar2 = STControl::checkLeftTrigger(*(STControl **)(this + 0x28fc));
    if (cVar2 == '\0') {
      cVar2 = STControl::checkUpTrigger(*(STControl **)(this + 0x28fc));
      if (cVar2 == '\0') {
        cVar2 = STControl::checkDownTrigger(*(STControl **)(this + 0x28fc));
        if (cVar2 == '\0') {
          if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
            if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0) &&
               (this[0x2904] == (dName_c)0x4)) {
              iVar1 = nameCheck(this);
              if (iVar1 == 0) {
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x906,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                           d_name::_4201,d_name::_4201,0);
              }
              else {
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,*(ulong *)(this + 0x2ae4),(cXyz *)0x0,0,0,
                           d_name::_4200,d_name::_4200,d_name::_4201,d_name::_4201,0);
              }
              *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
              *(undefined2 *)(this + 0x2910) = 0;
              this[0x2903] = (dName_c)0x2;
            }
          }
          else {
            if (this[0x2904] == (dName_c)0x4) {
              iVar1 = nameCheck(this);
              if (iVar1 == 0) {
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x906,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                           d_name::_4201,d_name::_4201,0);
              }
              else {
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,*(ulong *)(this + 0x2ae4),(cXyz *)0x0,0,0,
                           d_name::_4200,d_name::_4200,d_name::_4201,d_name::_4201,0);
              }
            }
            else {
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x89f,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                         d_name::_4201,d_name::_4201,0);
            }
            *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
            *(undefined2 *)(this + 0x2910) = 0;
            this[0x2903] = (dName_c)0x2;
          }
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                     d_name::_4201,d_name::_4201,0);
          this[0x2903] = (dName_c)0x0;
          selectCursorPosSet(this,0);
        }
      }
      else {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                   d_name::_4201,d_name::_4201,0);
        this[0x2903] = (dName_c)0x0;
        selectCursorPosSet(this,4);
      }
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                 d_name::_4201,d_name::_4201,0);
      if (this[0x2904] == (dName_c)0x3) {
        this[0x2904] = (dName_c)0x4;
      }
      else {
        this[0x2904] = (dName_c)((char)this[0x2904] + -1);
      }
      menuCursorMove(this);
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89c,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
               d_name::_4201,d_name::_4201,0);
    this[0x2904] = (dName_c)((char)this[0x2904] + '\x01');
    if (4 < (byte)this[0x2904]) {
      this[0x2904] = (dName_c)0x3;
    }
    menuCursorMove(this);
  }
  menuCursorAnime(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021815c) */
/* __thiscall dName_c::MenuButtonAnime(void) */

void __thiscall dName_c::MenuButtonAnime(dName_c *this)

{
  dName_c dVar1;
  double dVar2;
  
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6f9f,(int)*(short *)(this + 0x2910),5)
  ;
  *(float *)(this + 0x2ac4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e6f9e) - d_name::_4214) *
              dVar2);
  dVar1 = this[0x2904];
  if (dVar1 == (dName_c)0x2) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x13fc),(double)d_name::_4034,
               (double)*(float *)(this + 0x2ac4));
  }
  else {
    if ((byte)dVar1 < 2) {
      if (dVar1 == (dName_c)0x0) {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1afc),(double)d_name::_4034,
                   (double)*(float *)(this + 0x2ac4));
      }
      else {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x177c),(double)d_name::_4034,
                   (double)*(float *)(this + 0x2ac4));
      }
    }
    else {
      if (dVar1 == (dName_c)0x4) {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0xcfc),(double)d_name::_4034,
                   (double)*(float *)(this + 0x2ac4));
      }
      else {
        if ((byte)dVar1 < 4) {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x107c),(double)d_name::_4034,
                     (double)*(float *)(this + 0x2ac4));
        }
      }
    }
  }
  *(short *)(this + 0x2910) = *(short *)(this + 0x2910) + 1;
  if ((short)(ushort)DAT_803e6f9f < *(short *)(this + 0x2910)) {
    *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 1;
    menuAbtnSelect(this);
    this[0x2903] = (dName_c)0x1;
    *(undefined2 *)(this + 0x2910) = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80218254) */
/* __thiscall dName_c::menuAbtnSelect(void) */

void __thiscall dName_c::menuAbtnSelect(dName_c *this)

{
  dName_c dVar1;
  int iVar2;
  
  dVar1 = this[0x2904];
  if (dVar1 == (dName_c)0x3) {
    backSpace(this);
  }
  else {
    if ((byte)dVar1 < 3) {
      if (dVar1 != this[0x2902]) {
        this[0x290c] = this[0x2902];
        this[0x2902] = this[0x2904];
        mojiListChange(this,(uchar)this[0x290c]);
      }
    }
    else {
      if ((byte)dVar1 < 5) {
        iVar2 = nameCheck(this);
        if (iVar2 == 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x906,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
                     d_name::_4201,d_name::_4201,0);
        }
        else {
          *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
          playNameSet(this,iVar2);
          this[0x290b] = (dName_c)0x1;
        }
      }
    }
  }
  return;
}


/* __thiscall dName_c::backSpace(void) */

void __thiscall dName_c::backSpace(dName_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  dName_c *pdVar4;
  
  if (this[0x2907] != (dName_c)0x0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89e,(cXyz *)0x0,0,0,d_name::_4200,d_name::_4200,
               d_name::_4201,d_name::_4201,0);
    if (((byte)this[0x2907] == 8) && (*(int *)(this + 0x2aac) != 0x20)) {
      this[0x2aa8] = (dName_c)0x7;
      this[0x2aa9] = (dName_c)0x1;
      this[0x2aaa] = (dName_c)0x2;
      this[0x2aab] = (dName_c)0x1;
      *(undefined4 *)(this + 0x2aac) = 0x20;
    }
    else {
      iVar3 = (byte)this[0x2907] - 1;
      iVar2 = iVar3 * 8;
      iVar1 = 7 - iVar3;
      if (iVar3 < 7) {
        do {
          pdVar4 = this + iVar2;
          pdVar4[0x2a70] = pdVar4[0x2a78];
          pdVar4[0x2a71] = pdVar4[0x2a79];
          pdVar4[0x2a72] = pdVar4[0x2a7a];
          pdVar4[0x2a73] = pdVar4[0x2a7b];
          *(undefined4 *)(pdVar4 + 0x2a74) = *(undefined4 *)(pdVar4 + 0x2a7c);
          iVar2 = iVar2 + 8;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      this[0x2aa8] = (dName_c)0x7;
      this[0x2aa9] = (dName_c)0x1;
      this[0x2aaa] = (dName_c)0x2;
      this[0x2aab] = (dName_c)0x1;
      *(undefined4 *)(this + 0x2aac) = 0x20;
    }
    this[0x2907] = (dName_c)((char)this[0x2907] + -1);
    setNameText(this);
    nameCursorMove(this);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021844c) */
/* WARNING: Removing unreachable block (ram,0x80218488) */
/* __thiscall dName_c::mojiListChange(unsigned char) */

void __thiscall dName_c::mojiListChange(dName_c *this,uchar param_1)

{
  dName_c dVar1;
  int iVar2;
  dName_c *in_r8;
  dName_c *in_r9;
  int iVar3;
  
  if (param_1 == '\x01') {
    in_r8 = this + 0x324;
  }
  else {
    if (param_1 == '\0') {
      in_r8 = this + 0x5fc;
    }
    else {
      if (param_1 < 3) {
        in_r8 = this + 0x4c;
      }
    }
  }
  dVar1 = this[0x2902];
  if (dVar1 == (dName_c)0x1) {
    in_r9 = this + 0x324;
  }
  else {
    if (dVar1 == (dName_c)0x0) {
      in_r9 = this + 0x5fc;
    }
    else {
      if ((byte)dVar1 < 3) {
        in_r9 = this + 0x4c;
      }
    }
  }
  iVar2 = 0;
  iVar3 = 0xd;
  do {
    *(undefined *)(*(int *)(in_r8 + iVar2) + 0xaa) = 0;
    *(undefined *)(*(int *)(in_r9 + iVar2) + 0xaa) = 1;
    iVar2 = iVar2 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  selectCursorTxtChange(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802185a8) */
/* WARNING: Removing unreachable block (ram,0x802187f8) */
/* __thiscall dName_c::menuCursorMove(void) */

void __thiscall dName_c::menuCursorMove(dName_c *this)

{
  dName_c dVar1;
  dName_c *pdVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this[0x9b1] = (dName_c)0x0;
  *(undefined2 *)(this + 0x9b2) = 0;
  *(undefined2 *)(this + 0x9ea) = 0;
  this[0x2908] = (dName_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x97c));
  iVar3 = 0;
  iVar4 = 0;
  do {
    pdVar2 = this + iVar4;
    pdVar2[0x9b0] = *(dName_c *)(*(int *)(pdVar2 + 0x97c) + 0xac);
    *(undefined4 *)(pdVar2 + 0x988) = *(undefined4 *)(pdVar2 + 0x980);
    *(undefined4 *)(pdVar2 + 0x98c) = *(undefined4 *)(pdVar2 + 0x984);
    *(undefined4 *)(pdVar2 + 0x998) = *(undefined4 *)(pdVar2 + 0x990);
    *(undefined4 *)(pdVar2 + 0x99c) = *(undefined4 *)(pdVar2 + 0x994);
    *(undefined4 *)(pdVar2 + 0x9a8) = *(undefined4 *)(pdVar2 + 0x9a0);
    *(undefined4 *)(pdVar2 + 0x9ac) = *(undefined4 *)(pdVar2 + 0x9a4);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 0x97c));
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 5);
  dVar1 = this[0x2904];
  if (dVar1 == (dName_c)0x4) {
    *(byte *)(*(int *)(this + 0x9b4) + 0xdf) = *(byte *)(*(int *)(this + 0x9b4) + 0xdf) & 4 | 1;
    *(byte *)(*(int *)(this + 0xa24) + 0xdf) = *(byte *)(*(int *)(this + 0xa24) + 0xdf) & 4 | 2;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x97c),
               (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
               (double)d_name::_4888);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x9b4),
               (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
               (double)d_name::_4889);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0xa24),
               (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
               (double)d_name::_4889);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0xa5c),
               (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
               (double)d_name::_4889);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x9ec),
               (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
               (double)d_name::_4890);
    iVar3 = 1;
    iVar4 = 0x38;
    dVar6 = (double)d_name::_4038;
    do {
      pdVar2 = this + iVar4;
      *(undefined4 *)(pdVar2 + 0x998) = *(undefined4 *)(pdVar2 + 0x990);
      *(float *)(pdVar2 + 0x988) =
           *(float *)(pdVar2 + 0x998) - (float)((double)*(float *)(pdVar2 + 0x9a8) * dVar6);
      (**(code **)(**(int **)(pdVar2 + 0x97c) + 0x10))
                ((double)*(float *)(pdVar2 + 0x988),(double)*(float *)(pdVar2 + 0x98c));
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 5);
  }
  else {
    if ((byte)dVar1 < 4) {
      if ((byte)dVar1 < 2) {
        *(byte *)(*(int *)(this + 0x9b4) + 0xdf) = *(byte *)(*(int *)(this + 0x9b4) + 0xdf) & 4 | 3;
        *(byte *)(*(int *)(this + 0xa24) + 0xdf) = *(byte *)(*(int *)(this + 0xa24) + 0xdf) & 4;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x97c),
                   (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
                   (double)d_name::_4034);
      }
      else {
        *(byte *)(*(int *)(this + 0x9b4) + 0xdf) = *(byte *)(*(int *)(this + 0x9b4) + 0xdf) & 4 | 3;
        *(byte *)(*(int *)(this + 0xa24) + 0xdf) = *(byte *)(*(int *)(this + 0xa24) + 0xdf) & 4;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x97c),
                   (double)*(float *)(&d_name::PosData_4830 + (uint)(byte)this[0x2904] * 4),
                   (double)d_name::_4034);
        f_op_msg_mng::fopMsgM_paneScaleX((double)d_name::_4887,this + 0x9b4);
        f_op_msg_mng::fopMsgM_paneScaleX((double)d_name::_4887,this + 0xa24);
        f_op_msg_mng::fopMsgM_paneScaleX((double)d_name::_4887,this + 0xa5c);
        (**(code **)(**(int **)(this + 0x9b4) + 0x10))
                  ((double)*(float *)(this + 0x9a0),(double)*(float *)(this + 0x9c4));
        (**(code **)(**(int **)(this + 0xa24) + 0x10))
                  ((double)*(float *)(this + 0x9a0),(double)*(float *)(this + 0xa34));
        (**(code **)(**(int **)(this + 0xa5c) + 0x10))
                  ((double)*(float *)(this + 0x9a0),(double)*(float *)(this + 0xa6c));
        (**(code **)(**(int **)(this + 0x9ec) + 0x10))
                  ((double)(*(float *)(this + 0x9a0) + *(float *)(this + 0x9e0)),
                   (double)*(float *)(this + 0x9fc));
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021886c) */
/* __thiscall dName_c::selectCursorPosSet(int) */

void __thiscall dName_c::selectCursorPosSet(dName_c *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)(byte)this[0x2904];
  if ((this + uVar2 * 4)[0x2ab2] == (dName_c)0x1) {
    this[0x2900] = (this + uVar2 * 4)[0x2ab0];
    this[0x2901] = SUB41(param_1,0);
  }
  else {
    if (uVar2 == 2) {
      this[0x2900] = (dName_c)0x6;
    }
    else {
      if (uVar2 < 2) {
        if (uVar2 == 0) {
          this[0x2900] = (dName_c)0x0;
        }
        else {
          this[0x2900] = (dName_c)0x3;
        }
      }
      else {
        if (uVar2 == 4) {
          this[0x2900] = (dName_c)0xa;
        }
        else {
          if (uVar2 < 4) {
            this[0x2900] = (dName_c)0x8;
          }
        }
      }
    }
    this[0x2901] = SUB41(param_1,0);
    this[(uint)(byte)this[0x2904] * 4 + 0x2ab0] = this[0x2900];
    this[(uint)(byte)this[0x2904] * 4 + 0x2ab1] = this[0x2901];
    this[(uint)(byte)this[0x2904] * 4 + 0x2ab2] = (dName_c)0x1;
  }
  iVar1 = 0;
  iVar3 = 3;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x8d4) + 0xaa) = 1;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  selectCursorMove(this);
  *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dName_c::menuCursorAnime(void) */

void __thiscall dName_c::menuCursorAnime(dName_c *this)

{
  undefined4 uVar1;
  uint uVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6f9b,(int)*(short *)(this + 0x9b2),0);
  if (this[0x2908] != (dName_c)0x0) {
    dVar3 = (double)(float)((double)d_name::_4200 - dVar3);
  }
  uVar2 = (uint)DAT_803e6f9d;
  uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      DAT_803e6f9c - uVar2 ^
                                                                      0x80000000) - d_name::_4113) *
                                    dVar3));
  this[0x9b1] = SUB41((int)((float)((double)CONCAT44(0x43300000,uVar2) - d_name::_4214) +
                           (float)((double)CONCAT44(0x43300000,uVar1) - d_name::_4214)),0);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x97c));
  if (*(short *)(this + 0x9b2) == 0) {
    *(ushort *)(this + 0x9b2) = (ushort)DAT_803e6f9b;
    this[0x2908] = (dName_c)((byte)this[0x2908] ^ 1);
  }
  else {
    *(short *)(this + 0x9b2) = *(short *)(this + 0x9b2) + -1;
  }
  return;
}


/* __thiscall dName_c::_draw(void) */

void __thiscall dName_c::_draw(dName_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 8));
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* __thiscall dName_c::screenSet(void) */

void __thiscall dName_c::screenSet(dName_c *this)

{
  J2DScreen *pJVar1;
  undefined4 uVar2;
  ulong uVar3;
  ___ in_r5;
  int iVar4;
  int iVar5;
  dName_c *pdVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char acStack104 [32];
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63633030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x14),pJVar1);
  iVar8 = 0;
  iVar4 = 0;
  iVar5 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_Eisu_4940 + iVar5));
    pdVar6 = this + iVar4;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x4c),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_Kata_4941 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x324),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_Hira_4942 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x5fc),pJVar1);
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar6 + 0x4c),*(JUTFont **)(this + 0x10));
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar6 + 0x324),*(JUTFont **)(this + 0x10));
    J2DTextBox::setFont(*(J2DTextBox **)(pdVar6 + 0x5fc),*(JUTFont **)(this + 0x10));
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar8 < 0xd);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x64746c65);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x20ac),pJVar1);
  iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar4 == 0) {
    f_op_msg_mng::fopMsgM_messageGet(acStack104,0x28);
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x20ac),acStack104,in_r5);
  }
  else {
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x20ac),"Enter the password!",in_r5);
  }
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x68697261);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1894),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1894),*(JUTFont **)(this + 0x10));
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6b616e61);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1514),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1514),*(JUTFont **)(this + 0x10));
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x656e676c);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1194),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1194),*(JUTFont **)(this + 0x10));
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x79617a)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xe14),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x66696e)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xa94),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xa94),*(JUTFont **)(this + 0x10));
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6e616d65);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1c14),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1c14),*(JUTFont **)(this + 0x10));
  *(float *)(*(int *)(this + 0x1c14) + 0xe0) = d_name::_4034;
  iVar4 = 0;
  iVar5 = 0x140;
  do {
    this[iVar4 + 0x2914] = (dName_c)0x41;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  this[0x2a53] = (dName_c)0x0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x1c14),(char *)(this + 0x2914),in_r5);
  uVar2 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x1c14));
  *(undefined4 *)(this + 0x2a58) = uVar2;
  **(undefined **)(this + 0x2a58) = 0;
  if (*(int *)(this + 0x2a58) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_name.cpp",0x804,"pNameTxt != 0");
    m_Do_printf::OSPanic("d_name.cpp",0x804,&DAT_803620e9);
  }
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x31637531);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x8d4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x31637532);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x90c),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x346375)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x944),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x944),*(JUTFont **)(this + 0x10));
  uVar2 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x944));
  *(undefined4 *)(this + 0x2a54) = uVar2;
  if (*(int *)(this + 0x2a54) == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_name.cpp",0x80b,"pCurTxt != 0");
    m_Do_printf::OSPanic("d_name.cpp",0x80b,&DAT_803620e9);
  }
  this[0x909] = DAT_803e6f93;
  this[0x941] = DAT_803e6f94;
  *(ushort *)(this + 0x90a) = (ushort)DAT_803e6f92;
  *(ushort *)(this + 0x942) = (ushort)DAT_803e6f95;
  *(ushort *)(this + 0x97a) = (ushort)DAT_803e6f96;
  this[0x2909] = (dName_c)0x0;
  this[0x2905] = (dName_c)0x0;
  *(undefined4 *)(this + 0x2ac8) = *(undefined4 *)(*(int *)(this + 0x8d4) + 0xa4);
  *(undefined4 *)(this + 0x2acc) = *(undefined4 *)(*(int *)(this + 0x90c) + 0xa4);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x8d4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x90c));
  iVar8 = 0x32637531;
  iVar12 = 0x6e6b3531;
  iVar11 = 0x6e6b3431;
  iVar10 = 0x6e6b3331;
  iVar9 = 0x6e6b3231;
  iVar7 = 0x6e6b3131;
  iVar5 = 0;
  iVar13 = 0;
  iVar4 = 0;
  do {
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar8);
    pdVar6 = this + iVar4;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x97c),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar12)
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0xcfc),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar11)
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x107c),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar10)
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x13fc),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar9);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x177c),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar7);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x1afc),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_NameNt_4956 + iVar13))
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x1c84),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_MenuNmB_4957 + iVar13)
                       );
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x20e4),pJVar1);
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 1;
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 1;
    iVar7 = iVar7 + 1;
    iVar13 = iVar13 + 4;
    iVar4 = iVar4 + 0x38;
  } while (iVar5 < 5);
  iVar8 = 0;
  iVar4 = 0;
  iVar5 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_endB_4963 + iVar5));
    pdVar6 = this + iVar4;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0xacc),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_ArwB_4964 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0xe4c),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_EisuB_4965 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x11cc),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_KataB_4966 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x154c),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 0xc) + 0x30))
                       (*(int **)(this + 0xc),*(undefined4 *)((int)&d_name::l_HiraB_4967 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x18cc),pJVar1);
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar8 < 10);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x33637531);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1c4c),pJVar1);
  uStack68 = (int)DAT_803e6fa4 ^ 0x80000000;
  local_48 = 0x43300000;
  uStack60 = (int)DAT_803e6fa2 ^ 0x80000000;
  local_40 = 0x43300000;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x1c4c),
             (double)(float)((double)CONCAT44(0x43300000,uStack68) - d_name::_4113),
             (double)(float)((double)CONCAT44(0x43300000,uStack60) - d_name::_4113));
  this[0x2906] = (dName_c)0x0;
  *(ushort *)(this + 0x1c82) = (ushort)DAT_803e6f97;
  this[0x1c81] = DAT_803e6f99;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1c4c));
  iVar8 = 0x64303030;
  iVar7 = 0x646b3030;
  iVar9 = 0x63303030;
  iVar10 = 0x636b3030;
  iVar5 = 0;
  iVar4 = 0;
  do {
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar8);
    pdVar6 = this + iVar4;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x1d9c),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar7);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x1f24),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar9);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x21fc),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar10)
    ;
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(pdVar6 + 0x2384),pJVar1);
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 1;
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar5 < 7);
  iVar8 = 0x62303030;
  iVar7 = 0x626b3030;
  iVar5 = 0;
  iVar4 = 0;
  do {
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar8);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar4 + 0x250c),pJVar1);
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar7);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar4 + 0x2704),pJVar1);
    iVar5 = iVar5 + 1;
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar5 < 9);
  return;
}


/* __thiscall dName_c::paneTransInit(void) */

void __thiscall dName_c::paneTransInit(dName_c *this)

{
  *(undefined2 *)(this + 0x2910) = 0;
  PaneTranceBase0(this,*(short *)(this + 0x2910),DAT_803e6f84,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) -
                         d_name::_4113),d_name::_4034,'\x01',0);
  PaneTranceTitle(this,*(short *)(this + 0x2910),DAT_803e6f82,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fbe ^ 0x80000000) -
                         d_name::_4113),d_name::_4034,'\x01',0);
  PaneTranceName(this,*(short *)(this + 0x2910),DAT_803e6f83,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc0 ^ 0x80000000) - d_name::_4113
                        ),d_name::_4034,'\x01',0);
  PaneTranceBase(this,*(short *)(this + 0x2910),DAT_803e6f84,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc2 ^ 0x80000000) - d_name::_4113
                        ),d_name::_4034,'\x01',0);
  PaneTranceKata(this,*(short *)(this + 0x2910),DAT_803e6f85,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) - d_name::_4113
                        ),d_name::_4034,'\x01',0);
  PaneTranceHira(this,*(short *)(this + 0x2910),DAT_803e6f86,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) - d_name::_4113
                        ),d_name::_4034,'\x01',0);
  PaneTranceEisu(this,*(short *)(this + 0x2910),DAT_803e6f87,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) - d_name::_4113
                        ),d_name::_4034,'\x01',0);
  PaneTranceArrow(this,*(short *)(this + 0x2910),DAT_803e6f88,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) -
                         d_name::_4113),d_name::_4034,'\x01',0);
  PaneTranceEnd(this,*(short *)(this + 0x2910),DAT_803e6f89,
                (float)((double)CONCAT44(0x43300000,(int)DAT_803e6fc4 ^ 0x80000000) - d_name::_4113)
                ,d_name::_4034,'\x01',0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80219778) */
/* WARNING: Removing unreachable block (ram,0x80219770) */
/* WARNING: Removing unreachable block (ram,0x80219780) */
/* __thiscall dName_c::PaneTranceTitle(short,
                                       unsigned char,
                                       float,
                                       float,
                                       unsigned char,
                                       int) */

undefined4 __thiscall
dName_c::PaneTranceTitle
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar7;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_4;
  dVar7 = (double)param_3;
  uVar4 = 0;
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
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      dVar7 = (double)(float)(dVar7 + (double)(float)(dVar5 * (double)(float)(dVar6 - dVar7)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x20ac),(double)d_name::_4034,dVar7);
      iVar2 = 0;
      iVar3 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar3 + 0x20e4),(double)d_name::_4034,dVar7);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x38;
      } while (iVar2 < 5);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x21fc),(double)d_name::_4034,dVar7);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2384),(double)d_name::_4034,dVar7);
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar5 = (double)(float)((double)d_name::_4200 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x20ac),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x20ac));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x20e4),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x20e4));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x21fc),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2384),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x21fc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2384));
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802199cc) */
/* WARNING: Removing unreachable block (ram,0x802199c4) */
/* WARNING: Removing unreachable block (ram,0x802199d4) */
/* __thiscall dName_c::PaneTranceName(short,
                                      unsigned char,
                                      float,
                                      float,
                                      unsigned char,
                                      int) */

undefined4 __thiscall
dName_c::PaneTranceName
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar7;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_4;
  dVar7 = (double)param_3;
  uVar4 = 0;
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
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      dVar7 = (double)(float)(dVar7 + (double)(float)(dVar5 * (double)(float)(dVar6 - dVar7)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1c14),dVar7,(double)d_name::_4034);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1f24),dVar7,(double)d_name::_4034);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1c4c),
                 (double)((float)((double)(float)((double)CONCAT44(0x43300000,
                                                                   (int)DAT_803e6fa4 ^ 0x80000000) -
                                                 d_name::_4113) + dVar7) +
                         (float)((double)CONCAT44(0x43300000,
                                                  (uint)(byte)this[0x2907] * (uint)DAT_803e6f98 ^
                                                  0x80000000) - d_name::_4113)),
                 (double)(float)((double)CONCAT44(0x43300000,(int)DAT_803e6fa2 ^ 0x80000000) -
                                d_name::_4113));
      iVar2 = 0;
      iVar3 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar3 + 0x1c84),dVar7,(double)d_name::_4034);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x38;
      } while (iVar2 < 5);
      iVar2 = 0;
      iVar3 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar3 + 0x1d9c),dVar7,(double)d_name::_4034);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x38;
      } while (iVar2 < 7);
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar5 = (double)(float)((double)d_name::_4200 - dVar5);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1c14),(float)dVar5);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1f24),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1c14));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1f24));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1c4c),(float)dVar5);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1c4c));
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1c84),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1c84));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 5);
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1d9c),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1d9c));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 7);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x80219ab4) */
/* WARNING: Removing unreachable block (ram,0x80219aac) */
/* WARNING: Removing unreachable block (ram,0x80219abc) */
/* __thiscall dName_c::PaneTranceBase0(short,
                                       unsigned char,
                                       float,
                                       float,
                                       unsigned char,
                                       int) */

undefined4 __thiscall
dName_c::PaneTranceBase0
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x14),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x14),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x14));
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


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80219cdc) */
/* WARNING: Removing unreachable block (ram,0x80219b58) */
/* WARNING: Removing unreachable block (ram,0x80219cd4) */
/* WARNING: Removing unreachable block (ram,0x80219ce4) */
/* __thiscall dName_c::PaneTranceBase(short,
                                      unsigned char,
                                      float,
                                      float,
                                      unsigned char,
                                      int) */

undefined4 __thiscall
dName_c::PaneTranceBase
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  dName_c dVar1;
  undefined4 uVar2;
  undefined3 in_register_00000018;
  dName_c *unaff_r28;
  int iVar3;
  dName_c *pdVar4;
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
    uVar2 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar2 = 1;
    }
    else {
      dVar1 = this[0x2902];
      if (dVar1 == (dName_c)0x1) {
        unaff_r28 = this + 0x324;
      }
      else {
        if (dVar1 == (dName_c)0x0) {
          unaff_r28 = this + 0x5fc;
        }
        else {
          if ((byte)dVar1 < 3) {
            unaff_r28 = this + 0x4c;
          }
        }
      }
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar7 * (double)(float)(dVar8 - dVar9)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x250c),(double)d_name::_4034,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2704),(double)d_name::_4034,dVar9);
      iVar3 = 0;
      iVar5 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar5 + 0x8d4),(double)d_name::_4034,dVar9);
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 0x38;
      } while (iVar3 < 3);
      iVar3 = 0;
      iVar5 = 0;
      do {
        pdVar4 = this + iVar5;
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(pdVar4 + 0x5fc),(double)d_name::_4034,dVar9);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(pdVar4 + 0x324),(double)d_name::_4034,dVar9);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(pdVar4 + 0x4c),(double)d_name::_4034,dVar9);
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 0x38;
      } while (iVar3 < 0xd);
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar7 = (double)(float)((double)d_name::_4200 - dVar7);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x250c),(float)dVar7);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2704),(float)dVar7);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x250c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2704));
        iVar3 = 0;
        iVar5 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar5 + 0x8d4),(float)dVar7);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar5 + 0x8d4));
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 0x38;
        } while (iVar3 < 3);
        iVar3 = 0;
        iVar5 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(unaff_r28 + iVar5),(float)dVar7);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(unaff_r28 + iVar5));
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 0x38;
        } while (iVar3 < 0xd);
      }
      uVar2 = 0;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return uVar2;
}


/* WARNING: Removing unreachable block (ram,0x80219dec) */
/* WARNING: Removing unreachable block (ram,0x80219de4) */
/* WARNING: Removing unreachable block (ram,0x80219df4) */
/* __thiscall dName_c::PaneTranceHira(short,
                                      unsigned char,
                                      float,
                                      float,
                                      unsigned char,
                                      int) */

undefined4 __thiscall
dName_c::PaneTranceHira
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1afc),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1894),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1afc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x18cc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1894));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1afc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x18cc));
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


/* WARNING: Removing unreachable block (ram,0x80219efc) */
/* WARNING: Removing unreachable block (ram,0x80219ef4) */
/* WARNING: Removing unreachable block (ram,0x80219f04) */
/* __thiscall dName_c::PaneTranceKata(short,
                                      unsigned char,
                                      float,
                                      float,
                                      unsigned char,
                                      int) */

undefined4 __thiscall
dName_c::PaneTranceKata
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x177c),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1514),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x154c),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x177c),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1514));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x154c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x177c));
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


/* WARNING: Removing unreachable block (ram,0x8021a00c) */
/* WARNING: Removing unreachable block (ram,0x8021a004) */
/* WARNING: Removing unreachable block (ram,0x8021a014) */
/* __thiscall dName_c::PaneTranceEisu(short,
                                      unsigned char,
                                      float,
                                      float,
                                      unsigned char,
                                      int) */

undefined4 __thiscall
dName_c::PaneTranceEisu
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x13fc),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1194),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x11cc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x13fc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1194));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x11cc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x13fc));
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


/* WARNING: Removing unreachable block (ram,0x8021a11c) */
/* WARNING: Removing unreachable block (ram,0x8021a114) */
/* WARNING: Removing unreachable block (ram,0x8021a124) */
/* __thiscall dName_c::PaneTranceArrow(short,
                                       unsigned char,
                                       float,
                                       float,
                                       unsigned char,
                                       int) */

undefined4 __thiscall
dName_c::PaneTranceArrow
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x107c),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe14),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe4c),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x107c),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xe14));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xe4c));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x107c));
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


/* WARNING: Removing unreachable block (ram,0x8021a22c) */
/* WARNING: Removing unreachable block (ram,0x8021a224) */
/* WARNING: Removing unreachable block (ram,0x8021a234) */
/* __thiscall dName_c::PaneTranceEnd(short,
                                     unsigned char,
                                     float,
                                     float,
                                     unsigned char,
                                     int) */

undefined4 __thiscall
dName_c::PaneTranceEnd
          (dName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
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
  
  dVar5 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = 0;
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
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xcfc),(double)d_name::_4034,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_name::_4200 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xa94),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xacc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcfc),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xa94));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xacc));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcfc));
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


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dName_c::displayInit(void) */

void __thiscall dName_c::displayInit(dName_c *this)

{
  int iVar1;
  dName_c *pdVar2;
  int iVar3;
  
  this[0x290d] = (dName_c)0x1;
  iVar1 = 0;
  iVar3 = 5;
  do {
    this[iVar1 + 0x2ab2] = (dName_c)0x0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this[0x2900] = (dName_c)0x0;
  this[0x2901] = (dName_c)0x0;
  this[0x2ab0] = (dName_c)0x0;
  this[0x2ab1] = (dName_c)0x0;
  this[0x2ab2] = (dName_c)0x1;
  this[0x2907] = (dName_c)0x0;
  **(undefined **)(this + 0x2a58) = 0;
  iVar1 = 0;
  iVar3 = 8;
  do {
    pdVar2 = this + iVar1;
    pdVar2[0x2a70] = (dName_c)0x7;
    pdVar2[0x2a71] = (dName_c)0x1;
    pdVar2[0x2a72] = (dName_c)0x2;
    pdVar2[0x2a73] = (dName_c)0x1;
    *(undefined4 *)(pdVar2 + 0x2a74) = 0x20;
    iVar1 = iVar1 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2ae4) = 0x80d;
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 == 0) {
    *(undefined *)(*(int *)(this + 0x14) + 0xaa) = 0;
    if (this[0x2ad0] != (dName_c)0x0) {
      NameStrSet(this);
    }
    *(undefined4 *)(this + 0x2ae4) = 0x833;
  }
  this[0x2904] = (dName_c)0x3;
  this[0x2902] = (dName_c)0x2;
  iVar1 = 0;
  *(undefined *)(*(int *)(this + 0x1afc) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x177c) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0x13fc) + 0xaa) = 0;
  this[0x2903] = (dName_c)0x0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar2 + 0x5fc));
    f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar2 + 0x4c));
    f_op_msg_mng::fopMsgM_setInitAlpha((fopMsgM_pane_class *)(pdVar2 + 0x324));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0x5fc));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0x4c));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar2 + 0x324));
    *(undefined *)(*(int *)(pdVar2 + 0x5fc) + 0xaa) = 0;
    *(undefined *)(*(int *)(pdVar2 + 0x4c) + 0xaa) = 1;
    *(undefined *)(*(int *)(pdVar2 + 0x324) + 0xaa) = 0;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 0xd);
  *(undefined *)(*(int *)(this + 0x97c) + 0xaa) = 0;
  iVar1 = 0;
  iVar3 = 3;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x8d4) + 0xaa) = 1;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  selectCursorTxtChange(this);
  this[0x290b] = (dName_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dName_c::NameStrSet(void) */

void __thiscall dName_c::NameStrSet(dName_c *this)

{
  char cVar1;
  bool bVar2;
  ushort *puVar3;
  ushort *puVar4;
  char *pcVar5;
  dName_c dVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  dName_c dVar10;
  ushort *puVar11;
  dName_c *pdVar12;
  
  puVar11 = (ushort *)(this + 0x2ad0);
  dVar10 = (dName_c)0x0;
  iVar8 = 0;
  do {
    while( true ) {
      if (*(byte *)puVar11 == 0) {
        this[0x2907] = dVar10;
        setNameText(this);
        nameCursorMove(this);
        return;
      }
      if (((int)(uint)*(byte *)puVar11 >> 4 == 8) || ((int)(uint)*(byte *)puVar11 >> 4 == 9)) break;
      pdVar12 = this + iVar8;
      *(int *)(pdVar12 + 0x2a74) = (int)(char)*(byte *)puVar11;
      pdVar12[0x2a72] = (dName_c)0x2;
      bVar2 = false;
      iVar9 = 0;
      iVar7 = 0;
      do {
        if (bVar2) break;
        pcVar5 = (char *)J2DTextBox::getStringPtr(*(J2DTextBox **)(this + iVar7 + 0x4c));
        dVar6 = (dName_c)0x0;
        while (cVar1 = *pcVar5, cVar1 != '\0') {
          if (cVar1 == 10) {
            pcVar5 = pcVar5 + 1;
          }
          else {
            if ((int)cVar1 == *(int *)(pdVar12 + 0x2a74)) {
              pdVar12[0x2a70] = SUB41(iVar9,0);
              pdVar12[0x2a71] = dVar6;
              bVar2 = true;
              break;
            }
            dVar6 = (dName_c)((char)dVar6 + '\x01');
            pcVar5 = pcVar5 + 1;
          }
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0x38;
      } while (iVar9 < 0xd);
      puVar11 = (ushort *)((int)puVar11 + 1);
      dVar10 = (dName_c)((char)dVar10 + '\x01');
      iVar8 = iVar8 + 8;
    }
    pdVar12 = this + iVar8;
    *(uint *)(pdVar12 + 0x2a74) = (uint)*puVar11;
    bVar2 = false;
    iVar9 = 0;
    iVar7 = 0;
    do {
      if (bVar2) break;
      puVar3 = (ushort *)J2DTextBox::getStringPtr(*(J2DTextBox **)(this + iVar7 + 0x5fc));
      puVar4 = (ushort *)J2DTextBox::getStringPtr(*(J2DTextBox **)(this + iVar7 + 0x324));
      dVar6 = (dName_c)0x0;
      while( true ) {
        if (*(char *)puVar3 == '\0') break;
        if (*(char *)puVar3 == '\n') {
          puVar3 = (ushort *)((int)puVar3 + 1);
        }
        else {
          if ((uint)*puVar3 == *(uint *)(pdVar12 + 0x2a74)) {
            pdVar12[0x2a70] = SUB41(iVar9,0);
            pdVar12[0x2a71] = dVar6;
            pdVar12[0x2a72] = (dName_c)0x0;
            bVar2 = true;
            break;
          }
          dVar6 = (dName_c)((char)dVar6 + '\x01');
          puVar3 = puVar3 + 1;
        }
      }
      dVar6 = (dName_c)0x0;
      while (*(char *)puVar4 != '\0') {
        if (*(char *)puVar4 == '\n') {
          puVar4 = (ushort *)((int)puVar4 + 1);
        }
        else {
          if ((uint)*puVar4 == *(uint *)(pdVar12 + 0x2a74)) {
            pdVar12[0x2a70] = SUB41(iVar9,0);
            pdVar12[0x2a71] = dVar6;
            pdVar12[0x2a72] = (dName_c)0x1;
            bVar2 = true;
            break;
          }
          dVar6 = (dName_c)((char)dVar6 + '\x01');
          puVar4 = puVar4 + 1;
        }
      }
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 0x38;
    } while (iVar9 < 0xd);
    puVar11 = puVar11 + 1;
    dVar10 = (dName_c)((char)dVar10 + '\x01');
    iVar8 = iVar8 + 8;
  } while( true );
}


/* __thiscall dDlst_NameIN_c::draw(void) */

void __thiscall dDlst_NameIN_c::draw(dDlst_NameIN_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_name::_4034,d_name::_4034,&pCtx->parent);
  return;
}


/* __thiscall dNm_HIO_c::~dNm_HIO_c(void) */

void __thiscall dNm_HIO_c::_dNm_HIO_c(dNm_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dNm_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_name {

void __sinit_d_name_cpp(void)

{
  ::dNm_HIO_c::dNm_HIO_c((dNm_HIO_c *)&g_nmHIO);
  Runtime.PPCEABI.H::__register_global_object();
  SelProc = _4060;
  DAT_8039382c = DAT_803937fc;
  DAT_80393830 = PTR_MojiSelect_80393800;
  DAT_80393834 = _4061;
  DAT_80393838 = DAT_80393808;
  DAT_8039383c = PTR_MenuSelect_8039380c;
  DAT_80393840 = _4062;
  DAT_80393844 = DAT_80393814;
  DAT_80393848 = PTR_MenuButtonAnime_80393818;
  DAT_8039384c = _4063;
  DAT_80393850 = DAT_80393820;
  DAT_80393854 = PTR_EndWait_80393824;
  return;
}

