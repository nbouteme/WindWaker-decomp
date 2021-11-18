#include <d_file_select.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_ext.h>
#include <m_Do_hostIO.h>
#include <d_file_select.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_op_msg_mng.h>
#include <J2DGraph/J2DPicture.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_save.h>
#include <m_Do_MemCardRWmng.h>
#include <m_Do_MemCard.h>
#include <J2DGraph/J2DTextBox.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <os/OSTime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_FileSel_c.h>
#include <dFile_select_c.h>
#include <dFs_HIO_c.h>


namespace d_file_select {
}

namespace d_file_select {
undefined g_fsHIO;
}

/* __thiscall dFs_HIO_c::dFs_HIO_c(void) */

void __thiscall dFs_HIO_c::dFs_HIO_c(dFs_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[7] = (dFs_HIO_c)0x1;
  this[0xb] = (dFs_HIO_c)0xa;
  this[8] = (dFs_HIO_c)0x6;
  this[9] = (dFs_HIO_c)0xa;
  *(undefined2 *)(this + 0x48) = 0xff6a;
  this[0xc] = (dFs_HIO_c)0x6;
  this[0xd] = (dFs_HIO_c)0x6;
  this[0xe] = (dFs_HIO_c)0x6;
  this[0xf] = (dFs_HIO_c)0x0;
  this[0x10] = (dFs_HIO_c)0x6;
  *(undefined2 *)(this + 0x18) = 0xff06;
  this[0x14] = (dFs_HIO_c)0xa;
  this[0x11] = (dFs_HIO_c)0x6;
  *(undefined2 *)(this + 0x1a) = 0xfa;
  this[0x15] = (dFs_HIO_c)0x5;
  this[0x12] = (dFs_HIO_c)0x6;
  *(undefined2 *)(this + 0x1c) = 0xfa;
  this[0x16] = (dFs_HIO_c)0x0;
  this[0x13] = (dFs_HIO_c)0x6;
  *(undefined2 *)(this + 0x1e) = 0xfa;
  this[0x21] = (dFs_HIO_c)0x0;
  this[0x20] = (dFs_HIO_c)0x0;
  this[0x22] = (dFs_HIO_c)0xc;
  this[0x23] = (dFs_HIO_c)0x8c;
  this[0x24] = (dFs_HIO_c)0x46;
  this[0x25] = (dFs_HIO_c)0xc;
  this[0x26] = (dFs_HIO_c)0x8c;
  this[0x27] = (dFs_HIO_c)0x46;
  this[0x28] = (dFs_HIO_c)0x6;
  *(undefined2 *)(this + 0x40) = 400;
  this[0x29] = (dFs_HIO_c)0x0;
  this[0x2a] = (dFs_HIO_c)0x5;
  this[0x2b] = (dFs_HIO_c)0x5;
  this[0x2c] = (dFs_HIO_c)0xa;
  this[0x2d] = (dFs_HIO_c)0x8;
  this[0x2e] = (dFs_HIO_c)0x5;
  this[0x2f] = (dFs_HIO_c)0x6;
  this[0x30] = (dFs_HIO_c)0x5;
  this[0x31] = (dFs_HIO_c)0x0;
  this[0x32] = (dFs_HIO_c)0x6;
  this[0x33] = (dFs_HIO_c)0x0;
  *(undefined2 *)(this + 0x44) = 500;
  this[10] = (dFs_HIO_c)0x5;
  this[0x34] = (dFs_HIO_c)0x6;
  this[0x35] = (dFs_HIO_c)0x5;
  this[0x36] = (dFs_HIO_c)0x0;
  this[0x37] = (dFs_HIO_c)0x2;
  this[0x38] = (dFs_HIO_c)0x8;
  this[0x39] = (dFs_HIO_c)0x0;
  *(undefined2 *)(this + 0x42) = 100;
  *(undefined2 *)(this + 0x46) = 0xfed4;
  this[0x3a] = (dFs_HIO_c)0x0;
  this[0x3b] = (dFs_HIO_c)0x0;
  *(undefined2 *)(this + 0x3c) = 400;
  *(undefined2 *)(this + 0x3e) = 200;
  this[0x4f] = (dFs_HIO_c)0x5;
  this[0x4e] = (dFs_HIO_c)0x14;
  this[0x50] = (dFs_HIO_c)0x0;
  this[0x51] = (dFs_HIO_c)0x0;
  this[0x52] = (dFs_HIO_c)0x0;
  this[5] = (dFs_HIO_c)0x0;
  this[6] = (dFs_HIO_c)0x0;
  *(undefined2 *)(this + 0x4a) = 0x5a;
  *(undefined2 *)(this + 0x4c) = 100;
  *(float *)(this + 0x54) = d_file_select::_4012;
  *(float *)(this + 0x58) = d_file_select::_4013;
  return;
}


/* __thiscall dFile_select_c::_create(void) */

void __thiscall dFile_select_c::_create(dFile_select_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *pSVar2;
  JUTFont *pJVar3;
  dFile_select_c *pdVar4;
  int iVar5;
  int iVar6;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_file_select::_4050;
    local_18.mTL.y = d_file_select::_4050;
    local_18.mBR.x = d_file_select::_4051;
    local_18.mBR.y = d_file_select::_4052;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 8) = this_00;
  if (*(int *)(this + 8) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_select.cpp",0x164,"fileSel.Scr != 0");
    m_Do_printf::OSPanic("d_file_select.cpp",0x164,"Halt");
  }
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,5,2,3,2,d_file_select::_4053,d_file_select::_4054,0,0x2000);
  }
  *(STControl **)(this + 0x390c) = pSVar2;
  if (*(int *)(this + 0x390c) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_select.cpp",0x169,"stick != 0");
    m_Do_printf::OSPanic("d_file_select.cpp",0x169,"Halt");
  }
  pSVar2 = (STControl *)JKernel::operator_new(0x28);
  if (pSVar2 != (STControl *)0x0) {
    STControl::STControl(pSVar2,3,1,3,2,d_file_select::_4053,d_file_select::_4054,0,0x2000);
  }
  *(STControl **)(this + 0x3910) = pSVar2;
  if (*(int *)(this + 0x3910) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_select.cpp",0x16c,"stick2 != 0");
    m_Do_printf::OSPanic("d_file_select.cpp",0x16c,"Halt");
  }
  J2DScreen::set(*(J2DScreen **)(this + 8),"file_select.blo",*(JKRArchive **)this);
  pJVar3 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0xc) = pJVar3;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_file_select.cpp",0x172,"fileSel.font != 0");
    m_Do_printf::OSPanic("d_file_select.cpp",0x172,"Halt");
  }
  DAT_803e4a50 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"ファイルセレクト画面",
                            (JORReflexible *)&d_file_select::g_fsHIO);
  *(undefined4 *)(this + 0x3938) = 0;
  *(undefined4 *)(this + 0x393c) = 0;
  iVar5 = 0;
  iVar6 = 3;
  do {
    pdVar4 = this + iVar5;
    pdVar4[0x3914] = (dFile_select_c)0x0;
    pdVar4[0x3917] = (dFile_select_c)0x0;
    pdVar4[0x391a] = (dFile_select_c)0x0;
    pdVar4[0x391d] = (dFile_select_c)0x0;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this[0x3922] = (dFile_select_c)0x0;
  screenSet(this);
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dFile_select_c::initial(void) */

void __thiscall dFile_select_c::initial(dFile_select_c *this)

{
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dFile_select_c::_delete(void) */

void __thiscall dFile_select_c::_delete(dFile_select_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  m_Do_ext::mDoExt_removeMesgFont();
  JKernel::operator_delete(*(JKRHeap **)(this + 0x390c));
  JKernel::operator_delete(*(JKRHeap **)(this + 0x3910));
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e4a50);
  return;
}


/* __thiscall dFile_select_c::_move(void) */

void __thiscall dFile_select_c::_move(dFile_select_c *this)

{
  if (((DAT_file_cursor == 0) || (DAT_file_cursor == 1)) && (this[0x3941] == (dFile_select_c)0x0)) {
    this[0x392e] = (dFile_select_c)0x1;
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392c] = (dFile_select_c)0x2;
    this[0x3936] = (dFile_select_c)0x3;
    this[0x392a] = (dFile_select_c)0x7;
    this[0x392b] = (dFile_select_c)0x26;
  }
  else {
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_file_select::DataSelProc + (uint)(byte)this[0x392b] * 3),this,
               &DAT_80390000);
  }
  DAT_file_cursor = 2;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dFile_select_c::_open(void) */

undefined4 __thiscall dFile_select_c::_open(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar1 = PaneTranceTitle(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a57,DAT_803e4a54,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,DAT_803e4a53,0);
  iVar2 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a5b,DAT_803e4a58,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                                   d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                            d_file_select::_4050,'\x01',0);
  iVar3 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) -
                                 ((ushort)DAT_803e4a5b + (ushort)DAT_803e4a5c),DAT_803e4a59,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                                   d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                            d_file_select::_4050,'\x01',0);
  iVar4 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) -
                                 ((ushort)DAT_803e4a5b + (ushort)DAT_803e4a5c * 2),DAT_803e4a5a,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                                   d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                            d_file_select::_4050,'\x01',0);
  iVar5 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a60,DAT_803e4a5d,
                             d_file_select::_4050,
                             (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a66 ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                             '\x01',0);
  iVar6 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a61,DAT_803e4a5e,
                             d_file_select::_4050,
                             (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a68 ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                             '\x01',0);
  iVar7 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a62,DAT_803e4a5f,
                             d_file_select::_4050,
                             (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a6a ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                             '\x01',0);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) &&
     (((iVar4 == 1 && (iVar5 == 1)) && ((iVar6 == 1 && (iVar7 == 1)))))) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}


/* __thiscall dFile_select_c::_close(void) */

bool __thiscall dFile_select_c::_close(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  
  if (this[0x392e] == (dFile_select_c)0x0) {
    if (this[0x392c] == (dFile_select_c)0x3) {
      iVar2 = closeBack(this);
    }
    else {
      iVar2 = closeEnd(this);
    }
  }
  else {
    dVar1 = this[0x392a];
    if (dVar1 == (dFile_select_c)0x4) {
      iVar2 = closeErrErase(this);
    }
    else {
      if (dVar1 == (dFile_select_c)0x3) {
        iVar2 = closeErrCopy(this);
      }
      else {
        if (dVar1 == (dFile_select_c)0x5) {
          iVar2 = closeErrErase(this);
        }
        else {
          if (dVar1 == (dFile_select_c)0x6) {
            iVar2 = closeCardErr(this);
          }
          else {
            iVar2 = 1;
          }
        }
      }
    }
  }
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  return iVar2 != 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8018023c) */
/* __thiscall dFile_select_c::closeEnd(void) */

undefined4 __thiscall dFile_select_c::closeEnd(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_r29;
  int unaff_r30;
  
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),'\0',1);
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930),DAT_803e4a59,d_file_select::_4050,
                                  d_file_select::_4196,
                                  -(float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,'\0',1);
    unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930),DAT_803e4a5e,d_file_select::_4050,
                                   d_file_select::_4196,
                                   -(float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4196,'\0',1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,d_file_select::_4050
                                    ,d_file_select::_4050,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,
                                     d_file_select::_4050,d_file_select::_4050,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930),DAT_803e4a5a,
                                      d_file_select::_4050,d_file_select::_4197,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,'\0',1);
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930),DAT_803e4a5e,
                                       d_file_select::_4050,d_file_select::_4197,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4197,'\0',1);
      }
    }
  }
  iVar3 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,0,'\0',1);
  iVar4 = menuPaneMove(this,d_file_select::_4050,
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                              d_file_select::_4148),0,'\0',1);
  if ((((iVar2 == 1) && (unaff_r30 == 1)) && (unaff_r29 == 1)) && ((iVar3 == 1 && (iVar4 == 1)))) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80180598) */
/* __thiscall dFile_select_c::closeCardErr(void) */

undefined4 __thiscall dFile_select_c::closeCardErr(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_r29;
  int unaff_r30;
  
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),'\0',1);
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930),DAT_803e4a59,d_file_select::_4050,
                                  d_file_select::_4196,
                                  -(float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,'\0',1);
    unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930),DAT_803e4a5e,d_file_select::_4050,
                                   d_file_select::_4196,
                                   -(float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4196,'\0',1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,d_file_select::_4050
                                    ,d_file_select::_4050,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,
                                     d_file_select::_4050,d_file_select::_4050,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930),DAT_803e4a5a,
                                      d_file_select::_4050,d_file_select::_4197,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,'\0',1);
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930),DAT_803e4a5e,
                                       d_file_select::_4050,d_file_select::_4197,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4197,'\0',1);
      }
    }
  }
  iVar3 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,0,'\0',1);
  iVar4 = yesNoPaneMove(this,d_file_select::_4050,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                               d_file_select::_4148),0,'\0',1);
  if ((((iVar2 == 1) && (unaff_r30 == 1)) && (unaff_r29 == 1)) && ((iVar3 == 1 && (iVar4 == 1)))) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dFile_select_c::closeBack(void) */

undefined4 __thiscall dFile_select_c::closeBack(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar1 = PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),'\0',1);
  iVar2 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,d_file_select::_4050,
                            d_file_select::_4050,
                            -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,'\0',1);
  iVar3 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,d_file_select::_4050,
                             d_file_select::_4050,
                             -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,'\0',1);
  iVar4 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a5c,DAT_803e4a59,
                            d_file_select::_4050,d_file_select::_4050,
                            -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,'\0',1);
  iVar5 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a5c,DAT_803e4a5e,
                             d_file_select::_4050,d_file_select::_4050,
                             -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,'\0',1);
  iVar6 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) + (ushort)DAT_803e4a5c * -2,DAT_803e4a5a,
                            d_file_select::_4050,d_file_select::_4050,
                            -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,'\0',1);
  iVar7 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) + (ushort)DAT_803e4a5c * -2,DAT_803e4a5e
                             ,d_file_select::_4050,d_file_select::_4050,
                             -(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,'\0',1);
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) &&
     (((iVar4 == 1 && (iVar5 == 1)) && ((iVar6 == 1 && (iVar7 == 1)))))) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80180c1c) */
/* __thiscall dFile_select_c::closeErrErase(void) */

undefined4 __thiscall dFile_select_c::closeErrErase(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_r27;
  int unaff_r29;
  
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),'\0',1);
  iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a7d,
                          '\0',1);
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r29 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930),DAT_803e4a59,d_file_select::_4050,
                                  d_file_select::_4196,
                                  -(float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,'\0',1);
    unaff_r27 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930),DAT_803e4a5e,d_file_select::_4050,
                                   d_file_select::_4196,
                                   -(float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4196,'\0',1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r29 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,d_file_select::_4050
                                    ,d_file_select::_4050,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r27 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,
                                     d_file_select::_4050,d_file_select::_4050,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r29 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930),DAT_803e4a5a,
                                      d_file_select::_4050,d_file_select::_4197,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,'\0',1);
        unaff_r27 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930),DAT_803e4a5e,
                                       d_file_select::_4050,d_file_select::_4197,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4197,'\0',1);
      }
    }
  }
  if ((((iVar2 == 1) && (iVar3 == 1)) && (unaff_r29 == 1)) && (unaff_r27 == 1)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80180f30) */
/* __thiscall dFile_select_c::closeErrCopy(void) */

undefined4 __thiscall dFile_select_c::closeErrCopy(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_r23;
  int unaff_r24;
  int unaff_r28;
  int unaff_r30;
  
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                                 d_file_select::_4148),'\0',1);
  iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4299,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4299,(ushort)DAT_803e4a7d,
                          '\0',1);
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930),DAT_803e4a59,d_file_select::_4050,
                                  d_file_select::_4196,
                                  -(float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,'\0',1);
    unaff_r28 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930),DAT_803e4a5e,d_file_select::_4050,
                                   d_file_select::_4196,
                                   -(float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4196,'\0',1);
    if (this[0x3925] == (dFile_select_c)0x0) {
      unaff_r24 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                    DAT_803e4a58,d_file_select::_4050,d_file_select::_4299,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4299,'\0',1);
      unaff_r23 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                     DAT_803e4a5d,d_file_select::_4050,d_file_select::_4299,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4299,'\0',1);
    }
    else {
      unaff_r24 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                    DAT_803e4a5a,d_file_select::_4050,d_file_select::_4196,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4196,'\0',1);
      unaff_r23 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                     DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4196,'\0',1);
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,d_file_select::_4050
                                    ,d_file_select::_4050,
                                    -(float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r28 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,
                                     d_file_select::_4050,d_file_select::_4050,
                                     -(float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
      if (this[0x3925] == (dFile_select_c)0x0) {
        unaff_r24 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                      DAT_803e4a59,d_file_select::_4050,d_file_select::_4050,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4050,'\0',1);
        unaff_r23 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                       DAT_803e4a5e,d_file_select::_4050,d_file_select::_4050,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4050,'\0',1);
      }
      else {
        unaff_r24 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                      DAT_803e4a5a,d_file_select::_4050,d_file_select::_4196,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4196,'\0',1);
        unaff_r23 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                       DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4196,'\0',1);
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930),DAT_803e4a5a,
                                      d_file_select::_4050,d_file_select::_4197,
                                      -(float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,'\0',1);
        unaff_r28 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930),DAT_803e4a5e,
                                       d_file_select::_4050,d_file_select::_4197,
                                       -(float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4197,'\0',1);
        if (this[0x3925] == (dFile_select_c)0x0) {
          unaff_r24 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                        DAT_803e4a58,d_file_select::_4050,d_file_select::_4299,
                                        -(float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8c ^ 0x80000000) -
                                                d_file_select::_4148),d_file_select::_4299,'\0',1);
          unaff_r23 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                         DAT_803e4a5d,d_file_select::_4050,d_file_select::_4299,
                                         -(float)((double)CONCAT44(0x43300000,
                                                                   (int)DAT_803e4a8c ^ 0x80000000) -
                                                 d_file_select::_4148),d_file_select::_4299,'\0',1);
        }
        else {
          unaff_r24 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                        DAT_803e4a59,d_file_select::_4050,d_file_select::_4050,
                                        -(float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8c ^ 0x80000000) -
                                                d_file_select::_4148),d_file_select::_4050,'\0',1);
          unaff_r23 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a83,
                                         DAT_803e4a5e,d_file_select::_4050,d_file_select::_4050,
                                         -(float)((double)CONCAT44(0x43300000,
                                                                   (int)DAT_803e4a8c ^ 0x80000000) -
                                                 d_file_select::_4148),d_file_select::_4050,'\0',1);
        }
      }
    }
  }
  if ((((iVar2 == 1) && (iVar3 == 1)) && (unaff_r30 == 1)) &&
     (((unaff_r28 == 1 && (unaff_r24 == 1)) && (unaff_r23 == 1)))) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* __thiscall dFile_select_c::dataSelect(void) */

void __thiscall dFile_select_c::dataSelect(dFile_select_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0x3910));
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)) {
    cVar1 = STControl::checkUpTrigger(*(STControl **)(this + 0x3910));
    if (cVar1 == '\0') {
      cVar1 = STControl::checkDownTrigger(*(STControl **)(this + 0x3910));
      if ((cVar1 != '\0') && (this[0x3922] != (dFile_select_c)0x2)) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        this[0x3922] = (dFile_select_c)((char)this[0x3922] + '\x01');
        *(float *)(this + 0x3948) = d_file_select::_4050;
        this[0x3923] = (dFile_select_c)0x1;
        *(undefined2 *)(this + 0x3930) = 0;
        this[0x392b] = (dFile_select_c)0x1;
        recCursorMove(this);
      }
    }
    else {
      if (this[0x3922] != (dFile_select_c)0x0) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        this[0x3922] = (dFile_select_c)((char)this[0x3922] + -1);
        *(float *)(this + 0x3948) = d_file_select::_4050;
        this[0x3923] = (dFile_select_c)0xff;
        *(undefined2 *)(this + 0x3930) = 0;
        this[0x392b] = (dFile_select_c)0x1;
        recCursorMove(this);
      }
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
               d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
    this[0x3936] = (dFile_select_c)0x4;
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 0;
    if (this[(byte)this[0x3922] + 0x3917] != (dFile_select_c)0x0) {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1c);
    }
    menuColorChange(this);
    dataSelMoveSet(this);
    this[0x392b] = (dFile_select_c)0x2;
  }
  recCursorAnime(this);
  return;
}


/* __thiscall dFile_select_c::menuColorChange(void) */

void __thiscall dFile_select_c::menuColorChange(dFile_select_c *this)

{
  dFile_select_c dVar1;
  dFile_select_c dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined local_68;
  undefined uStack103;
  undefined uStack102;
  undefined uStack101;
  undefined local_64;
  undefined uStack99;
  undefined uStack98;
  undefined uStack97;
  undefined local_60;
  undefined uStack95;
  undefined uStack94;
  undefined uStack93;
  undefined local_5c;
  undefined uStack91;
  undefined uStack90;
  undefined uStack89;
  undefined local_58;
  undefined uStack87;
  undefined uStack86;
  undefined uStack85;
  undefined local_54;
  undefined uStack83;
  undefined uStack82;
  undefined uStack81;
  undefined local_50;
  undefined uStack79;
  undefined uStack78;
  undefined uStack77;
  undefined local_4c;
  undefined uStack75;
  undefined uStack74;
  undefined uStack73;
  
  if (this[(byte)this[0x3922] + 0x3914] == (dFile_select_c)0x0) {
    uVar3 = *(undefined4 *)(this + 0x38c8);
    uVar4 = *(undefined4 *)(this + 0x38c0);
    iVar5 = *(int *)(this + 0x3618);
    local_4c = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar5 + 0x108) = local_4c;
    uStack75 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar5 + 0x109) = uStack75;
    uStack74 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar5 + 0x10a) = uStack74;
    uStack73 = (undefined)uVar4;
    *(undefined *)(iVar5 + 0x10b) = uStack73;
    local_50 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar5 + 0x104) = local_50;
    uStack79 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar5 + 0x105) = uStack79;
    uStack78 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar5 + 0x106) = uStack78;
    uStack77 = (undefined)uVar3;
    *(undefined *)(iVar5 + 0x107) = uStack77;
    uVar3 = *(undefined4 *)(this + 0x38cc);
    uVar4 = *(undefined4 *)(this + 0x38c4);
    iVar5 = *(int *)(this + 0x3650);
    local_54 = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar5 + 0x108) = local_54;
    uStack83 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar5 + 0x109) = uStack83;
    uStack82 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar5 + 0x10a) = uStack82;
    uStack81 = (undefined)uVar4;
    *(undefined *)(iVar5 + 0x10b) = uStack81;
    local_58 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar5 + 0x104) = local_58;
    uStack87 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar5 + 0x105) = uStack87;
    uStack86 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar5 + 0x106) = uStack86;
    uStack85 = (undefined)uVar3;
    *(undefined *)(iVar5 + 0x107) = uStack85;
    uVar3 = *(undefined4 *)(this + 0x38d8);
    uVar4 = *(undefined4 *)(this + 0x38d0);
    iVar5 = *(int *)(this + 0x3730);
    local_5c = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar5 + 0x108) = local_5c;
    uStack91 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar5 + 0x109) = uStack91;
    uStack90 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar5 + 0x10a) = uStack90;
    uStack89 = (undefined)uVar4;
    *(undefined *)(iVar5 + 0x10b) = uStack89;
    local_60 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar5 + 0x104) = local_60;
    uStack95 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar5 + 0x105) = uStack95;
    uStack94 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar5 + 0x106) = uStack94;
    uStack93 = (undefined)uVar3;
    *(undefined *)(iVar5 + 0x107) = uStack93;
    uVar3 = *(undefined4 *)(this + 0x38dc);
    uVar4 = *(undefined4 *)(this + 0x38d4);
    iVar5 = *(int *)(this + 0x3768);
    local_64 = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar5 + 0x108) = local_64;
    uStack99 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar5 + 0x109) = uStack99;
    uStack98 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar5 + 0x10a) = uStack98;
    uStack97 = (undefined)uVar4;
    *(undefined *)(iVar5 + 0x10b) = uStack97;
    local_68 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar5 + 0x104) = local_68;
    uStack103 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar5 + 0x105) = uStack103;
    uStack102 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar5 + 0x106) = uStack102;
    uStack101 = (undefined)uVar3;
    *(undefined *)(iVar5 + 0x107) = uStack101;
  }
  else {
    dVar1 = this[0x38cb];
    dVar2 = this[0x38c3];
    iVar5 = *(int *)(this + 0x3618);
    *(undefined *)(iVar5 + 0x108) = 0x5a;
    *(undefined *)(iVar5 + 0x109) = 0x5a;
    *(undefined *)(iVar5 + 0x10a) = 0x5a;
    *(dFile_select_c *)(iVar5 + 0x10b) = dVar2;
    *(undefined *)(iVar5 + 0x104) = 200;
    *(undefined *)(iVar5 + 0x105) = 200;
    *(undefined *)(iVar5 + 0x106) = 200;
    *(dFile_select_c *)(iVar5 + 0x107) = dVar1;
    dVar1 = this[0x38cf];
    dVar2 = this[0x38c7];
    iVar5 = *(int *)(this + 0x3650);
    *(undefined *)(iVar5 + 0x108) = 0x5a;
    *(undefined *)(iVar5 + 0x109) = 0x5a;
    *(undefined *)(iVar5 + 0x10a) = 0x5a;
    *(dFile_select_c *)(iVar5 + 0x10b) = dVar2;
    *(undefined *)(iVar5 + 0x104) = 200;
    *(undefined *)(iVar5 + 0x105) = 200;
    *(undefined *)(iVar5 + 0x106) = 200;
    *(dFile_select_c *)(iVar5 + 0x107) = dVar1;
    dVar1 = this[0x38df];
    dVar2 = this[0x38d3];
    iVar5 = *(int *)(this + 0x3730);
    *(undefined *)(iVar5 + 0x108) = 0x5a;
    *(undefined *)(iVar5 + 0x109) = 0x5a;
    *(undefined *)(iVar5 + 0x10a) = 0x5a;
    *(dFile_select_c *)(iVar5 + 0x10b) = dVar2;
    *(undefined *)(iVar5 + 0x104) = 200;
    *(undefined *)(iVar5 + 0x105) = 200;
    *(undefined *)(iVar5 + 0x106) = 200;
    *(dFile_select_c *)(iVar5 + 0x107) = dVar1;
    dVar1 = this[0x38df];
    dVar2 = this[0x38d3];
    iVar5 = *(int *)(this + 0x3768);
    *(undefined *)(iVar5 + 0x108) = 0x5a;
    *(undefined *)(iVar5 + 0x109) = 0x5a;
    *(undefined *)(iVar5 + 0x10a) = 0x5a;
    *(dFile_select_c *)(iVar5 + 0x10b) = dVar2;
    *(undefined *)(iVar5 + 0x104) = 200;
    *(undefined *)(iVar5 + 0x105) = 200;
    *(undefined *)(iVar5 + 0x106) = 200;
    *(dFile_select_c *)(iVar5 + 0x107) = dVar1;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80181c14) */
/* __thiscall dFile_select_c::SelectTitAnime(void) */

void __thiscall dFile_select_c::SelectTitAnime(dFile_select_c *this)

{
  dFile_select_c dVar1;
  double dVar2;
  
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e4a9b,(int)*(short *)(this + 0x3930),5)
  ;
  *(float *)(this + 0x3948) =
       (float)((double)CONCAT44(0x43300000,(int)(char)this[0x3923] ^ 0x80000000) -
              d_file_select::_4148) *
       (float)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e4a9a) -
                              d_file_select::_4475) * dVar2);
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + 0x15b8),(double)d_file_select::_4050,
               (double)*(float *)(this + 0x3948));
    if (*(char *)(*(int *)(this + 0x1158) + 0xaa) != '\0') {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1158),(double)d_file_select::_4050,
                 (double)*(float *)(this + 0x3948));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1190),(double)d_file_select::_4050,
                 (double)*(float *)(this + 0x3948));
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1238),(double)d_file_select::_4050,
                 (double)*(float *)(this + 0x3948));
      if (*(char *)(*(int *)(this + 0x10e8) + 0xaa) != '\0') {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x10e8),(double)d_file_select::_4050,
                   (double)*(float *)(this + 0x3948));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1120),(double)d_file_select::_4050,
                   (double)*(float *)(this + 0x3948));
      }
    }
    else {
      if (((byte)dVar1 < 3) &&
         (f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1938),(double)d_file_select::_4050,
                     (double)*(float *)(this + 0x3948)),
         *(char *)(*(int *)(this + 0x10e8) + 0xaa) != '\0')) {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x11c8),(double)d_file_select::_4050,
                   (double)*(float *)(this + 0x3948));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1200),(double)d_file_select::_4050,
                   (double)*(float *)(this + 0x3948));
      }
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x2fc0),(double)d_file_select::_4050,
             (double)(d_file_select::_4299 *
                      (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x3922]) -
                             d_file_select::_4475) + *(float *)(this + 0x3948)));
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((short)(ushort)DAT_803e4a9b < *(short *)(this + 0x3930)) {
    *(undefined2 *)(this + 0x3930) = 0;
    if (this[0x3940] == (dFile_select_c)0x0) {
      this[0x392b] = (dFile_select_c)0x0;
    }
    else {
      this[0x392b] = (dFile_select_c)0x1a;
    }
  }
  return;
}


/* __thiscall dFile_select_c::recCursorMove(void) */

void __thiscall dFile_select_c::recCursorMove(dFile_select_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x2fc0),(double)d_file_select::_4050,
             (double)(d_file_select::_4299 *
                     (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x3922]) -
                            d_file_select::_4475)));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::recCursorAnime(void) */

void __thiscall dFile_select_c::recCursorAnime(dFile_select_c *this)

{
  byte bVar1;
  char cVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e4a6e,(int)*(short *)(this + 0x2ff6),0)
  ;
  bVar1 = DAT_803e4a70;
  if (this[0x3921] != (dFile_select_c)0x0) {
    dVar3 = (double)(float)((double)d_file_select::_4329 - dVar3);
  }
  cVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e4a6f -
                                                                      (uint)DAT_803e4a70 ^
                                                                      0x80000000) -
                                                    d_file_select::_4148) * dVar3));
  this[0x2ff5] = (dFile_select_c)(bVar1 + cVar2);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2fc0));
  if (*(short *)(this + 0x2ff6) == 0) {
    *(ushort *)(this + 0x2ff6) = (ushort)DAT_803e4a6e;
    this[0x3921] = (dFile_select_c)((byte)this[0x3921] ^ 1);
  }
  else {
    *(short *)(this + 0x2ff6) = *(short *)(this + 0x2ff6) + -1;
  }
  return;
}


/* __thiscall dFile_select_c::recCursorAlphaInit(void) */

void __thiscall dFile_select_c::recCursorAlphaInit(dFile_select_c *this)

{
  this[0x2ff5] = (dFile_select_c)0x0;
  *(undefined2 *)(this + 0x2ff6) = 0;
  this[0x3921] = (dFile_select_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2fc0));
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x80181f00) */
/* __thiscall dFile_select_c::recDataPaneMove(void) */

undefined4 __thiscall dFile_select_c::recDataPaneMove(dFile_select_c *this)

{
  dFile_select_c dVar1;
  dFile_select_c *pdVar2;
  undefined4 uVar3;
  int unaff_r25;
  int unaff_r26;
  int unaff_r27;
  int unaff_r28;
  int unaff_r30;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a74
                                  ,d_file_select::_4050,d_file_select::_4050,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,'\0',1);
    unaff_r28 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,
                                   DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4050,'\0',1);
    unaff_r27 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,DAT_803e4a74
                                  ,d_file_select::_4050,d_file_select::_4050,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,'\0',1);
    unaff_r26 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,
                                   DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4050,'\0',1);
    unaff_r25 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a79,DAT_803e4a74
                                  ,d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                  d_file_select::_4196,DAT_803e4a53,2);
    pdVar2 = (dFile_select_c *)
             PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a79,DAT_803e4a74,
                                d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                d_file_select::_4196,DAT_803e4a53,2);
    this[0x3920] = (dFile_select_c)(DAT_803e4a74 >> 1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,
                                    DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r28 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,
                                     DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r27 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,
                                    DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r26 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,
                                     DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,'\0',1);
      unaff_r25 = 1;
      this[0x3920] = (dFile_select_c)0x0;
      pdVar2 = (dFile_select_c *)&DAT_00000001;
    }
    else {
      pdVar2 = this;
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,
                                      DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
        unaff_r28 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,
                                       DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4050,'\0',1);
        unaff_r27 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,
                                      DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,'\0',1);
        unaff_r26 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a76,
                                       DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4050,'\0',1);
        unaff_r25 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a79,
                                      DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                      d_file_select::_4050,d_file_select::_4197,DAT_803e4a53,2);
        pdVar2 = (dFile_select_c *)
                 PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a79,
                                    DAT_803e4a74,d_file_select::_4050,d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4197,DAT_803e4a53,2);
        this[0x3920] = (dFile_select_c)(DAT_803e4a74 >> 1);
      }
    }
  }
  if ((((unaff_r30 == 1) && (unaff_r28 == 1)) && (unaff_r27 == 1)) &&
     (((unaff_r26 == 1 && (unaff_r25 == 1)) && (pdVar2 == (dFile_select_c *)&DAT_00000001)))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall dFile_select_c::dataSelMoveSet(void) */

void __thiscall dFile_select_c::dataSelMoveSet(dFile_select_c *this)

{
  *(undefined2 *)(this + 0x3930) = 0;
  if (this[(byte)this[0x3922] + 0x3917] == (dFile_select_c)0x0) {
    makeRecInfo(this,(uchar)this[0x3922]);
  }
  else {
    f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),0x23);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dFile_select_c::makeRecInfo(unsigned char) */

void __thiscall dFile_select_c::makeRecInfo(dFile_select_c *this,uchar param_1)

{
  ushort uVar1;
  dFile_select_c *pdVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  
  puVar5 = (ushort *)(*(int *)(this + 0x3938) + (uint)param_1 * 0x770);
  uVar1 = puVar5[1];
  uVar4 = (uint)(uVar1 >> 2);
  if ((uVar1 & 3) != 0) {
    uVar4 = uVar4 + 1;
  }
  iVar6 = 0;
  iVar3 = 0;
  do {
    if (iVar6 < (int)(uint)(*puVar5 >> 2)) {
      pdVar2 = this + iVar3;
      *(undefined *)(*(int *)(pdVar2 + 0x828) + 0xaa) = 1;
      *(undefined *)(*(int *)(pdVar2 + 0xc88) + 0xaa) = 1;
      if (iVar6 < (int)uVar4) {
        if (((uVar1 & 3) == 0) || (iVar6 != uVar4 - 1)) {
          J2DPicture::changeTexture(*(J2DPicture **)(pdVar2 + 0x828),"heart.bti",0);
          J2DPicture::changeTexture(*(J2DPicture **)(pdVar2 + 0xc88),"heart.bti",0);
        }
        else {
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar2 + 0x828),(char *)(&DAT_80391764)[uVar1 & 3],0);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(pdVar2 + 0xc88),(char *)(&DAT_80391764)[uVar1 & 3],0);
        }
      }
      else {
        J2DPicture::changeTexture(*(J2DPicture **)(pdVar2 + 0x828),"heart_04_2.bti",0);
        J2DPicture::changeTexture(*(J2DPicture **)(pdVar2 + 0xc88),"heart_04_2.bti",0);
      }
    }
    else {
      *(undefined *)(*(int *)(this + iVar3 + 0x828) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + iVar3 + 0xc88) + 0xaa) = 0;
    }
    iVar6 = iVar6 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar6 < 0x14);
  if (*(char *)(puVar5 + 0x5e) == '\0') {
    *(undefined *)(*(int *)(this + 0x278) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x5f8) + 0xaa) = 0;
    iVar3 = 0;
    iVar6 = 9;
    do {
      *(undefined *)(*(int *)(this + iVar3 + 0x630) + 0xaa) = 0;
      iVar3 = iVar3 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    *(undefined *)(*(int *)(this + 0x278) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x5f8) + 0xaa) = 1;
    if (*(char *)(puVar5 + 0x5e) == -1) {
      iVar3 = 0;
      iVar6 = 8;
      do {
        *(undefined *)(*(int *)(this + iVar3 + 0x630) + 0xaa) = 0;
        iVar3 = iVar3 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(undefined *)(*(int *)(this + 0x7f0) + 0xaa) = 1;
    }
    else {
      *(undefined *)(*(int *)(this + 0x7f0) + 0xaa) = 0;
      uVar4 = 1;
      iVar3 = 0;
      iVar6 = 8;
      do {
        if ((uVar4 & *(byte *)(puVar5 + 0x5e)) == 0) {
          *(undefined *)(*(int *)(this + iVar3 + 0x630) + 0xaa) = 0;
        }
        else {
          *(undefined *)(*(int *)(this + iVar3 + 0x630) + 0xaa) = 1;
        }
        uVar4 = (uVar4 & 0x7f) << 1;
        iVar3 = iVar3 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  uVar4 = 1;
  iVar3 = 0;
  iVar6 = 3;
  do {
    if ((uVar4 & *(byte *)((int)puVar5 + 0xbd)) == 0) {
      *(undefined *)(*(int *)(this + iVar3 + 0x4a8) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + iVar3 + 0x550) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(this + iVar3 + 0x4a8) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + iVar3 + 0x550) + 0xaa) = 1;
    }
    uVar4 = (uVar4 & 0x7f) << 1;
    iVar3 = iVar3 + 0x38;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dFile_select_c::dataSelectPaneMove(void) */

void __thiscall dFile_select_c::dataSelectPaneMove(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 1;
  iVar2 = recDataPaneMove(this);
  dVar1 = this[(byte)this[0x3922] + 0x3917];
  if (dVar1 == (dFile_select_c)0x0) {
    iVar3 = recInfoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4050,
                            d_file_select::_4050,d_file_select::_4050,
                            (ushort)DAT_803e4a7c + (ushort)(byte)this[0x3920],'\x01',0);
    iVar4 = menuPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,
                         (ushort)DAT_803e4a81 + (ushort)(byte)this[0x3920],'\x01',0);
  }
  else {
    iVar3 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4050,
                            d_file_select::_4050,d_file_select::_4050,
                            (ushort)DAT_803e4a7c + (ushort)(byte)this[0x3920],'\x01',0);
    iVar4 = yesNoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                                      d_file_select::_4148),d_file_select::_4050,
                          (ushort)DAT_803e4a84 + (ushort)(byte)this[0x3920],'\x01',0);
    iVar5 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  }
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((iVar2 == 1) && (iVar3 == 1)) && (iVar4 == 1)) && (iVar5 == 1)) {
    if (dVar1 != (dFile_select_c)0x0) {
      this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    }
    menuCursorAlphaInit(this);
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 1;
    if (this[(byte)this[0x3922] + 0x3917] == (dFile_select_c)0x0) {
      this[0x3928] = (dFile_select_c)0x0;
      menuCursorMove(this);
      this[0x392b] = (dFile_select_c)0x3;
      this[0x392a] = (dFile_select_c)0x1;
    }
    else {
      this[0x3928] = (dFile_select_c)0x1;
      yesNoCursorMove(this);
      *(undefined2 *)(this + 0x3930) = 0;
      *(float *)(this + 0x3944) = d_file_select::_4050;
      this[0x392b] = (dFile_select_c)0xb;
      this[0x392a] = (dFile_select_c)0x4;
    }
  }
  return;
}


/* __thiscall dFile_select_c::MessagePaneMoveSet(float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 int) */

void __thiscall
dFile_select_c::MessagePaneMoveSet
          (dFile_select_c *this,float param_1,float param_2,float param_3,float param_4,
          uchar param_5,int param_6)

{
  PaneTranceMessageBase
            (this,*(short *)(this + 0x3930),DAT_803e4a7e,param_1,param_2,param_3,param_4,param_5,
             param_6);
  if (*(char *)(*(int *)(this + 0xf0) + 0xaa) == '\0') {
    *(undefined *)(*(int *)(this + 0xf0) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x128) + 0xaa) = 1;
  }
  return;
}


/* __thiscall dFile_select_c::menuSelect(void) */

void __thiscall dFile_select_c::menuSelect(dFile_select_c *this)

{
  dFile_select_c dVar1;
  dFile_select_c *pdVar2;
  char cVar3;
  
  STControl::checkTrigger(*(STControl **)(this + 0x390c));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      *(undefined2 *)(this + 0x3930) = 0;
      *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
      this[0x3936] = (dFile_select_c)0x5;
      this[0x392b] = (dFile_select_c)0x6;
      this[0x392a] = (dFile_select_c)0x8;
    }
    else {
      cVar3 = STControl::checkRightTrigger(*(STControl **)(this + 0x390c));
      if (cVar3 == '\0') {
        cVar3 = STControl::checkLeftTrigger(*(STControl **)(this + 0x390c));
        if (cVar3 != '\0') {
          if (this[0x3928] != (dFile_select_c)0x0) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
            this[0x3928] = (dFile_select_c)((char)this[0x3928] + -1);
            if ((this[(byte)this[0x3922] + 0x3914] != (dFile_select_c)0x0) &&
               ((this[0x3928] == (dFile_select_c)0x1 || (this[0x3928] == (dFile_select_c)0x2)))) {
              this[0x3928] = (dFile_select_c)0x0;
            }
          }
          *(undefined2 *)(this + 0x3930) = 0;
          menuCursorMove(this);
        }
      }
      else {
        if (this[0x3928] != (dFile_select_c)0x3) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          this[0x3928] = (dFile_select_c)((char)this[0x3928] + '\x01');
          if ((this[(byte)this[0x3922] + 0x3914] != (dFile_select_c)0x0) &&
             ((this[0x3928] == (dFile_select_c)0x1 || (this[0x3928] == (dFile_select_c)0x2)))) {
            this[0x3928] = (dFile_select_c)0x3;
          }
        }
        *(undefined2 *)(this + 0x3930) = 0;
        menuCursorMove(this);
      }
    }
  }
  else {
    dVar1 = this[0x3928];
    if (dVar1 == (dFile_select_c)0x0) {
      pdVar2 = this + (byte)this[0x3922];
      if (pdVar2[0x3914] == (dFile_select_c)0x0) {
        if (pdVar2[0x391a] == (dFile_select_c)0x0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x833,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        }
        else {
          if (pdVar2[0x391d] == (dFile_select_c)0x0) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x833,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          }
          else {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          }
        }
      }
      else {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      }
      *(undefined2 *)(this + 0x3930) = 0;
      *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
      this[0x392c] = (dFile_select_c)0x1;
      d_com_inf_game::g_dComIfG_gameInfo._4752_1_ = this[0x3922];
      this[0x392b] = (dFile_select_c)0x26;
    }
    else {
      if (dVar1 == (dFile_select_c)0x1) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        *(undefined2 *)(this + 0x3930) = 0;
        *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
        this[0x3924] = this[0x3922];
        saveCopyBWColor(this);
        *(float *)(this + 0x3944) = d_file_select::_4299;
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1f);
        this[0x392b] = (dFile_select_c)0x4;
        this[0x392a] = (dFile_select_c)0x3;
      }
      else {
        if (dVar1 == (dFile_select_c)0x2) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          *(undefined2 *)(this + 0x3930) = 0;
          *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
          *(float *)(this + 0x3944) = d_file_select::_4050;
          f_op_msg_mng::fopMsgM_messageGet
                    (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1c);
          this[0x392b] = (dFile_select_c)0x5;
          this[0x392a] = (dFile_select_c)0x4;
        }
        else {
          if (dVar1 == (dFile_select_c)0x3) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
            *(undefined2 *)(this + 0x3930) = 0;
            *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
            *(float *)(this + 0x3944) = d_file_select::_4050;
            this[0x3936] = (dFile_select_c)0x5;
            this[0x392b] = (dFile_select_c)0x6;
            this[0x392a] = (dFile_select_c)0x8;
          }
        }
      }
    }
  }
  menuCursorAnime(this);
  return;
}


/* __thiscall dFile_select_c::menuCursorAlphaInit(void) */

void __thiscall dFile_select_c::menuCursorAlphaInit(dFile_select_c *this)

{
  this[0x310d] = (dFile_select_c)0x0;
  *(undefined2 *)(this + 0x310e) = 0;
  this[0x3927] = (dFile_select_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x30d8));
  return;
}


/* __thiscall dFile_select_c::menuCursorMove(void) */

void __thiscall dFile_select_c::menuCursorMove(dFile_select_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x30d8),
             (double)*(float *)(&d_file_select::posx_4771 + (uint)(byte)this[0x3928] * 4),
             (double)d_file_select::_4050);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::menuCursorAnime(void) */

void __thiscall dFile_select_c::menuCursorAnime(dFile_select_c *this)

{
  byte bVar1;
  char cVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e4a71,(int)*(short *)(this + 0x310e),0)
  ;
  bVar1 = DAT_803e4a73;
  if (this[0x3927] != (dFile_select_c)0x0) {
    dVar3 = (double)(float)((double)d_file_select::_4329 - dVar3);
  }
  cVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e4a72 -
                                                                      (uint)DAT_803e4a73 ^
                                                                      0x80000000) -
                                                    d_file_select::_4148) * dVar3));
  this[0x310d] = (dFile_select_c)(bVar1 + cVar2);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x30d8));
  if (*(short *)(this + 0x310e) == 0) {
    *(ushort *)(this + 0x310e) = (ushort)DAT_803e4a71;
    this[0x3927] = (dFile_select_c)((byte)this[0x3927] ^ 1);
  }
  else {
    *(short *)(this + 0x310e) = *(short *)(this + 0x310e) + -1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dFile_select_c::ToCopyPaneMove(void) */

void __thiscall dFile_select_c::ToCopyPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DataSelectPaneCopyMove(this,(ushort)DAT_803e4a77,(ushort)DAT_803e4a78);
  iVar2 = DataSelectPaneCopyColorMove(this,*(short *)(this + 0x3930),DAT_803e4a56,1);
  iVar3 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a7d,
                          '\0',1);
  iVar4 = menuPaneMove(this,d_file_select::_4050,
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                              d_file_select::_4148),(ushort)DAT_803e4a82,'\0',1);
  iVar5 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && ((iVar4 == 1 && (iVar5 == 1)))) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    recCursorAlphaInit(this);
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
    this[0x3925] = (dFile_select_c)0x0;
    cptCursorMove(this);
    this[0x392b] = (dFile_select_c)0x7;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::ToErasePaneMove(void) */

void __thiscall dFile_select_c::ToErasePaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = menuPaneMove(this,d_file_select::_4050,
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                              d_file_select::_4148),(ushort)DAT_803e4a82,'\0',1);
  iVar2 = yesNoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a84,
                        '\x01',0);
  iVar3 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    menuCursorAlphaInit(this);
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 1;
    this[0x3928] = (dFile_select_c)0x1;
    yesNoCursorMove(this);
    this[0x392b] = (dFile_select_c)0xb;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::ToBackPaneMove(void) */

void __thiscall dFile_select_c::ToBackPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DataSelectPaneBackMove
                    (this,(ushort)DAT_803e4a77,(ushort)DAT_803e4a78,(ushort)DAT_803e4a7a);
  iVar2 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a7d,
                          '\0',1);
  iVar3 = menuPaneMove(this,d_file_select::_4050,
                       (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                              d_file_select::_4148),(ushort)DAT_803e4a82,'\0',1);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    recCursorAlphaInit(this);
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
    this[0x392b] = (dFile_select_c)0x0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8018349c) */
/* __thiscall dFile_select_c::copyDataToSelect(void) */

void __thiscall dFile_select_c::copyDataToSelect(dFile_select_c *this)

{
  dFile_select_c dVar1;
  char cVar2;
  
  STControl::checkTrigger(*(STControl **)(this + 0x390c));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 0;
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1b);
      this[0x3936] = (dFile_select_c)0x5;
      this[0x392b] = (dFile_select_c)0x9;
    }
    else {
      cVar2 = STControl::checkUpTrigger(*(STControl **)(this + 0x390c));
      if (cVar2 == '\0') {
        cVar2 = STControl::checkDownTrigger(*(STControl **)(this + 0x390c));
        if ((cVar2 != '\0') && (this[0x3925] != (dFile_select_c)0x1)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          *(float *)(this + 0x3948) = d_file_select::_4050;
          this[0x3923] = (dFile_select_c)0x1;
          *(undefined2 *)(this + 0x3930) = 0;
          this[0x3925] = (dFile_select_c)0x1;
          cptCursorMove(this);
          this[0x392b] = (dFile_select_c)0x8;
        }
      }
      else {
        if (this[0x3925] != (dFile_select_c)0x0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          *(float *)(this + 0x3948) = d_file_select::_4050;
          this[0x3923] = (dFile_select_c)0xff;
          *(undefined2 *)(this + 0x3930) = 0;
          this[0x3925] = (dFile_select_c)0x0;
          cptCursorMove(this);
          this[0x392b] = (dFile_select_c)0x8;
        }
      }
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,
               d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
    dVar1 = this[0x3924];
    if (dVar1 == (dFile_select_c)0x1) {
      this[0x3926] = (dFile_select_c)((char)this[0x3925] << 1);
    }
    else {
      if (dVar1 == (dFile_select_c)0x0) {
        this[0x3926] = (dFile_select_c)((char)this[0x3925] + '\x01');
      }
      else {
        if ((byte)dVar1 < 3) {
          this[0x3926] = this[0x3925];
        }
      }
    }
    if (this[(byte)this[0x3926] + 0x3917] == (dFile_select_c)0x0) {
      makeRecInfo(this,(uchar)this[0x3926]);
    }
    else {
      f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),0x24);
    }
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x20);
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 0;
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0xa;
  }
  recCursorAnime(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8018374c) */
/* __thiscall dFile_select_c::copyDataSelAnime(void) */

void __thiscall dFile_select_c::copyDataSelAnime(dFile_select_c *this)

{
  dFile_select_c dVar1;
  double dVar2;
  
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e4a9b,(int)*(short *)(this + 0x3930),5)
  ;
  *(float *)(this + 0x3948) =
       (float)((double)CONCAT44(0x43300000,(int)(char)this[0x3923] ^ 0x80000000) -
              d_file_select::_4148) *
       (float)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e4a9a) -
                              d_file_select::_4475) * dVar2);
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    if (this[0x3925] == (dFile_select_c)0x0) {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1238),(double)d_file_select::_4050,
                 (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
      if (*(char *)(*(int *)(this + 0x10e8) + 0xaa) != '\0') {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x10e8),(double)d_file_select::_4050,
                   (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1120),(double)d_file_select::_4050,
                   (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
      }
    }
    else {
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1938),(double)d_file_select::_4050,
                 (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
      if (*(char *)(*(int *)(this + 0x11c8) + 0xaa) != '\0') {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x11c8),(double)d_file_select::_4050,
                   (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1200),(double)d_file_select::_4050,
                   (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
      }
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      if (this[0x3925] == (dFile_select_c)0x0) {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x15b8),(double)d_file_select::_4050,
                   (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
        if (*(char *)(*(int *)(this + 0x1158) + 0xaa) != '\0') {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1158),(double)d_file_select::_4050,
                     (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1190),(double)d_file_select::_4050,
                     (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
        }
      }
      else {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1938),(double)d_file_select::_4050,
                   (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
        if (*(char *)(*(int *)(this + 0x11c8) + 0xaa) != '\0') {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x11c8),(double)d_file_select::_4050,
                     (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1200),(double)d_file_select::_4050,
                     (double)(d_file_select::_4901 + *(float *)(this + 0x3948)));
        }
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        if (this[0x3925] == (dFile_select_c)0x0) {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1238),(double)d_file_select::_4050,
                     (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
          if (*(char *)(*(int *)(this + 0x10e8) + 0xaa) != '\0') {
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + 0x10e8),(double)d_file_select::_4050,
                       (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + 0x1120),(double)d_file_select::_4050,
                       (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
          }
        }
        else {
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x15b8),(double)d_file_select::_4050,
                     (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
          if (*(char *)(*(int *)(this + 0x1158) + 0xaa) != '\0') {
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + 0x1158),(double)d_file_select::_4050,
                       (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + 0x1190),(double)d_file_select::_4050,
                       (double)(d_file_select::_4902 + *(float *)(this + 0x3948)));
          }
        }
      }
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x2fc0),(double)d_file_select::_4050,
             (double)(d_file_select::_4901 +
                      d_file_select::_4299 *
                      (float)((double)CONCAT44(0x43300000,(byte)this[0x3925] + 1 ^ 0x80000000) -
                             d_file_select::_4148) + *(float *)(this + 0x3948)));
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((short)(ushort)DAT_803e4a9b < *(short *)(this + 0x3930)) {
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x7;
  }
  return;
}


/* __thiscall dFile_select_c::cptCursorMove(void) */

void __thiscall dFile_select_c::cptCursorMove(dFile_select_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x2fc0),(double)d_file_select::_4050,
             (double)(d_file_select::_4901 +
                     d_file_select::_4299 *
                     (float)((double)CONCAT44(0x43300000,(byte)this[0x3925] + 1 ^ 0x80000000) -
                            d_file_select::_4148)));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::copyToSelBack(void) */

void __thiscall dFile_select_c::copyToSelBack(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DataSelectPaneBackFromCopyMove(this,DAT_803e4a6c,DAT_803e4a6d);
  iVar2 = DataSelectPaneCopyColorMove(this,*(short *)(this + 0x3930),DAT_803e4a56,0);
  iVar3 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
    recCursorMove(this);
    this[0x392b] = (dFile_select_c)0x0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dFile_select_c::copyToSelPaneMove(void) */

void __thiscall dFile_select_c::copyToSelPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DataSelectPaneCopyMove2(this,(ushort)DAT_803e4a75,(ushort)DAT_803e4a76);
  if (this[(byte)this[0x3926] + 0x3917] == (dFile_select_c)0x0) {
    iVar2 = recInfoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4299,
                            d_file_select::_4050,d_file_select::_4299,(ushort)DAT_803e4a7c,'\x01',0)
    ;
  }
  else {
    iVar2 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4299,
                            d_file_select::_4050,d_file_select::_4299,(ushort)DAT_803e4a7c,'\x01',0)
    ;
  }
  iVar3 = yesNoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a84,
                        '\x01',0);
  iVar4 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (iVar4 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 1;
    this[0x3928] = (dFile_select_c)0x1;
    yesNoCursorMove(this);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0xb;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80183d58) */
/* __thiscall dFile_select_c::copyPaneMoveOk(void) */

void __thiscall dFile_select_c::copyPaneMoveOk(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int unaff_r30;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    if (this[0x3925] == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5d,d_file_select::_4050,d_file_select::_4299,
                                     d_file_select::_4050,
                                     d_file_select::_4299 +
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8a ^ 0x80000000) -
                                            d_file_select::_4148),DAT_803e4a53,1);
    }
    else {
      unaff_r30 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5f,d_file_select::_4050,d_file_select::_4196,
                                     d_file_select::_4050,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8a ^ 0x80000000) -
                                            d_file_select::_4148) - d_file_select::_4299,
                                     DAT_803e4a53,1);
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      if (this[0x3925] == (dFile_select_c)0x0) {
        unaff_r30 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5e,d_file_select::_4050,d_file_select::_4050,
                                       d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8a ^ 0x80000000) -
                                              d_file_select::_4148),DAT_803e4a53,1);
      }
      else {
        unaff_r30 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5f,d_file_select::_4050,d_file_select::_4196,
                                       d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8a ^ 0x80000000) -
                                              d_file_select::_4148) - d_file_select::_4299,
                                       DAT_803e4a53,1);
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        if (this[0x3925] == (dFile_select_c)0x0) {
          unaff_r30 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                         DAT_803e4a5d,d_file_select::_4050,d_file_select::_4299,
                                         d_file_select::_4050,
                                         d_file_select::_4299 +
                                         (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8a ^ 0x80000000) -
                                                d_file_select::_4148),DAT_803e4a53,1);
        }
        else {
          unaff_r30 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                         DAT_803e4a5e,d_file_select::_4050,d_file_select::_4050,
                                         d_file_select::_4050,
                                         (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8a ^ 0x80000000) -
                                                d_file_select::_4148),DAT_803e4a53,1);
        }
      }
    }
  }
  MessagePaneMove(this,d_file_select::_4050,d_file_select::_4299,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                         d_file_select::_4148),d_file_select::_4299,(ushort)DAT_803e4a87,'\0',1);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((unaff_r30 == 1) && (unaff_r30 == 1)) {
    setSaveData(this);
    makeRecInfo(this,(uchar)this[0x3926]);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x12;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80184094) */
/* __thiscall dFile_select_c::copyPaneMoveOk2(void) */

void __thiscall dFile_select_c::copyPaneMoveOk2(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  int unaff_r29;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    if (this[0x3925] == (dFile_select_c)0x0) {
      unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5d,d_file_select::_4050,d_file_select::_4050,
                                     d_file_select::_4050,d_file_select::_4299,'\x01',0);
    }
    else {
      unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5f,d_file_select::_4050,d_file_select::_4197,
                                     d_file_select::_4050,d_file_select::_4196,'\x01',0);
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      if (this[0x3925] == (dFile_select_c)0x0) {
        unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                       d_file_select::_4050,d_file_select::_4050,'\x01',0);
      }
      else {
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5f,d_file_select::_4050,d_file_select::_4197,
                                       d_file_select::_4050,d_file_select::_4196,'\x01',0);
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        if (this[0x3925] == (dFile_select_c)0x0) {
          unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                         DAT_803e4a5d,d_file_select::_4050,d_file_select::_4050,
                                         d_file_select::_4050,d_file_select::_4299,'\x01',0);
        }
        else {
          unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                         DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                         d_file_select::_4050,d_file_select::_4050,'\x01',0);
        }
      }
    }
  }
  iVar2 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                          d_file_select::_4299,(ushort)DAT_803e4a86,'\x01',0);
  iVar3 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((unaff_r29 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x17;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8018430c) */
/* __thiscall dFile_select_c::saveCopyBWColor(void) */

void __thiscall dFile_select_c::saveCopyBWColor(dFile_select_c *this)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  dFile_select_c *pdVar5;
  int iVar6;
  dFile_select_c local_48;
  dFile_select_c dStack71;
  dFile_select_c dStack70;
  dFile_select_c dStack69;
  dFile_select_c local_44;
  dFile_select_c dStack67;
  dFile_select_c dStack66;
  dFile_select_c dStack65;
  dFile_select_c local_40;
  dFile_select_c dStack63;
  dFile_select_c dStack62;
  dFile_select_c dStack61;
  dFile_select_c local_3c;
  dFile_select_c dStack59;
  dFile_select_c dStack58;
  dFile_select_c dStack57;
  dFile_select_c local_38;
  dFile_select_c dStack55;
  dFile_select_c dStack54;
  dFile_select_c dStack53;
  dFile_select_c local_34;
  dFile_select_c dStack51;
  dFile_select_c dStack50;
  dFile_select_c dStack49;
  dFile_select_c local_30;
  dFile_select_c dStack47;
  dFile_select_c dStack46;
  dFile_select_c dStack45;
  dFile_select_c local_2c;
  dFile_select_c dStack43;
  dFile_select_c dStack42;
  dFile_select_c dStack41;
  dFile_select_c local_28;
  dFile_select_c dStack39;
  dFile_select_c dStack38;
  dFile_select_c dStack37;
  dFile_select_c local_24;
  dFile_select_c dStack35;
  dFile_select_c dStack34;
  dFile_select_c dStack33;
  dFile_select_c local_20;
  dFile_select_c dStack31;
  dFile_select_c dStack30;
  dFile_select_c dStack29;
  dFile_select_c local_1c;
  dFile_select_c dStack27;
  dFile_select_c dStack26;
  dFile_select_c dStack25;
  dFile_select_c local_18;
  dFile_select_c dStack23;
  dFile_select_c dStack22;
  dFile_select_c dStack21;
  dFile_select_c local_14;
  dFile_select_c dStack19;
  dFile_select_c dStack18;
  dFile_select_c dStack17;
  dFile_select_c local_10;
  dFile_select_c dStack15;
  dFile_select_c dStack14;
  dFile_select_c dStack13;
  dFile_select_c local_c;
  dFile_select_c dStack11;
  dFile_select_c dStack10;
  dFile_select_c dStack9;
  dFile_select_c local_8;
  dFile_select_c dStack7;
  dFile_select_c dStack6;
  dFile_select_c dStack5;
  dFile_select_c local_4;
  dFile_select_c dStack3;
  dFile_select_c dStack2;
  dFile_select_c dStack1;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    iVar3 = 8;
    iVar4 = 0x70;
    iVar6 = 10;
    do {
      uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x15b8) + 0x108);
      local_1c = SUB41((uint)uVar2 >> 0x18,0);
      pdVar5 = this + iVar3;
      pdVar5[0x37d0] = local_1c;
      dStack27 = SUB41((uint)uVar2 >> 0x10,0);
      pdVar5[0x37d1] = dStack27;
      dStack26 = SUB41((uint)uVar2 >> 8,0);
      pdVar5[0x37d2] = dStack26;
      dStack25 = SUB41(uVar2,0);
      pdVar5[0x37d3] = dStack25;
      uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x15b8) + 0x104);
      local_20 = SUB41((uint)uVar2 >> 0x18,0);
      pdVar5[0x37fc] = local_20;
      dStack31 = SUB41((uint)uVar2 >> 0x10,0);
      pdVar5[0x37fd] = dStack31;
      dStack30 = SUB41((uint)uVar2 >> 8,0);
      pdVar5[0x37fe] = dStack30;
      dStack29 = SUB41(uVar2,0);
      pdVar5[0x37ff] = dStack29;
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar2 = *(undefined4 *)(*(int *)(this + 0x15f0) + 0x108);
    local_24 = SUB41((uint)uVar2 >> 0x18,0);
    this[0x3800] = local_24;
    dStack35 = SUB41((uint)uVar2 >> 0x10,0);
    this[0x3801] = dStack35;
    dStack34 = SUB41((uint)uVar2 >> 8,0);
    this[0x3802] = dStack34;
    dStack33 = SUB41(uVar2,0);
    this[0x3803] = dStack33;
    uVar2 = *(undefined4 *)(*(int *)(this + 0x15f0) + 0x104);
    local_28 = SUB41((uint)uVar2 >> 0x18,0);
    this[0x382c] = local_28;
    dStack39 = SUB41((uint)uVar2 >> 0x10,0);
    this[0x382d] = dStack39;
    dStack38 = SUB41((uint)uVar2 >> 8,0);
    this[0x382e] = dStack38;
    dStack37 = SUB41(uVar2,0);
    this[0x382f] = dStack37;
    iVar3 = 0xc;
    iVar4 = 0xa8;
    iVar6 = 0x12;
    do {
      uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x2310) + 0x108);
      local_2c = SUB41((uint)uVar2 >> 0x18,0);
      pdVar5 = this + iVar3;
      pdVar5[0x3824] = local_2c;
      dStack43 = SUB41((uint)uVar2 >> 0x10,0);
      pdVar5[0x3825] = dStack43;
      dStack42 = SUB41((uint)uVar2 >> 8,0);
      pdVar5[0x3826] = dStack42;
      dStack41 = SUB41(uVar2,0);
      pdVar5[0x3827] = dStack41;
      uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x2310) + 0x104);
      local_30 = SUB41((uint)uVar2 >> 0x18,0);
      pdVar5[0x386c] = local_30;
      dStack47 = SUB41((uint)uVar2 >> 0x10,0);
      pdVar5[0x386d] = dStack47;
      dStack46 = SUB41((uint)uVar2 >> 8,0);
      pdVar5[0x386e] = dStack46;
      dStack45 = SUB41(uVar2,0);
      pdVar5[0x386f] = dStack45;
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      iVar3 = 8;
      iVar4 = 0x70;
      iVar6 = 10;
      do {
        uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1238) + 0x108);
        local_4 = SUB41((uint)uVar2 >> 0x18,0);
        pdVar5 = this + iVar3;
        pdVar5[0x37d0] = local_4;
        dStack3 = SUB41((uint)uVar2 >> 0x10,0);
        pdVar5[0x37d1] = dStack3;
        dStack2 = SUB41((uint)uVar2 >> 8,0);
        pdVar5[0x37d2] = dStack2;
        dStack1 = SUB41(uVar2,0);
        pdVar5[0x37d3] = dStack1;
        uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1238) + 0x104);
        local_8 = SUB41((uint)uVar2 >> 0x18,0);
        pdVar5[0x37fc] = local_8;
        dStack7 = SUB41((uint)uVar2 >> 0x10,0);
        pdVar5[0x37fd] = dStack7;
        dStack6 = SUB41((uint)uVar2 >> 8,0);
        pdVar5[0x37fe] = dStack6;
        dStack5 = SUB41(uVar2,0);
        pdVar5[0x37ff] = dStack5;
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar2 = *(undefined4 *)(*(int *)(this + 0x1270) + 0x108);
      local_c = SUB41((uint)uVar2 >> 0x18,0);
      this[0x3800] = local_c;
      dStack11 = SUB41((uint)uVar2 >> 0x10,0);
      this[0x3801] = dStack11;
      dStack10 = SUB41((uint)uVar2 >> 8,0);
      this[0x3802] = dStack10;
      dStack9 = SUB41(uVar2,0);
      this[0x3803] = dStack9;
      uVar2 = *(undefined4 *)(*(int *)(this + 0x1270) + 0x104);
      local_10 = SUB41((uint)uVar2 >> 0x18,0);
      this[0x382c] = local_10;
      dStack15 = SUB41((uint)uVar2 >> 0x10,0);
      this[0x382d] = dStack15;
      dStack14 = SUB41((uint)uVar2 >> 8,0);
      this[0x382e] = dStack14;
      dStack13 = SUB41(uVar2,0);
      this[0x382f] = dStack13;
      iVar3 = 0xc;
      iVar4 = 0xa8;
      iVar6 = 0x12;
      do {
        uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1cb8) + 0x108);
        local_14 = SUB41((uint)uVar2 >> 0x18,0);
        pdVar5 = this + iVar3;
        pdVar5[0x3824] = local_14;
        dStack19 = SUB41((uint)uVar2 >> 0x10,0);
        pdVar5[0x3825] = dStack19;
        dStack18 = SUB41((uint)uVar2 >> 8,0);
        pdVar5[0x3826] = dStack18;
        dStack17 = SUB41(uVar2,0);
        pdVar5[0x3827] = dStack17;
        uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1cb8) + 0x104);
        local_18 = SUB41((uint)uVar2 >> 0x18,0);
        pdVar5[0x386c] = local_18;
        dStack23 = SUB41((uint)uVar2 >> 0x10,0);
        pdVar5[0x386d] = dStack23;
        dStack22 = SUB41((uint)uVar2 >> 8,0);
        pdVar5[0x386e] = dStack22;
        dStack21 = SUB41(uVar2,0);
        pdVar5[0x386f] = dStack21;
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      if ((byte)dVar1 < 3) {
        iVar3 = 8;
        iVar4 = 0x70;
        iVar6 = 10;
        do {
          uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1938) + 0x108);
          local_34 = SUB41((uint)uVar2 >> 0x18,0);
          pdVar5 = this + iVar3;
          pdVar5[0x37d0] = local_34;
          dStack51 = SUB41((uint)uVar2 >> 0x10,0);
          pdVar5[0x37d1] = dStack51;
          dStack50 = SUB41((uint)uVar2 >> 8,0);
          pdVar5[0x37d2] = dStack50;
          dStack49 = SUB41(uVar2,0);
          pdVar5[0x37d3] = dStack49;
          uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x1938) + 0x104);
          local_38 = SUB41((uint)uVar2 >> 0x18,0);
          pdVar5[0x37fc] = local_38;
          dStack55 = SUB41((uint)uVar2 >> 0x10,0);
          pdVar5[0x37fd] = dStack55;
          dStack54 = SUB41((uint)uVar2 >> 8,0);
          pdVar5[0x37fe] = dStack54;
          dStack53 = SUB41(uVar2,0);
          pdVar5[0x37ff] = dStack53;
          iVar3 = iVar3 + 4;
          iVar4 = iVar4 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar2 = *(undefined4 *)(*(int *)(this + 0x1970) + 0x108);
        local_3c = SUB41((uint)uVar2 >> 0x18,0);
        this[0x3800] = local_3c;
        dStack59 = SUB41((uint)uVar2 >> 0x10,0);
        this[0x3801] = dStack59;
        dStack58 = SUB41((uint)uVar2 >> 8,0);
        this[0x3802] = dStack58;
        dStack57 = SUB41(uVar2,0);
        this[0x3803] = dStack57;
        uVar2 = *(undefined4 *)(*(int *)(this + 0x1970) + 0x104);
        local_40 = SUB41((uint)uVar2 >> 0x18,0);
        this[0x382c] = local_40;
        dStack63 = SUB41((uint)uVar2 >> 0x10,0);
        this[0x382d] = dStack63;
        dStack62 = SUB41((uint)uVar2 >> 8,0);
        this[0x382e] = dStack62;
        dStack61 = SUB41(uVar2,0);
        this[0x382f] = dStack61;
        iVar3 = 0xc;
        iVar4 = 0xa8;
        iVar6 = 0x12;
        do {
          uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x2968) + 0x108);
          local_44 = SUB41((uint)uVar2 >> 0x18,0);
          pdVar5 = this + iVar3;
          pdVar5[0x3824] = local_44;
          dStack67 = SUB41((uint)uVar2 >> 0x10,0);
          pdVar5[0x3825] = dStack67;
          dStack66 = SUB41((uint)uVar2 >> 8,0);
          pdVar5[0x3826] = dStack66;
          dStack65 = SUB41(uVar2,0);
          pdVar5[0x3827] = dStack65;
          uVar2 = *(undefined4 *)(*(int *)(this + iVar4 + 0x2968) + 0x104);
          local_48 = SUB41((uint)uVar2 >> 0x18,0);
          pdVar5[0x386c] = local_48;
          dStack71 = SUB41((uint)uVar2 >> 0x10,0);
          pdVar5[0x386d] = dStack71;
          dStack70 = SUB41((uint)uVar2 >> 8,0);
          pdVar5[0x386e] = dStack70;
          dStack69 = SUB41(uVar2,0);
          pdVar5[0x386f] = dStack69;
          iVar3 = iVar3 + 4;
          iVar4 = iVar4 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80184750) */
/* __thiscall dFile_select_c::DataSelectPaneCopyMove(short,
                                                     short) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneCopyMove(dFile_select_c *this,short param_1,short param_2)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  int unaff_r27;
  int unaff_r28;
  int unaff_r29;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r29 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4902,d_file_select::_4050,d_file_select::_4902,
                                  '\x01',0);
    unaff_r28 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4902,
                                   d_file_select::_4050,d_file_select::_4902,'\x01',0);
    unaff_r27 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4901,d_file_select::_4050,d_file_select::_4901,
                                  '\x01',0);
    this = (dFile_select_c *)
           PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                              (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4901,d_file_select::_4050
                              ,d_file_select::_4901,'\x01',0);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r29 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4901,
                                    d_file_select::_4050,d_file_select::_4901,'\x01',0);
      unaff_r28 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4901,
                                     d_file_select::_4050,d_file_select::_4901,'\x01',0);
      unaff_r27 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4901,
                                    d_file_select::_4050,d_file_select::_4901,'\x01',0);
      this = (dFile_select_c *)
             PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000)
                                       - d_file_select::_4148),d_file_select::_4901,
                                d_file_select::_4050,d_file_select::_4901,'\x01',0);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r29 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4902,
                                      d_file_select::_4050,d_file_select::_4902,'\x01',0);
        unaff_r28 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4902,
                                       d_file_select::_4050,d_file_select::_4902,'\x01',0);
        unaff_r27 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4902,
                                      d_file_select::_4050,d_file_select::_4902,'\x01',0);
        this = (dFile_select_c *)
               PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4902,d_file_select::_4050,d_file_select::_4902,
                                  '\x01',0);
      }
    }
  }
  if ((((unaff_r29 == 1) && (unaff_r28 == 1)) && (unaff_r27 == 1)) &&
     (this == (dFile_select_c *)&DAT_00000001)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80184bb8) */
/* __thiscall dFile_select_c::DataSelectPaneCopyBackMove(short,
                                                         short) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneCopyBackMove(dFile_select_c *this,short param_1,short param_2)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  int unaff_r24;
  int unaff_r26;
  int unaff_r27;
  int unaff_r29;
  int unaff_r30;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r27 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                  d_file_select::_4050,DAT_803e4a53,2);
    unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                   d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                   d_file_select::_4050,DAT_803e4a53,2);
    if (this[0x3925] == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4299,d_file_select::_4050,
                                    d_file_select::_4050,DAT_803e4a53,2);
      unaff_r26 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     d_file_select::_4050,d_file_select::_4299,d_file_select::_4050,
                                     d_file_select::_4050,DAT_803e4a53,2);
      unaff_r24 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
      this = (dFile_select_c *)
             PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000)
                                       - d_file_select::_4148),d_file_select::_4050,
                                d_file_select::_4050,d_file_select::_4050,'\x01',0);
    }
    else {
      unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                    d_file_select::_4050,DAT_803e4a53,2);
      unaff_r26 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                     d_file_select::_4050,DAT_803e4a53,2);
      unaff_r24 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
      this = (dFile_select_c *)
             PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000)
                                       - d_file_select::_4148),d_file_select::_4050,
                                d_file_select::_4050,d_file_select::_4050,'\x01',0);
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r27 = 1;
      unaff_r29 = 1;
      if (this[0x3925] == (dFile_select_c)0x0) {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,
                                      d_file_select::_4050,d_file_select::_4050,'\x01',0);
        unaff_r26 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4050,
                                       d_file_select::_4050,d_file_select::_4050,'\x01',0);
        unaff_r24 = 1;
        this = (dFile_select_c *)&DAT_00000001;
      }
      else {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4196,d_file_select::_4050
                                      ,d_file_select::_4050,DAT_803e4a53,2);
        unaff_r26 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       d_file_select::_4050,d_file_select::_4196,
                                       d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
        unaff_r24 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,
                                      d_file_select::_4050,d_file_select::_4050,'\x01',0);
        this = (dFile_select_c *)
               PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                  '\x01',0);
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r27 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4197,d_file_select::_4050
                                      ,d_file_select::_4050,DAT_803e4a53,2);
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       d_file_select::_4050,d_file_select::_4197,
                                       d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
        if (this[0x3925] == (dFile_select_c)0x0) {
          unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                        d_file_select::_4050,d_file_select::_4299,
                                        d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
          unaff_r26 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                         d_file_select::_4050,d_file_select::_4299,
                                         d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
          unaff_r24 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                        (float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4050,
                                        d_file_select::_4050,d_file_select::_4050,'\x01',0);
          this = (dFile_select_c *)
                 PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
        }
        else {
          unaff_r30 = 1;
          unaff_r26 = 1;
          unaff_r24 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                        (float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4050,
                                        d_file_select::_4050,d_file_select::_4050,'\x01',0);
          this = (dFile_select_c *)
                 PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
        }
      }
    }
  }
  if ((((unaff_r30 == 1) && (unaff_r26 == 1)) && (unaff_r24 == 1)) &&
     (((this == (dFile_select_c *)&DAT_00000001 && (unaff_r27 == 1)) && (unaff_r29 == 1)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8018531c) */
/* __thiscall dFile_select_c::DataSelectPaneCopyMove2(short,
                                                      short) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneCopyMove2(dFile_select_c *this,short param_1,short param_2)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  int unaff_r28;
  int unaff_r29;
  int unaff_r30;
  
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    if (this[0x3925] == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4901,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4901,'\0',1);
      unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     d_file_select::_4050,d_file_select::_4901,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4901,'\0',1);
      unaff_r28 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                    d_file_select::_4299,'\0',2);
      this = (dFile_select_c *)
             PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                d_file_select::_4299,'\0',2);
    }
    else {
      unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4902,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4902,'\0',1);
      unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     d_file_select::_4050,d_file_select::_4902,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4902,'\0',1);
      unaff_r28 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                    d_file_select::_4196,DAT_803e4a53,2);
      this = (dFile_select_c *)
             PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                d_file_select::_4196,DAT_803e4a53,2);
    }
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      if (this[0x3925] == (dFile_select_c)0x0) {
        unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4901,d_file_select::_4050
                                      ,d_file_select::_4050,'\0',2);
        unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                       d_file_select::_4050,d_file_select::_4901,
                                       d_file_select::_4050,d_file_select::_4050,'\0',2);
        unaff_r28 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4901,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4901,'\0',1);
        this = (dFile_select_c *)
               PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4901,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4901,'\0',1);
      }
      else {
        unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4901,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4901,'\0',1);
        unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       d_file_select::_4050,d_file_select::_4901,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4901,'\0',1);
        unaff_r28 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4901,d_file_select::_4050
                                      ,d_file_select::_4196,DAT_803e4a53,2);
        this = (dFile_select_c *)
               PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                  d_file_select::_4196,DAT_803e4a53,2);
      }
    }
    else {
      if ((byte)dVar1 < 3) {
        if (this[0x3925] == (dFile_select_c)0x0) {
          unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                        d_file_select::_4050,d_file_select::_4902,
                                        (float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4902,'\0',1);
          unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                         d_file_select::_4050,d_file_select::_4902,
                                         (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8c ^ 0x80000000) -
                                                d_file_select::_4148),d_file_select::_4902,'\0',1);
          unaff_r28 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                        d_file_select::_4050,d_file_select::_4902,
                                        d_file_select::_4050,d_file_select::_4299,'\0',2);
          this = (dFile_select_c *)
                 PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                    d_file_select::_4299,'\0',2);
        }
        else {
          unaff_r30 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                        d_file_select::_4050,d_file_select::_4902,
                                        (float)((double)CONCAT44(0x43300000,
                                                                 (int)DAT_803e4a8c ^ 0x80000000) -
                                               d_file_select::_4148),d_file_select::_4902,'\0',1);
          unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                         d_file_select::_4050,d_file_select::_4902,
                                         (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_803e4a8c ^ 0x80000000) -
                                                d_file_select::_4148),d_file_select::_4902,'\0',1);
          unaff_r28 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                        d_file_select::_4050,d_file_select::_4902,
                                        d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
          this = (dFile_select_c *)
                 PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                    d_file_select::_4050,DAT_803e4a53,2);
        }
      }
    }
  }
  if ((((unaff_r30 == 1) && (unaff_r29 == 1)) && (unaff_r28 == 1)) &&
     (this == (dFile_select_c *)&DAT_00000001)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80186a58) */
/* __thiscall dFile_select_c::DataSelectPaneCopyColorMove(short,
                                                          unsigned char,
                                                          int) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneCopyColorMove
          (dFile_select_c *this,short param_1,uchar param_2,int param_3)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  dFile_select_c *pdVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  undefined local_298;
  undefined uStack663;
  undefined uStack662;
  undefined uStack661;
  undefined local_294;
  undefined uStack659;
  undefined uStack658;
  undefined uStack657;
  undefined local_290;
  undefined uStack655;
  undefined uStack654;
  undefined uStack653;
  undefined local_28c;
  undefined uStack651;
  undefined uStack650;
  undefined uStack649;
  undefined local_288;
  undefined uStack647;
  undefined uStack646;
  undefined uStack645;
  undefined local_284;
  undefined uStack643;
  undefined uStack642;
  undefined uStack641;
  undefined local_280;
  undefined uStack639;
  undefined uStack638;
  undefined uStack637;
  undefined local_27c;
  undefined uStack635;
  undefined uStack634;
  undefined uStack633;
  undefined local_270;
  undefined uStack623;
  undefined uStack622;
  undefined uStack621;
  undefined local_26c;
  undefined uStack619;
  undefined uStack618;
  undefined uStack617;
  undefined local_268;
  undefined uStack615;
  undefined uStack614;
  undefined uStack613;
  undefined local_264;
  undefined uStack611;
  undefined uStack610;
  undefined uStack609;
  undefined local_260;
  undefined uStack607;
  undefined uStack606;
  undefined uStack605;
  undefined local_25c;
  undefined uStack603;
  undefined uStack602;
  undefined uStack601;
  undefined local_258;
  undefined uStack599;
  undefined uStack598;
  undefined uStack597;
  undefined local_254;
  undefined uStack595;
  undefined uStack594;
  undefined uStack593;
  undefined local_248;
  undefined uStack583;
  undefined uStack582;
  undefined uStack581;
  undefined local_244;
  undefined uStack579;
  undefined uStack578;
  undefined uStack577;
  undefined local_240;
  undefined uStack575;
  undefined uStack574;
  undefined uStack573;
  undefined local_23c;
  undefined uStack571;
  undefined uStack570;
  undefined uStack569;
  undefined local_238;
  undefined uStack567;
  undefined uStack566;
  undefined uStack565;
  undefined local_234;
  undefined uStack563;
  undefined uStack562;
  undefined uStack561;
  undefined local_230;
  undefined uStack559;
  undefined uStack558;
  undefined uStack557;
  undefined local_22c;
  undefined uStack555;
  undefined uStack554;
  undefined uStack553;
  undefined local_228;
  undefined uStack551;
  undefined uStack550;
  undefined uStack549;
  undefined local_224;
  undefined uStack547;
  undefined uStack546;
  undefined uStack545;
  undefined4 local_220 [2];
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c [2];
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8 [2];
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4 [2];
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4 [3];
  undefined4 local_1c8;
  undefined4 auStack432 [3];
  undefined4 local_1a4;
  undefined4 auStack396 [3];
  undefined4 local_180;
  undefined4 auStack360 [3];
  undefined4 local_15c;
  double local_138;
  undefined4 local_130;
  uint uStack300;
  double local_128;
  double local_120;
  undefined4 local_118;
  uint uStack276;
  double local_110;
  double local_108;
  undefined4 local_100;
  uint uStack252;
  double local_f8;
  double local_f0;
  undefined4 local_e8;
  uint uStack228;
  double local_e0;
  double local_d8;
  undefined4 local_d0;
  uint uStack204;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  undefined4 local_a0;
  uint uStack156;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  undefined4 local_70;
  uint uStack108;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  undefined4 local_40;
  uint uStack60;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  
  local_220[1] = 0xffffffff;
  local_220[0] = 0xffffffff;
  local_1dc = 0xffffffff;
  local_1d8 = 0xffffffff;
  local_1d4[0] = 0xffffffff;
  local_1d4[1] = 0xffffffff;
  local_1d4[2] = 0xffffffff;
  local_1f0 = 0xffffffff;
  local_1ec = 0xffffffff;
  local_1e8 = 0xffffffff;
  local_1e4[0] = 0xffffffff;
  local_1e4[1] = 0xffffffff;
  local_204 = 0xffffffff;
  local_200 = 0xffffffff;
  local_1fc = 0xffffffff;
  local_1f8[0] = 0xffffffff;
  local_1f8[1] = 0xffffffff;
  local_218 = 0xffffffff;
  local_214 = 0xffffffff;
  local_210 = 0xffffffff;
  local_20c[0] = 0xffffffff;
  local_20c[1] = 0xffffffff;
  Runtime.PPCEABI.H::__construct_array(&local_15c,JUtility::TColor::TColor,(undefined *)0x0,4,9);
  Runtime.PPCEABI.H::__construct_array(&local_180,JUtility::TColor::TColor,(undefined *)0x0,4,9);
  Runtime.PPCEABI.H::__construct_array(&local_1a4,JUtility::TColor::TColor,(undefined *)0x0,4,9);
  Runtime.PPCEABI.H::__construct_array(&local_1c8,JUtility::TColor::TColor,(undefined *)0x0,4,9);
  if (param_1 < 0) {
    uVar3 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar3 = 1;
    }
    else {
      dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease((uint)param_2,(int)param_1,0);
      if (param_3 == 1) {
        iVar4 = 0;
        iVar7 = 5;
        do {
          pdVar5 = this + iVar4;
          local_138 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37d8]);
          *(char *)((int)&local_1dc + iVar4) =
               (char)(int)((float)(local_138 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x37d8]) -
                                                  d_file_select::_4475) - d_file_select::_5719) *
                                 dVar9));
          local_120 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37d9]);
          *(char *)((int)&local_1dc + iVar4 + 1) =
               (char)(int)((float)(local_120 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x37d9]) -
                                                  d_file_select::_4475) - d_file_select::_5719) *
                                 dVar9));
          local_108 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37da]);
          *(char *)((int)&local_1dc + iVar4 + 2) =
               (char)(int)((float)(local_108 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x37da]) -
                                                  d_file_select::_4475) - d_file_select::_5719) *
                                 dVar9));
          *(dFile_select_c *)((int)&local_1dc + iVar4 + 3) = pdVar5[0x37db];
          local_f0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3804]);
          *(char *)((int)&local_204 + iVar4) =
               (char)(int)((float)(local_f0 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x3804]) -
                                                  d_file_select::_4475) - d_file_select::_5720) *
                                 dVar9));
          local_d8 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3805]);
          *(char *)((int)&local_204 + iVar4 + 1) =
               (char)(int)((float)(local_d8 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x3805]) -
                                                  d_file_select::_4475) - d_file_select::_5720) *
                                 dVar9));
          local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3806]);
          local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3806]);
          *(char *)((int)&local_204 + iVar4 + 2) =
               (char)(int)((float)(local_c0 - d_file_select::_4475) -
                          (float)((double)((float)(local_b8 - d_file_select::_4475) -
                                          d_file_select::_5720) * dVar9));
          *(dFile_select_c *)((int)&local_204 + iVar4 + 3) = pdVar5[0x3807];
          local_a8 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ec]);
          *(char *)((int)&local_1f0 + iVar4) =
               (char)(int)((float)(local_a8 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x37ec]) -
                                                  d_file_select::_4475) - d_file_select::_5721) *
                                 dVar9));
          local_90 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ed]);
          local_88 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ed]);
          *(char *)((int)&local_1f0 + iVar4 + 1) =
               (char)(int)((float)(local_90 - d_file_select::_4475) -
                          (float)((double)((float)(local_88 - d_file_select::_4475) -
                                          d_file_select::_5721) * dVar9));
          local_78 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ee]);
          *(char *)((int)&local_1f0 + iVar4 + 2) =
               (char)(int)((float)(local_78 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x37ee]) -
                                                  d_file_select::_4475) - d_file_select::_5721) *
                                 dVar9));
          *(dFile_select_c *)((int)&local_1f0 + iVar4 + 3) = pdVar5[0x37ef];
          local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3818]);
          local_58 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3818]);
          *(char *)((int)&local_218 + iVar4) =
               (char)(int)((float)(local_60 - d_file_select::_4475) -
                          (float)((double)((float)(local_58 - d_file_select::_4475) -
                                          d_file_select::_5722) * dVar9));
          local_48 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3819]);
          *(char *)((int)&local_218 + iVar4 + 1) =
               (char)(int)((float)(local_48 - d_file_select::_4475) -
                          (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                    (uint)(byte)pdVar5[0x3819]) -
                                                  d_file_select::_4475) - d_file_select::_5722) *
                                 dVar9));
          local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x381a]);
          local_28 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x381a]);
          *(char *)((int)&local_218 + iVar4 + 2) =
               (char)(int)((float)(local_30 - d_file_select::_4475) -
                          (float)((double)((float)(local_28 - d_file_select::_4475) -
                                          d_file_select::_5722) * dVar9));
          *(dFile_select_c *)((int)&local_218 + iVar4 + 3) = pdVar5[0x381b];
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3800]);
        local_28 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3800]);
        local_38 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3801]);
        local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3802]);
        local_58 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3802]);
        uVar3 = CONCAT31(CONCAT21(CONCAT11((char)(int)((float)(local_20 - d_file_select::_4475) -
                                                      (float)((double)(float)(local_28 -
                                                                             d_file_select::_4475) *
                                                             dVar9)),
                                           (char)(int)((float)(local_38 - d_file_select::_4475) -
                                                      (float)((double)(float)((double)CONCAT44(
                                                  0x43300000,(uint)(byte)this[0x3801]) -
                                                  d_file_select::_4475) * dVar9))),
                                  (char)(int)((float)(local_50 - d_file_select::_4475) -
                                             (float)((double)(float)(local_58 - d_file_select::_4475
                                                                    ) * dVar9))),this[0x3803]);
        local_68 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382c]);
        local_80 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382d]);
        local_88 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382d]);
        local_98 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382e]);
        uVar2 = CONCAT31(CONCAT21(CONCAT11((char)(int)((float)(local_68 - d_file_select::_4475) -
                                                      (float)((double)((float)((double)CONCAT44(
                                                  0x43300000,(uint)(byte)this[0x382c]) -
                                                  d_file_select::_4475) - d_file_select::_5720) *
                                                  dVar9)),
                                           (char)(int)((float)(local_80 - d_file_select::_4475) -
                                                      (float)((double)((float)(local_88 -
                                                                              d_file_select::_4475)
                                                                      - d_file_select::_5720) *
                                                             dVar9))),
                                  (char)(int)((float)(local_98 - d_file_select::_4475) -
                                             (float)((double)((float)((double)CONCAT44(0x43300000,
                                                                                       (uint)(byte)
                                                  this[0x382e]) - d_file_select::_4475) -
                                                  d_file_select::_5720) * dVar9))),this[0x382f]);
        iVar4 = 0;
        iVar7 = 9;
        do {
          pdVar5 = this + iVar4;
          local_20 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3830]);
          local_28 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3830]);
          iVar8 = (int)((float)(local_20 - d_file_select::_4475) -
                       (float)((double)((float)(local_28 - d_file_select::_4475) -
                                       d_file_select::_5722) * dVar9));
          local_30 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4) = (char)iVar8;
          uStack60 = (uint)(byte)pdVar5[0x3831];
          local_38 = (double)CONCAT44(0x43300000,uStack60);
          local_40 = 0x43300000;
          iVar8 = (int)((float)(local_38 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack60) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_48 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4 + 1) = (char)iVar8;
          local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3832]);
          local_58 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3832]);
          iVar8 = (int)((float)(local_50 - d_file_select::_4475) -
                       (float)((double)((float)(local_58 - d_file_select::_4475) -
                                       d_file_select::_5722) * dVar9));
          local_60 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_15c + iVar4 + 3) = pdVar5[0x3833];
          uStack108 = (uint)(byte)pdVar5[0x3878];
          local_68 = (double)CONCAT44(0x43300000,uStack108);
          local_70 = 0x43300000;
          iVar8 = (int)((float)(local_68 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack108) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_78 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4) = (char)iVar8;
          local_80 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3879]);
          local_88 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3879]);
          iVar8 = (int)((float)(local_80 - d_file_select::_4475) -
                       (float)((double)((float)(local_88 - d_file_select::_4475) -
                                       d_file_select::_5722) * dVar9));
          local_90 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4 + 1) = (char)iVar8;
          uStack156 = (uint)(byte)pdVar5[0x387a];
          local_98 = (double)CONCAT44(0x43300000,uStack156);
          local_a0 = 0x43300000;
          iVar8 = (int)((float)(local_98 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack156) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_a8 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_1a4 + iVar4 + 3) = pdVar5[0x387b];
          local_b0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3854]);
          local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3854]);
          iVar8 = (int)((float)(local_b0 - d_file_select::_4475) -
                       (float)((double)((float)(local_b8 - d_file_select::_4475) -
                                       d_file_select::_5721) * dVar9));
          local_c0 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4) = (char)iVar8;
          uStack204 = (uint)(byte)pdVar5[0x3855];
          local_c8 = (double)CONCAT44(0x43300000,uStack204);
          local_d0 = 0x43300000;
          iVar8 = (int)((float)(local_c8 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack204) -
                                               d_file_select::_4475) - d_file_select::_5721) * dVar9
                              ));
          local_d8 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4 + 1) = (char)iVar8;
          uStack228 = (uint)(byte)pdVar5[0x3856];
          local_e0 = (double)CONCAT44(0x43300000,uStack228);
          local_e8 = 0x43300000;
          iVar8 = (int)((float)(local_e0 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack228) -
                                               d_file_select::_4475) - d_file_select::_5721) * dVar9
                              ));
          local_f0 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_180 + iVar4 + 3) = pdVar5[0x3857];
          uStack252 = (uint)(byte)pdVar5[0x389c];
          local_f8 = (double)CONCAT44(0x43300000,uStack252);
          local_100 = 0x43300000;
          iVar8 = (int)((float)(local_f8 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack252) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_108 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4) = (char)iVar8;
          uStack276 = (uint)(byte)pdVar5[0x389d];
          local_110 = (double)CONCAT44(0x43300000,uStack276);
          local_118 = 0x43300000;
          iVar8 = (int)((float)(local_110 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack276) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_120 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4 + 1) = (char)iVar8;
          uStack300 = (uint)(byte)pdVar5[0x389e];
          local_128 = (double)CONCAT44(0x43300000,uStack300);
          local_130 = 0x43300000;
          iVar8 = (int)((float)(local_128 - d_file_select::_4475) -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uStack300) -
                                               d_file_select::_4475) - d_file_select::_5722) * dVar9
                              ));
          local_138 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_1c8 + iVar4 + 3) = pdVar5[0x389f];
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      else {
        iVar4 = 0;
        iVar7 = 5;
        do {
          pdVar5 = this + iVar4;
          local_20 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37d8]);
          *(char *)((int)&local_1dc + iVar4) =
               (char)(int)(d_file_select::_5719 -
                          (float)((double)(d_file_select::_5719 -
                                          (float)(local_20 - d_file_select::_4475)) * dVar9));
          local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37d9]);
          *(char *)((int)&local_1dc + iVar4 + 1) =
               (char)(int)(d_file_select::_5719 -
                          (float)((double)(d_file_select::_5719 -
                                          (float)(local_30 - d_file_select::_4475)) * dVar9));
          *(char *)((int)&local_1dc + iVar4 + 2) =
               (char)(int)(d_file_select::_5719 -
                          (float)((double)(d_file_select::_5719 -
                                          (float)((double)CONCAT44(0x43300000,
                                                                   (uint)(byte)pdVar5[0x37da]) -
                                                 d_file_select::_4475)) * dVar9));
          *(dFile_select_c *)((int)&local_1dc + iVar4 + 3) = pdVar5[0x37db];
          local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3804]);
          *(char *)((int)&local_204 + iVar4) =
               (char)(int)(d_file_select::_5720 -
                          (float)((double)(d_file_select::_5720 -
                                          (float)(local_50 - d_file_select::_4475)) * dVar9));
          local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3805]);
          *(char *)((int)&local_204 + iVar4 + 1) =
               (char)(int)(d_file_select::_5720 -
                          (float)((double)(d_file_select::_5720 -
                                          (float)(local_60 - d_file_select::_4475)) * dVar9));
          *(char *)((int)&local_204 + iVar4 + 2) =
               (char)(int)(d_file_select::_5720 -
                          (float)((double)(d_file_select::_5720 -
                                          (float)((double)CONCAT44(0x43300000,
                                                                   (uint)(byte)pdVar5[0x3806]) -
                                                 d_file_select::_4475)) * dVar9));
          *(dFile_select_c *)((int)&local_204 + iVar4 + 3) = pdVar5[0x3807];
          local_80 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ec]);
          *(char *)((int)&local_1f0 + iVar4) =
               (char)(int)(d_file_select::_5721 -
                          (float)((double)(d_file_select::_5721 -
                                          (float)(local_80 - d_file_select::_4475)) * dVar9));
          local_90 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x37ed]);
          *(char *)((int)&local_1f0 + iVar4 + 1) =
               (char)(int)(d_file_select::_5721 -
                          (float)((double)(d_file_select::_5721 -
                                          (float)(local_90 - d_file_select::_4475)) * dVar9));
          *(char *)((int)&local_1f0 + iVar4 + 2) =
               (char)(int)(d_file_select::_5721 -
                          (float)((double)(d_file_select::_5721 -
                                          (float)((double)CONCAT44(0x43300000,
                                                                   (uint)(byte)pdVar5[0x37ee]) -
                                                 d_file_select::_4475)) * dVar9));
          *(dFile_select_c *)((int)&local_1f0 + iVar4 + 3) = pdVar5[0x37ef];
          local_b0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3818]);
          *(char *)((int)&local_218 + iVar4) =
               (char)(int)(d_file_select::_5722 -
                          (float)((double)(d_file_select::_5722 -
                                          (float)(local_b0 - d_file_select::_4475)) * dVar9));
          local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3819]);
          *(char *)((int)&local_218 + iVar4 + 1) =
               (char)(int)(d_file_select::_5722 -
                          (float)((double)(d_file_select::_5722 -
                                          (float)(local_c0 - d_file_select::_4475)) * dVar9));
          *(char *)((int)&local_218 + iVar4 + 2) =
               (char)(int)(d_file_select::_5722 -
                          (float)((double)(d_file_select::_5722 -
                                          (float)((double)CONCAT44(0x43300000,
                                                                   (uint)(byte)pdVar5[0x381a]) -
                                                 d_file_select::_4475)) * dVar9));
          *(dFile_select_c *)((int)&local_218 + iVar4 + 3) = pdVar5[0x381b];
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        local_20 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3800]);
        local_30 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x3801]);
        uVar3 = CONCAT31(CONCAT21(CONCAT11((char)(int)-(float)(-(double)(float)(local_20 -
                                                                               d_file_select::_4475)
                                                              * dVar9),
                                           (char)(int)-(float)(-(double)(float)(local_30 -
                                                                               d_file_select::_4475)
                                                              * dVar9)),
                                  (char)(int)-(float)(-(double)(float)((double)CONCAT44(0x43300000,
                                                                                        (uint)(byte)
                                                  this[0x3802]) - d_file_select::_4475) * dVar9)),
                         this[0x3803]);
        local_50 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382c]);
        local_60 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x382d]);
        uVar2 = CONCAT31(CONCAT21(CONCAT11((char)(int)(d_file_select::_5720 -
                                                      (float)((double)(d_file_select::_5720 -
                                                                      (float)(local_50 -
                                                                             d_file_select::_4475))
                                                             * dVar9)),
                                           (char)(int)(d_file_select::_5720 -
                                                      (float)((double)(d_file_select::_5720 -
                                                                      (float)(local_60 -
                                                                             d_file_select::_4475))
                                                             * dVar9))),
                                  (char)(int)(d_file_select::_5720 -
                                             (float)((double)(d_file_select::_5720 -
                                                             (float)((double)CONCAT44(0x43300000,
                                                                                      (uint)(byte)
                                                  this[0x382e]) - d_file_select::_4475)) * dVar9))),
                         this[0x382f]);
        iVar4 = 0;
        iVar7 = 9;
        do {
          pdVar5 = this + iVar4;
          local_20 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3830]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_20 - d_file_select::_4475)) * dVar9));
          local_28 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4) = (char)iVar8;
          local_30 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3831]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_30 - d_file_select::_4475)) * dVar9));
          local_38 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4 + 1) = (char)iVar8;
          uStack60 = (uint)(byte)pdVar5[0x3832];
          local_40 = 0x43300000;
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)((double)CONCAT44(0x43300000,
                                                                (uint)(byte)pdVar5[0x3832]) -
                                              d_file_select::_4475)) * dVar9));
          local_48 = (double)(longlong)iVar8;
          *(char *)((int)&local_15c + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_15c + iVar4 + 3) = pdVar5[0x3833];
          local_50 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3878]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_50 - d_file_select::_4475)) * dVar9));
          local_58 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4) = (char)iVar8;
          local_60 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3879]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_60 - d_file_select::_4475)) * dVar9));
          local_68 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4 + 1) = (char)iVar8;
          uStack108 = (uint)(byte)pdVar5[0x387a];
          local_70 = 0x43300000;
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)((double)CONCAT44(0x43300000,
                                                                (uint)(byte)pdVar5[0x387a]) -
                                              d_file_select::_4475)) * dVar9));
          local_78 = (double)(longlong)iVar8;
          *(char *)((int)&local_1a4 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_1a4 + iVar4 + 3) = pdVar5[0x387b];
          local_80 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3854]);
          iVar8 = (int)(d_file_select::_5721 -
                       (float)((double)(d_file_select::_5721 -
                                       (float)(local_80 - d_file_select::_4475)) * dVar9));
          local_88 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4) = (char)iVar8;
          local_90 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x3855]);
          iVar8 = (int)(d_file_select::_5721 -
                       (float)((double)(d_file_select::_5721 -
                                       (float)(local_90 - d_file_select::_4475)) * dVar9));
          local_98 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4 + 1) = (char)iVar8;
          uStack156 = (uint)(byte)pdVar5[0x3856];
          local_a0 = 0x43300000;
          iVar8 = (int)(d_file_select::_5721 -
                       (float)((double)(d_file_select::_5721 -
                                       (float)((double)CONCAT44(0x43300000,
                                                                (uint)(byte)pdVar5[0x3856]) -
                                              d_file_select::_4475)) * dVar9));
          local_a8 = (double)(longlong)iVar8;
          *(char *)((int)&local_180 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_180 + iVar4 + 3) = pdVar5[0x3857];
          local_b0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x389c]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_b0 - d_file_select::_4475)) * dVar9));
          local_b8 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4) = (char)iVar8;
          local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar5[0x389d]);
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)(local_c0 - d_file_select::_4475)) * dVar9));
          local_c8 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4 + 1) = (char)iVar8;
          uStack204 = (uint)(byte)pdVar5[0x389e];
          local_d0 = 0x43300000;
          iVar8 = (int)(d_file_select::_5722 -
                       (float)((double)(d_file_select::_5722 -
                                       (float)((double)CONCAT44(0x43300000,
                                                                (uint)(byte)pdVar5[0x389e]) -
                                              d_file_select::_4475)) * dVar9));
          local_d8 = (double)(longlong)iVar8;
          *(char *)((int)&local_1c8 + iVar4 + 2) = (char)iVar8;
          *(dFile_select_c *)((int)&local_1c8 + iVar4 + 3) = pdVar5[0x389f];
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      dVar1 = this[0x3924];
      uStack545 = (undefined)uVar3;
      uStack546 = (undefined)((uint)uVar3 >> 8);
      uStack547 = (undefined)((uint)uVar3 >> 0x10);
      local_224 = (undefined)((uint)uVar3 >> 0x18);
      uStack549 = (undefined)uVar2;
      uStack550 = (undefined)((uint)uVar2 >> 8);
      uStack551 = (undefined)((uint)uVar2 >> 0x10);
      local_228 = (undefined)((uint)uVar2 >> 0x18);
      if (dVar1 == (dFile_select_c)0x1) {
        iVar4 = *(int *)(this + 0x15f0);
        *(undefined *)(iVar4 + 0x108) = local_224;
        *(undefined *)(iVar4 + 0x109) = uStack547;
        *(undefined *)(iVar4 + 0x10a) = uStack546;
        *(undefined *)(iVar4 + 0x10b) = uStack545;
        *(undefined *)(iVar4 + 0x104) = local_228;
        *(undefined *)(iVar4 + 0x105) = uStack551;
        *(undefined *)(iVar4 + 0x106) = uStack550;
        *(undefined *)(iVar4 + 0x107) = uStack549;
        iVar4 = 0x70;
        iVar7 = 8;
        iVar8 = 5;
        do {
          uVar3 = *(undefined4 *)((int)local_20c + iVar7);
          uVar2 = *(undefined4 *)((int)local_1e4 + iVar7);
          iVar6 = *(int *)(this + iVar4 + 0x15b8);
          local_254 = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar6 + 0x108) = local_254;
          uStack595 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar6 + 0x109) = uStack595;
          uStack594 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar6 + 0x10a) = uStack594;
          uStack593 = (undefined)uVar2;
          *(undefined *)(iVar6 + 0x10b) = uStack593;
          local_258 = (undefined)((uint)uVar3 >> 0x18);
          *(undefined *)(iVar6 + 0x104) = local_258;
          uStack599 = (undefined)((uint)uVar3 >> 0x10);
          *(undefined *)(iVar6 + 0x105) = uStack599;
          uStack598 = (undefined)((uint)uVar3 >> 8);
          *(undefined *)(iVar6 + 0x106) = uStack598;
          uStack597 = (undefined)uVar3;
          *(undefined *)(iVar6 + 0x107) = uStack597;
          uVar3 = *(undefined4 *)((int)local_220 + iVar7);
          uVar2 = *(undefined4 *)((int)local_1f8 + iVar7);
          iVar6 = *(int *)(this + iVar4 + 0x16d0);
          local_25c = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar6 + 0x108) = local_25c;
          uStack603 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar6 + 0x109) = uStack603;
          uStack602 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar6 + 0x10a) = uStack602;
          uStack601 = (undefined)uVar2;
          *(undefined *)(iVar6 + 0x10b) = uStack601;
          local_260 = (undefined)((uint)uVar3 >> 0x18);
          *(undefined *)(iVar6 + 0x104) = local_260;
          uStack607 = (undefined)((uint)uVar3 >> 0x10);
          *(undefined *)(iVar6 + 0x105) = uStack607;
          uStack606 = (undefined)((uint)uVar3 >> 8);
          *(undefined *)(iVar6 + 0x106) = uStack606;
          uStack605 = (undefined)uVar3;
          *(undefined *)(iVar6 + 0x107) = uStack605;
          iVar4 = iVar4 + 0x38;
          iVar7 = iVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        iVar4 = 0xa8;
        iVar7 = 0xc;
        iVar8 = 9;
        do {
          uVar3 = *(undefined4 *)((int)auStack432 + iVar7);
          uVar2 = *(undefined4 *)((int)auStack360 + iVar7);
          iVar6 = *(int *)(this + iVar4 + 0x2310);
          local_264 = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar6 + 0x108) = local_264;
          uStack611 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar6 + 0x109) = uStack611;
          uStack610 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar6 + 0x10a) = uStack610;
          uStack609 = (undefined)uVar2;
          *(undefined *)(iVar6 + 0x10b) = uStack609;
          local_268 = (undefined)((uint)uVar3 >> 0x18);
          *(undefined *)(iVar6 + 0x104) = local_268;
          uStack615 = (undefined)((uint)uVar3 >> 0x10);
          *(undefined *)(iVar6 + 0x105) = uStack615;
          uStack614 = (undefined)((uint)uVar3 >> 8);
          *(undefined *)(iVar6 + 0x106) = uStack614;
          uStack613 = (undefined)uVar3;
          *(undefined *)(iVar6 + 0x107) = uStack613;
          uVar3 = *(undefined4 *)((int)local_1d4 + iVar7);
          uVar2 = *(undefined4 *)((int)auStack396 + iVar7);
          iVar6 = *(int *)(this + iVar4 + 0x2508);
          local_26c = (undefined)((uint)uVar2 >> 0x18);
          *(undefined *)(iVar6 + 0x108) = local_26c;
          uStack619 = (undefined)((uint)uVar2 >> 0x10);
          *(undefined *)(iVar6 + 0x109) = uStack619;
          uStack618 = (undefined)((uint)uVar2 >> 8);
          *(undefined *)(iVar6 + 0x10a) = uStack618;
          uStack617 = (undefined)uVar2;
          *(undefined *)(iVar6 + 0x10b) = uStack617;
          local_270 = (undefined)((uint)uVar3 >> 0x18);
          *(undefined *)(iVar6 + 0x104) = local_270;
          uStack623 = (undefined)((uint)uVar3 >> 0x10);
          *(undefined *)(iVar6 + 0x105) = uStack623;
          uStack622 = (undefined)((uint)uVar3 >> 8);
          *(undefined *)(iVar6 + 0x106) = uStack622;
          uStack621 = (undefined)uVar3;
          *(undefined *)(iVar6 + 0x107) = uStack621;
          iVar4 = iVar4 + 0x38;
          iVar7 = iVar7 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      else {
        if (dVar1 == (dFile_select_c)0x0) {
          iVar4 = *(int *)(this + 0x1270);
          *(undefined *)(iVar4 + 0x108) = local_224;
          *(undefined *)(iVar4 + 0x109) = uStack547;
          *(undefined *)(iVar4 + 0x10a) = uStack546;
          *(undefined *)(iVar4 + 0x10b) = uStack545;
          *(undefined *)(iVar4 + 0x104) = local_228;
          *(undefined *)(iVar4 + 0x105) = uStack551;
          *(undefined *)(iVar4 + 0x106) = uStack550;
          *(undefined *)(iVar4 + 0x107) = uStack549;
          iVar4 = 0x70;
          iVar7 = 8;
          iVar8 = 5;
          do {
            uVar3 = *(undefined4 *)((int)local_20c + iVar7);
            uVar2 = *(undefined4 *)((int)local_1e4 + iVar7);
            iVar6 = *(int *)(this + iVar4 + 0x1238);
            local_22c = (undefined)((uint)uVar2 >> 0x18);
            *(undefined *)(iVar6 + 0x108) = local_22c;
            uStack555 = (undefined)((uint)uVar2 >> 0x10);
            *(undefined *)(iVar6 + 0x109) = uStack555;
            uStack554 = (undefined)((uint)uVar2 >> 8);
            *(undefined *)(iVar6 + 0x10a) = uStack554;
            uStack553 = (undefined)uVar2;
            *(undefined *)(iVar6 + 0x10b) = uStack553;
            local_230 = (undefined)((uint)uVar3 >> 0x18);
            *(undefined *)(iVar6 + 0x104) = local_230;
            uStack559 = (undefined)((uint)uVar3 >> 0x10);
            *(undefined *)(iVar6 + 0x105) = uStack559;
            uStack558 = (undefined)((uint)uVar3 >> 8);
            *(undefined *)(iVar6 + 0x106) = uStack558;
            uStack557 = (undefined)uVar3;
            *(undefined *)(iVar6 + 0x107) = uStack557;
            uVar3 = *(undefined4 *)((int)local_220 + iVar7);
            uVar2 = *(undefined4 *)((int)local_1f8 + iVar7);
            iVar6 = *(int *)(this + iVar4 + 0x1350);
            local_234 = (undefined)((uint)uVar2 >> 0x18);
            *(undefined *)(iVar6 + 0x108) = local_234;
            uStack563 = (undefined)((uint)uVar2 >> 0x10);
            *(undefined *)(iVar6 + 0x109) = uStack563;
            uStack562 = (undefined)((uint)uVar2 >> 8);
            *(undefined *)(iVar6 + 0x10a) = uStack562;
            uStack561 = (undefined)uVar2;
            *(undefined *)(iVar6 + 0x10b) = uStack561;
            local_238 = (undefined)((uint)uVar3 >> 0x18);
            *(undefined *)(iVar6 + 0x104) = local_238;
            uStack567 = (undefined)((uint)uVar3 >> 0x10);
            *(undefined *)(iVar6 + 0x105) = uStack567;
            uStack566 = (undefined)((uint)uVar3 >> 8);
            *(undefined *)(iVar6 + 0x106) = uStack566;
            uStack565 = (undefined)uVar3;
            *(undefined *)(iVar6 + 0x107) = uStack565;
            iVar4 = iVar4 + 0x38;
            iVar7 = iVar7 + 4;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          iVar4 = 0xa8;
          iVar7 = 0xc;
          iVar8 = 9;
          do {
            uVar3 = *(undefined4 *)((int)auStack432 + iVar7);
            uVar2 = *(undefined4 *)((int)auStack360 + iVar7);
            iVar6 = *(int *)(this + iVar4 + 0x1cb8);
            local_23c = (undefined)((uint)uVar2 >> 0x18);
            *(undefined *)(iVar6 + 0x108) = local_23c;
            uStack571 = (undefined)((uint)uVar2 >> 0x10);
            *(undefined *)(iVar6 + 0x109) = uStack571;
            uStack570 = (undefined)((uint)uVar2 >> 8);
            *(undefined *)(iVar6 + 0x10a) = uStack570;
            uStack569 = (undefined)uVar2;
            *(undefined *)(iVar6 + 0x10b) = uStack569;
            local_240 = (undefined)((uint)uVar3 >> 0x18);
            *(undefined *)(iVar6 + 0x104) = local_240;
            uStack575 = (undefined)((uint)uVar3 >> 0x10);
            *(undefined *)(iVar6 + 0x105) = uStack575;
            uStack574 = (undefined)((uint)uVar3 >> 8);
            *(undefined *)(iVar6 + 0x106) = uStack574;
            uStack573 = (undefined)uVar3;
            *(undefined *)(iVar6 + 0x107) = uStack573;
            uVar3 = *(undefined4 *)((int)local_1d4 + iVar7);
            uVar2 = *(undefined4 *)((int)auStack396 + iVar7);
            iVar6 = *(int *)(this + iVar4 + 0x1eb0);
            local_244 = (undefined)((uint)uVar2 >> 0x18);
            *(undefined *)(iVar6 + 0x108) = local_244;
            uStack579 = (undefined)((uint)uVar2 >> 0x10);
            *(undefined *)(iVar6 + 0x109) = uStack579;
            uStack578 = (undefined)((uint)uVar2 >> 8);
            *(undefined *)(iVar6 + 0x10a) = uStack578;
            uStack577 = (undefined)uVar2;
            *(undefined *)(iVar6 + 0x10b) = uStack577;
            local_248 = (undefined)((uint)uVar3 >> 0x18);
            *(undefined *)(iVar6 + 0x104) = local_248;
            uStack583 = (undefined)((uint)uVar3 >> 0x10);
            *(undefined *)(iVar6 + 0x105) = uStack583;
            uStack582 = (undefined)((uint)uVar3 >> 8);
            *(undefined *)(iVar6 + 0x106) = uStack582;
            uStack581 = (undefined)uVar3;
            *(undefined *)(iVar6 + 0x107) = uStack581;
            iVar4 = iVar4 + 0x38;
            iVar7 = iVar7 + 4;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        else {
          if ((byte)dVar1 < 3) {
            iVar4 = *(int *)(this + 0x1970);
            *(undefined *)(iVar4 + 0x108) = local_224;
            *(undefined *)(iVar4 + 0x109) = uStack547;
            *(undefined *)(iVar4 + 0x10a) = uStack546;
            *(undefined *)(iVar4 + 0x10b) = uStack545;
            *(undefined *)(iVar4 + 0x104) = local_228;
            *(undefined *)(iVar4 + 0x105) = uStack551;
            *(undefined *)(iVar4 + 0x106) = uStack550;
            *(undefined *)(iVar4 + 0x107) = uStack549;
            iVar4 = 0x70;
            iVar7 = 8;
            iVar8 = 5;
            do {
              uVar3 = *(undefined4 *)((int)local_20c + iVar7);
              uVar2 = *(undefined4 *)((int)local_1e4 + iVar7);
              iVar6 = *(int *)(this + iVar4 + 0x1938);
              local_27c = (undefined)((uint)uVar2 >> 0x18);
              *(undefined *)(iVar6 + 0x108) = local_27c;
              uStack635 = (undefined)((uint)uVar2 >> 0x10);
              *(undefined *)(iVar6 + 0x109) = uStack635;
              uStack634 = (undefined)((uint)uVar2 >> 8);
              *(undefined *)(iVar6 + 0x10a) = uStack634;
              uStack633 = (undefined)uVar2;
              *(undefined *)(iVar6 + 0x10b) = uStack633;
              local_280 = (undefined)((uint)uVar3 >> 0x18);
              *(undefined *)(iVar6 + 0x104) = local_280;
              uStack639 = (undefined)((uint)uVar3 >> 0x10);
              *(undefined *)(iVar6 + 0x105) = uStack639;
              uStack638 = (undefined)((uint)uVar3 >> 8);
              *(undefined *)(iVar6 + 0x106) = uStack638;
              uStack637 = (undefined)uVar3;
              *(undefined *)(iVar6 + 0x107) = uStack637;
              uVar3 = *(undefined4 *)((int)local_220 + iVar7);
              uVar2 = *(undefined4 *)((int)local_1f8 + iVar7);
              iVar6 = *(int *)(this + iVar4 + 0x1a50);
              local_284 = (undefined)((uint)uVar2 >> 0x18);
              *(undefined *)(iVar6 + 0x108) = local_284;
              uStack643 = (undefined)((uint)uVar2 >> 0x10);
              *(undefined *)(iVar6 + 0x109) = uStack643;
              uStack642 = (undefined)((uint)uVar2 >> 8);
              *(undefined *)(iVar6 + 0x10a) = uStack642;
              uStack641 = (undefined)uVar2;
              *(undefined *)(iVar6 + 0x10b) = uStack641;
              local_288 = (undefined)((uint)uVar3 >> 0x18);
              *(undefined *)(iVar6 + 0x104) = local_288;
              uStack647 = (undefined)((uint)uVar3 >> 0x10);
              *(undefined *)(iVar6 + 0x105) = uStack647;
              uStack646 = (undefined)((uint)uVar3 >> 8);
              *(undefined *)(iVar6 + 0x106) = uStack646;
              uStack645 = (undefined)uVar3;
              *(undefined *)(iVar6 + 0x107) = uStack645;
              iVar4 = iVar4 + 0x38;
              iVar7 = iVar7 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            iVar4 = 0xa8;
            iVar7 = 0xc;
            iVar8 = 9;
            do {
              uVar3 = *(undefined4 *)((int)auStack432 + iVar7);
              uVar2 = *(undefined4 *)((int)auStack360 + iVar7);
              iVar6 = *(int *)(this + iVar4 + 0x2968);
              local_28c = (undefined)((uint)uVar2 >> 0x18);
              *(undefined *)(iVar6 + 0x108) = local_28c;
              uStack651 = (undefined)((uint)uVar2 >> 0x10);
              *(undefined *)(iVar6 + 0x109) = uStack651;
              uStack650 = (undefined)((uint)uVar2 >> 8);
              *(undefined *)(iVar6 + 0x10a) = uStack650;
              uStack649 = (undefined)uVar2;
              *(undefined *)(iVar6 + 0x10b) = uStack649;
              local_290 = (undefined)((uint)uVar3 >> 0x18);
              *(undefined *)(iVar6 + 0x104) = local_290;
              uStack655 = (undefined)((uint)uVar3 >> 0x10);
              *(undefined *)(iVar6 + 0x105) = uStack655;
              uStack654 = (undefined)((uint)uVar3 >> 8);
              *(undefined *)(iVar6 + 0x106) = uStack654;
              uStack653 = (undefined)uVar3;
              *(undefined *)(iVar6 + 0x107) = uStack653;
              uVar3 = *(undefined4 *)((int)local_1d4 + iVar7);
              uVar2 = *(undefined4 *)((int)auStack396 + iVar7);
              iVar6 = *(int *)(this + iVar4 + 0x2b60);
              local_294 = (undefined)((uint)uVar2 >> 0x18);
              *(undefined *)(iVar6 + 0x108) = local_294;
              uStack659 = (undefined)((uint)uVar2 >> 0x10);
              *(undefined *)(iVar6 + 0x109) = uStack659;
              uStack658 = (undefined)((uint)uVar2 >> 8);
              *(undefined *)(iVar6 + 0x10a) = uStack658;
              uStack657 = (undefined)uVar2;
              *(undefined *)(iVar6 + 0x10b) = uStack657;
              local_298 = (undefined)((uint)uVar3 >> 0x18);
              *(undefined *)(iVar6 + 0x104) = local_298;
              uStack663 = (undefined)((uint)uVar3 >> 0x10);
              *(undefined *)(iVar6 + 0x105) = uStack663;
              uStack662 = (undefined)((uint)uVar3 >> 8);
              *(undefined *)(iVar6 + 0x106) = uStack662;
              uStack661 = (undefined)uVar3;
              *(undefined *)(iVar6 + 0x107) = uStack661;
              iVar4 = iVar4 + 0x38;
              iVar7 = iVar7 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


namespace JUtility {

namespace TColor {

/* __thiscall TColor(void) */

void TColor(TColor *this)

{
  *this = 0xffffffff;
  return;
}

}
}

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80187108) */
/* __thiscall dFile_select_c::DataSelectPaneBackFromCopyMove(unsigned char,
                                                             unsigned char) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneBackFromCopyMove(dFile_select_c *this,uchar param_1,uchar param_2)

{
  dFile_select_c dVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = 1;
  iVar6 = 1;
  iVar5 = 1;
  iVar4 = 1;
  iVar7 = 1;
  iVar8 = 1;
  dVar1 = this[0x3924];
  if (dVar1 == (dFile_select_c)0x1) {
    iVar9 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                              d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                              d_file_select::_4050,DAT_803e4a53,2);
    iVar6 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                               d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                               d_file_select::_4050,DAT_803e4a53,2);
    iVar5 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - ((ushort)param_1 + (ushort)param_2),
                              DAT_803e4a74,d_file_select::_4050,d_file_select::_4196,
                              d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
    iVar4 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - ((ushort)param_1 + (ushort)param_2),
                               DAT_803e4a74,d_file_select::_4050,d_file_select::_4196,
                               d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
    sVar2 = (ushort)param_1 + (ushort)param_2 * 2;
    iVar7 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - sVar2,DAT_803e4a74,
                              d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                              d_file_select::_4050,DAT_803e4a53,2);
    iVar8 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - sVar2,DAT_803e4a74,
                               d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                               d_file_select::_4050,DAT_803e4a53,2);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      iVar9 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                                d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                d_file_select::_4050,DAT_803e4a53,2);
      iVar6 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                                 d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                 d_file_select::_4050,DAT_803e4a53,2);
      iVar5 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - ((ushort)param_1 + (ushort)param_2)
                                ,DAT_803e4a74,d_file_select::_4050,d_file_select::_4901,
                                d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
      iVar4 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) -
                                      ((ushort)param_1 + (ushort)param_2),DAT_803e4a74,
                                 d_file_select::_4050,d_file_select::_4901,d_file_select::_4050,
                                 d_file_select::_4050,DAT_803e4a53,2);
    }
    else {
      if ((byte)dVar1 < 3) {
        iVar9 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                  d_file_select::_4050,DAT_803e4a53,2);
        iVar6 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)param_1,DAT_803e4a74,
                                   d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                   d_file_select::_4050,DAT_803e4a53,2);
        iVar5 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) -
                                       ((ushort)param_1 + (ushort)param_2),DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                  d_file_select::_4050,DAT_803e4a53,2);
        iVar4 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) -
                                        ((ushort)param_1 + (ushort)param_2),DAT_803e4a74,
                                   d_file_select::_4050,d_file_select::_4902,d_file_select::_4050,
                                   d_file_select::_4050,DAT_803e4a53,2);
        sVar2 = (ushort)param_1 + (ushort)param_2 * 2;
        iVar7 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - sVar2,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4197,d_file_select::_4050,
                                  d_file_select::_4050,DAT_803e4a53,2);
        iVar8 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - sVar2,DAT_803e4a74,
                                   d_file_select::_4050,d_file_select::_4197,d_file_select::_4050,
                                   d_file_select::_4050,DAT_803e4a53,2);
      }
    }
  }
  if ((((iVar9 == 1) && (iVar6 == 1)) && (iVar5 == 1)) &&
     (((iVar4 == 1 && (iVar7 == 1)) && (iVar8 == 1)))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall dFile_select_c::YesNoSelect(void) */

void __thiscall dFile_select_c::YesNoSelect(dFile_select_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0x390c));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      this[0x3936] = (dFile_select_c)0x5;
      *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
      this[0x3928] = (dFile_select_c)0x1;
      this[0x392b] = (dFile_select_c)0xc;
      **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
    }
    else {
      cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0x390c));
      if (cVar1 == '\0') {
        cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0x390c));
        if ((cVar1 != '\0') && (this[0x3928] != (dFile_select_c)0x0)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          this[0x3928] = (dFile_select_c)0x0;
          *(undefined2 *)(this + 0x3930) = 0;
          yesNoCursorMove(this);
        }
      }
      else {
        if (this[0x3928] != (dFile_select_c)0x1) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          this[0x3928] = (dFile_select_c)0x1;
          *(undefined2 *)(this + 0x3930) = 0;
          yesNoCursorMove(this);
        }
      }
    }
  }
  else {
    if (this[0x3928] == (dFile_select_c)0x0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x89a,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      this[0x3941] = (dFile_select_c)0x1;
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      this[0x3936] = (dFile_select_c)0x5;
    }
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
    **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
    this[0x392b] = (dFile_select_c)0xc;
  }
  menuCursorAnime(this);
  return;
}


/* __thiscall dFile_select_c::yesNoCursorMove(void) */

void __thiscall dFile_select_c::yesNoCursorMove(dFile_select_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x30d8),
             (double)*(float *)(&d_file_select::posx_5833 + (uint)(byte)this[0x3928] * 4),
             (double)d_file_select::_4050);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_select_c::CmdExecPaneMove0(void) */

void __thiscall dFile_select_c::CmdExecPaneMove0(dFile_select_c *this)

{
  dFile_select_c *pdVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (this[0x392a] == (dFile_select_c)0x4) {
    pdVar1 = (dFile_select_c *)(uint)(byte)this[0x3922];
  }
  else {
    pdVar1 = this;
    if (this[0x392a] == (dFile_select_c)0x3) {
      pdVar1 = (dFile_select_c *)(uint)(byte)this[0x3926];
    }
  }
  if (this[((uint)pdVar1 & 0xff) + 0x3917] == (dFile_select_c)0x0) {
    iVar2 = recInfoPaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                            (ushort)DAT_803e4a7d,'\0',1);
  }
  else {
    iVar2 = MessagePaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                            (ushort)DAT_803e4a7d,'\0',1);
  }
  iVar3 = yesNoPaneMove(this,d_file_select::_4050,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                               d_file_select::_4148),(ushort)DAT_803e4a82,'\0',1);
  iVar4 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  if (this[0x392a] == (dFile_select_c)0x3) {
    DataSelectPaneCopyColorMove(this,*(short *)(this + 0x3930),DAT_803e4a56,0);
  }
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar2 == 1) && (iVar3 == 1)) && (iVar4 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    if (this[0x3928] == (dFile_select_c)0x0) {
      if (this[0x392a] == (dFile_select_c)0x4) {
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1d);
      }
      else {
        if (this[0x392a] == (dFile_select_c)0x3) {
          f_op_msg_mng::fopMsgM_messageGet
                    (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x21);
        }
      }
      f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),0x25);
      MessagePaneMoveSet(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                     d_file_select::_4148),*(float *)(this + 0x3944),
                         d_file_select::_4050,*(float *)(this + 0x3944),'\x01',0);
      this[0x392b] = (dFile_select_c)0xd;
    }
    else {
      this[0x3929] = (dFile_select_c)0xff;
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1b);
      this[0x392b] = (dFile_select_c)0x19;
    }
  }
  return;
}


/* __thiscall dFile_select_c::CmdExecPaneMove2(void) */

void __thiscall dFile_select_c::CmdExecPaneMove2(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                      d_file_select::_4148),*(float *)(this + 0x3944),
                          d_file_select::_4050,*(float *)(this + 0x3944),(ushort)DAT_803e4a7d,'\x01'
                          ,0);
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    this[0x392b] = (dFile_select_c)0xe;
  }
  else {
    *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  }
  return;
}


/* __thiscall dFile_select_c::CommandExec(void) */

void __thiscall dFile_select_c::CommandExec(dFile_select_c *this)

{
  byte *dst;
  
  if (this[0x392a] == (dFile_select_c)0x4) {
    dSv_info_c::initdata_to_card
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(char **)(this + 0x3938),
               (uint)(byte)this[0x3922]);
    m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(*(undefined4 *)(this + 0x3938),this[0x3922]);
    DAT_803b4ff4 = *(byte **)(this + 0x393c);
    DAT_file_slot = 0xff;
    mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,*(void **)(this + 0x3938),0x1650,0);
    this[0x392b] = (dFile_select_c)0xf;
  }
  else {
    if (this[0x392a] == (dFile_select_c)0x3) {
      copy_bytes((byte *)(*(int *)(this + 0x3938) + (uint)(byte)this[0x3926] * 0x770),
                 (byte *)(*(int *)(this + 0x3938) + (uint)(byte)this[0x3924] * 0x770),0x770);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData
                (*(undefined4 *)(this + 0x3938),this[0x3926]);
      dst = (byte *)(*(int *)(this + 0x393c) + (uint)(byte)this[0x3926] * 0x6000);
      copy_bytes(dst,(byte *)(*(int *)(this + 0x393c) + (uint)(byte)this[0x3924] * 0x6000),0x6000);
      DAT_file_slot = *(byte *)(this + 0x3926);
      DAT_803b4ff4 = dst;
      mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,*(void **)(this + 0x3938),0x1650,0);
      this[0x392b] = (dFile_select_c)0x10;
    }
  }
  return;
}


/* __thiscall dFile_select_c::DataEraseWait(void) */

void __thiscall dFile_select_c::DataEraseWait(dFile_select_c *this)

{
  int iVar1;
  
  iVar1 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  if (iVar1 != 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89b,(cXyz *)0x0,0,0,d_file_select::_4329,
               d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
    if (iVar1 == 2) {
      *(undefined2 *)(this + 0x3930) = 0;
      this[0x3929] = (dFile_select_c)0x1;
      *(float *)(this + 0x3944) = d_file_select::_4050;
      **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
      this[0x392b] = (dFile_select_c)0x15;
    }
    else {
      if (iVar1 == 1) {
        this[0x3941] = (dFile_select_c)0x0;
        *(undefined2 *)(this + 0x3930) = 0;
        this[0x3929] = (dFile_select_c)0x0;
        DAT_803b4ff4 = 0;
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1e);
        this[0x392b] = (dFile_select_c)0x13;
      }
    }
  }
  return;
}


/* __thiscall dFile_select_c::DataCopyWait(void) */

void __thiscall dFile_select_c::DataCopyWait(dFile_select_c *this)

{
  int iVar1;
  
  iVar1 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  if (iVar1 != 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x89b,(cXyz *)0x0,0,0,d_file_select::_4329,
               d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
    if (iVar1 == 2) {
      this[0x3929] = (dFile_select_c)0x1;
      *(undefined2 *)(this + 0x3930) = 0;
      *(float *)(this + 0x3944) = d_file_select::_4299;
      **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
      this[0x392b] = (dFile_select_c)0x15;
    }
    else {
      if (iVar1 == 1) {
        this[0x3941] = (dFile_select_c)0x0;
        this[0x3929] = (dFile_select_c)0x0;
        *(undefined2 *)(this + 0x3930) = 0;
        DAT_803b4ff4 = 0;
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x22);
        this[0x392b] = (dFile_select_c)0x11;
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80187e20) */
/* __thiscall dFile_select_c::ErasePaneMoveOk(void) */

void __thiscall dFile_select_c::ErasePaneMoveOk(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int unaff_r30;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                   DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                   d_file_select::_4050,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8a ^ 0x80000000) -
                                          d_file_select::_4148) - d_file_select::_4299,DAT_803e4a53,
                                   1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5d,d_file_select::_4050,d_file_select::_4050,
                                     d_file_select::_4050,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8a ^ 0x80000000) -
                                            d_file_select::_4148),DAT_803e4a53,1);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5f,d_file_select::_4050,d_file_select::_4197,
                                       d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8a ^ 0x80000000) -
                                              d_file_select::_4148) - d_file_select::_5953,
                                       DAT_803e4a53,1);
      }
    }
  }
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((unaff_r30 == 1) && (iVar2 == 1)) {
    setSaveData(this);
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x14;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80187ffc) */
/* __thiscall dFile_select_c::ErasePaneMoveOk2(void) */

void __thiscall dFile_select_c::ErasePaneMoveOk2(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int unaff_r30;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                   DAT_803e4a5e,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a88 ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,
                                   d_file_select::_4050,d_file_select::_4196,DAT_803e4a53,0);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                     DAT_803e4a5d,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a88 ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,
                                     d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,0);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                       DAT_803e4a5f,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a88 ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,
                                       d_file_select::_4050,d_file_select::_4197,DAT_803e4a53,0);
      }
    }
  }
  iVar2 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a87,
                          '\x01',1);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((unaff_r30 == 1) && (iVar2 == 1)) {
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x17;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::ErrorMsgPaneMove(void) */

void __thiscall dFile_select_c::ErrorMsgPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_r31;
  
  iVar1 = MessagePaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                 d_file_select::_4148),*(float *)(this + 0x3944),
                          (ushort)DAT_803e4a7d,'\0',1);
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    if (this[0x392a] == (dFile_select_c)0x4) {
      unaff_r31 = 0x26;
    }
    else {
      if (this[0x392a] == (dFile_select_c)0x3) {
        unaff_r31 = 0x27;
      }
    }
    f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),unaff_r31);
    MessagePaneMoveSet(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                       d_file_select::_4050,*(float *)(this + 0x3944),'\x01',0);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x16;
  }
  return;
}


/* __thiscall dFile_select_c::ErrorMsgPaneMove2(void) */

void __thiscall dFile_select_c::ErrorMsgPaneMove2(dFile_select_c *this)

{
  int iVar1;
  
  iVar1 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                      d_file_select::_4148),*(float *)(this + 0x3944),
                          d_file_select::_4050,*(float *)(this + 0x3944),(ushort)DAT_803e4a7d,'\x01'
                          ,0);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (iVar1 == 1) {
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x18;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_select_c::backDatSelPaneMove(void) */

void __thiscall dFile_select_c::backDatSelPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_r31;
  
  iVar3 = 1;
  iVar2 = 1;
  if (this[0x392a] == (dFile_select_c)0x4) {
    unaff_r31 = DataSelectPaneBackMove
                          (this,(ushort)DAT_803e4a75,(ushort)DAT_803e4a76,(ushort)DAT_803e4a75);
    if ((this[0x3929] != (dFile_select_c)0xff) && (this[0x3929] == (dFile_select_c)0x1)) {
      iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4050,
                              (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a7d
                              ,'\0',1);
    }
  }
  else {
    if (this[0x392a] == (dFile_select_c)0x3) {
      unaff_r31 = DataSelectPaneCopyBackMove(this,(ushort)DAT_803e4a75,(ushort)DAT_803e4a76);
      if (this[0x3929] != (dFile_select_c)0xff) {
        if (this[0x3929] == (dFile_select_c)0x0) {
          iVar2 = recInfoPaneMove(this,d_file_select::_4050,d_file_select::_4299,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4299,(ushort)DAT_803e4a7d,'\0',1);
        }
        else {
          iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4299,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4299,(ushort)DAT_803e4a7d,'\0',1);
        }
      }
    }
  }
  iVar1 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((unaff_r31 == 1) && (iVar3 == 1)) && (iVar2 == 1)) && (iVar1 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3932) = DAT_803e4a96;
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
    recCursorMove(this);
    this[0x392b] = (dFile_select_c)0x0;
    this[0x392a] = (dFile_select_c)0x0;
  }
  return;
}


/* __thiscall dFile_select_c::backDatSelWait(void) */

void __thiscall dFile_select_c::backDatSelWait(dFile_select_c *this)

{
  if (*(short *)(this + 0x3932) != 0) {
    *(short *)(this + 0x3932) = *(short *)(this + 0x3932) + -1;
  }
  if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
      (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) &&
     (*(short *)(this + 0x3932) != 0)) {
    return;
  }
  *(undefined2 *)(this + 0x3930) = 0;
  f_op_msg_mng::fopMsgM_messageGet
            (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x1b);
  this[0x3936] = (dFile_select_c)0x5;
  this[0x392b] = (dFile_select_c)0x19;
  return;
}


/* __thiscall dFile_select_c::backDatSelWait2(void) */

void __thiscall dFile_select_c::backDatSelWait2(dFile_select_c *this)

{
  if (*(short *)(this + 0x3932) != 0) {
    *(short *)(this + 0x3932) = *(short *)(this + 0x3932) + -1;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
          if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0) {
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0) {
              if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0) &&
                  ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)) &&
                 (*(short *)(this + 0x3932) != 0)) {
                return;
              }
            }
          }
        }
      }
    }
  }
  this[0x392e] = (dFile_select_c)0x1;
  *(undefined2 *)(this + 0x3930) = 0;
  this[0x392c] = (dFile_select_c)0x2;
  this[0x3936] = (dFile_select_c)0x3;
  this[0x392b] = (dFile_select_c)0x26;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8018873c) */
/* __thiscall dFile_select_c::DataSelectPaneBackMove(short,
                                                     short,
                                                     short) */

undefined4 __thiscall
dFile_select_c::DataSelectPaneBackMove
          (dFile_select_c *this,short param_1,short param_2,short param_3)

{
  dFile_select_c dVar1;
  undefined4 uVar2;
  int unaff_r23;
  int unaff_r27;
  int unaff_r28;
  int unaff_r29;
  int unaff_r30;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a74,
                                  d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                  d_file_select::_4050,DAT_803e4a53,2);
    unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a74,
                                   d_file_select::_4050,d_file_select::_4196,d_file_select::_4050,
                                   d_file_select::_4050,DAT_803e4a53,2);
    unaff_r28 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                  '\x01',0);
    unaff_r27 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8c ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4050,
                                   d_file_select::_4050,d_file_select::_4050,'\x01',0);
    unaff_r23 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                  '\x01',0);
    this = (dFile_select_c *)
           PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                              (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000) -
                                     d_file_select::_4148),d_file_select::_4050,d_file_select::_4050
                              ,d_file_select::_4050,'\x01',0);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = 1;
      unaff_r29 = 1;
      unaff_r28 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
      unaff_r27 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8c ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,
                                     d_file_select::_4050,d_file_select::_4050,'\x01',0);
      unaff_r23 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_803e4a8c ^ 0x80000000) -
                                           d_file_select::_4148),d_file_select::_4050,
                                    d_file_select::_4050,d_file_select::_4050,'\x01',0);
      this = (dFile_select_c *)
             PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000)
                                       - d_file_select::_4148),d_file_select::_4050,
                                d_file_select::_4050,d_file_select::_4050,'\x01',0);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecTlt3(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a74,
                                      d_file_select::_4050,d_file_select::_4197,d_file_select::_4050
                                      ,d_file_select::_4050,DAT_803e4a53,2);
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a74,
                                       d_file_select::_4050,d_file_select::_4197,
                                       d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,2);
        unaff_r28 = PaneTranceRecTlt1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,
                                      d_file_select::_4050,d_file_select::_4050,'\x01',0);
        unaff_r27 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - param_1,DAT_803e4a74,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8c ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4050,
                                       d_file_select::_4050,d_file_select::_4050,'\x01',0);
        unaff_r23 = PaneTranceRecTlt2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_803e4a8c ^ 0x80000000) -
                                             d_file_select::_4148),d_file_select::_4050,
                                      d_file_select::_4050,d_file_select::_4050,'\x01',0);
        this = (dFile_select_c *)
               PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - param_2,DAT_803e4a74,
                                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8c ^ 0x80000000
                                                          ) - d_file_select::_4148),
                                  d_file_select::_4050,d_file_select::_4050,d_file_select::_4050,
                                  '\x01',0);
      }
    }
  }
  if ((((unaff_r30 == 1) && (unaff_r29 == 1)) && (unaff_r28 == 1)) &&
     (((unaff_r27 == 1 && (unaff_r23 == 1)) && (this == (dFile_select_c *)&DAT_00000001)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall dFile_select_c::nextModeWait(void) */

void __thiscall dFile_select_c::nextModeWait(dFile_select_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dFile_select_c::screenSet(void) */

void __thiscall dFile_select_c::screenSet(dFile_select_c *this)

{
  undefined4 *puVar1;
  J2DScreen *pJVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  ___ in_r5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  dFile_select_c local_118;
  dFile_select_c dStack279;
  dFile_select_c dStack278;
  dFile_select_c dStack277;
  dFile_select_c local_114;
  dFile_select_c dStack275;
  dFile_select_c dStack274;
  dFile_select_c dStack273;
  dFile_select_c local_110;
  dFile_select_c dStack271;
  dFile_select_c dStack270;
  dFile_select_c dStack269;
  dFile_select_c local_10c;
  dFile_select_c dStack267;
  dFile_select_c dStack266;
  dFile_select_c dStack265;
  dFile_select_c local_108;
  dFile_select_c dStack263;
  dFile_select_c dStack262;
  dFile_select_c dStack261;
  dFile_select_c local_104;
  dFile_select_c dStack259;
  dFile_select_c dStack258;
  dFile_select_c dStack257;
  dFile_select_c local_100;
  dFile_select_c dStack255;
  dFile_select_c dStack254;
  dFile_select_c dStack253;
  dFile_select_c local_fc;
  dFile_select_c dStack251;
  dFile_select_c dStack250;
  dFile_select_c dStack249;
  undefined4 local_f8 [9];
  char local_d4 [47];
  undefined local_a5;
  char local_a4 [127];
  undefined local_25;
  
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x65786b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x10),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x65783030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x48),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6578706c);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x80),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x65787032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xb8),pJVar2);
  pcVar3 = local_d4;
  iVar10 = 0x30;
  do {
    *pcVar3 = 'A';
    pcVar3 = pcVar3 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  local_a5 = 0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x80),local_d4,in_r5);
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x80));
  *(undefined4 *)(this + 0x38e8) = uVar4;
  **(undefined **)(this + 0x38e8) = 0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0xb8),local_d4,in_r5);
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0xb8));
  *(undefined4 *)(this + 0x38ec) = uVar4;
  **(undefined **)(this + 0x38ec) = 0;
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e746b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x128),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6d657331);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x160),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x160),*(JUTFont **)(this + 0xc));
  pcVar3 = local_a4;
  iVar10 = 0x80;
  do {
    *pcVar3 = 'A';
    pcVar3 = pcVar3 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  local_25 = 0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x160),local_a4,in_r5);
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x160));
  *(undefined4 *)(this + 0x38f0) = uVar4;
  **(undefined **)(this + 0x38f0) = 0;
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72633030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x198),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72636b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d0),pJVar2);
  iVar10 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),*(undefined4 *)(d_file_select::l_Collec_6111 + iVar9));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0x208),pJVar2);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 0xc);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69743033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4a8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69743031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4e0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x69743032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x518),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x696b3033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x550),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x696b3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x588),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x696b3032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x5c0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x74726962);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x5f8),pJVar2);
  iVar10 = 4;
  puVar1 = (undefined4 *)0x8035ed9c;
  puVar7 = (undefined4 *)&local_fc;
  do {
    puVar6 = puVar7;
    puVar5 = puVar1;
    uVar4 = puVar5[2];
    puVar6[1] = puVar5[1];
    puVar7 = puVar6 + 2;
    *puVar7 = uVar4;
    iVar10 = iVar10 + -1;
    puVar1 = puVar5 + 2;
  } while (iVar10 != 0);
  puVar6[3] = puVar5[3];
  iVar10 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),*(undefined4 *)((int)local_f8 + iVar9));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0x630),pJVar2);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 9);
  iVar10 = 0;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),
                        *(undefined4 *)(d_file_select::l_Collec_6111 + iVar9 + 0x30));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0x828),pJVar2);
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),
                        *(undefined4 *)(d_file_select::l_Collec_6111 + iVar9 + 0x80));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0xc88),pJVar2);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 0x14);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6531);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x10e8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x656b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1120),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6532);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1158),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x656b32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1190),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6533);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x11c8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x656b33);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1200),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x616b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1238),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x31646174);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1270),pJVar2);
  iVar10 = 0x61303030;
  iVar8 = 2;
  iVar9 = 0x70;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x1238),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0xc);
  iVar10 = 0x616b3031;
  iVar8 = 0xc;
  iVar9 = 0x2a0;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x1238),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x10);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x626b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15b8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x32646174);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15f0),pJVar2);
  iVar10 = 0x62303030;
  iVar8 = 2;
  iVar9 = 0x70;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x15b8),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0xc);
  iVar10 = 0x626b3031;
  iVar8 = 0xc;
  iVar9 = 0x2a0;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x15b8),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x10);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x636b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1938),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x33646174);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1970),pJVar2);
  iVar10 = 0x63303030;
  iVar8 = 2;
  iVar9 = 0x70;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x1938),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0xc);
  iVar10 = 0x636b3031;
  iVar8 = 0xc;
  iVar9 = 0x2a0;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x1938),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x10);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x316b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cb8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e616d31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1cf0),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1cf0),*(JUTFont **)(this + 0xc));
  *(undefined4 *)(this + 0x38e0) = *(undefined4 *)(*(int *)(this + 0x1cf0) + 0xe8);
  *(undefined4 *)(this + 0x38e4) = *(undefined4 *)(*(int *)(this + 0x1cf0) + 0xec);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x64617931);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d28),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x1d28),*(JUTFont **)(this + 0xc));
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x1cf0),local_d4,(___)puVar7);
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x1cf0));
  *(undefined4 *)(this + 0x38f4) = uVar4;
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x1d28));
  *(undefined4 *)(this + 0x3900) = uVar4;
  iVar10 = 3;
  iVar8 = 0xa8;
  iVar9 = 0xc;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),
                        *(undefined4 *)(d_file_select::l_Collec_6111 + iVar9 + 0xc4));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0x1cb8),pJVar2);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 0x15);
  iVar10 = 0x316b3031;
  iVar8 = 0x15;
  iVar9 = 0x498;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x1cb8),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x1d);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x326b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2310),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e616d32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2348),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x2348),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x64617932);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2380),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x2380),*(JUTFont **)(this + 0xc));
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x2348));
  *(undefined4 *)(this + 0x38f8) = uVar4;
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x2380));
  *(undefined4 *)(this + 0x3904) = uVar4;
  iVar10 = 3;
  iVar8 = 0xa8;
  iVar9 = 0xc;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),
                        *(undefined4 *)(d_file_select::l_Collec_6111 + iVar9 + 0x10c));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar8 + 0x2310),pJVar2);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 0x15);
  iVar10 = 0x326b3031;
  iVar8 = 0x15;
  iVar9 = 0x498;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x2310),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x1d);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x336b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2968),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e616d33);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x29a0),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x29a0),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x64617933);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x29d8),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x29d8),*(JUTFont **)(this + 0xc));
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x29a0));
  *(undefined4 *)(this + 0x38fc) = uVar4;
  uVar4 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x29d8));
  *(undefined4 *)(this + 0x3908) = uVar4;
  iVar10 = 3;
  iVar9 = 0xa8;
  iVar8 = 0xc;
  do {
    pJVar2 = (J2DScreen *)
             (**(code **)(**(int **)(this + 8) + 0x30))
                       (*(int **)(this + 8),
                        *(undefined4 *)(d_file_select::l_Collec_6111 + iVar8 + 0x154));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x2968),pJVar2);
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
    iVar8 = iVar8 + 4;
  } while (iVar10 < 0x15);
  iVar10 = 0x336b3031;
  iVar8 = 0x15;
  iVar9 = 0x498;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x2968),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 0x1d);
  iVar10 = 0x32637531;
  iVar8 = 0;
  iVar9 = 0;
  do {
    pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),iVar10);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar9 + 0x2fc0),pJVar2);
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar8 < 5);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x31637531);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x30d8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x31637532);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3110),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x79736b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3148),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x79736b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3180),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x79733030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x31b8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x79733031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x31f0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x796573);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3228),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x3228),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e6f6b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3260),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e6f6b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3298),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e6f3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x32d0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e6f3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3308),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x6e6f);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3340),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x3340),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x736b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3378),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x736b3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x33b0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x73303030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x33e8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x73303031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3420),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x73746174);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3458),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x3458),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x63706b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x35a8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x63706b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x35e0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x63703030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3618),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x63703031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3650),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x636f7079);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3688),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x3688),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x646c6b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x36c0),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x646c6b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x36f8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x646c3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3730),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x646c3031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3768),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x646c6c65);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x37a0),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x37a0),*(JUTFont **)(this + 0xc));
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72656b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3490),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72656b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x34c8),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72653030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3500),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72653031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3538),pJVar2);
  pJVar2 = (J2DScreen *)(**(code **)(**(int **)(this + 8) + 0x30))(*(int **)(this + 8),0x72657475);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3570),pJVar2);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x3570),*(JUTFont **)(this + 0xc));
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3618) + 0x108);
  local_fc = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38c0] = local_fc;
  dStack251 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38c1] = dStack251;
  dStack250 = SUB41((uint)uVar4 >> 8,0);
  this[0x38c2] = dStack250;
  dStack249 = SUB41(uVar4,0);
  this[0x38c3] = dStack249;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3618) + 0x104);
  local_100 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38c8] = local_100;
  dStack255 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38c9] = dStack255;
  dStack254 = SUB41((uint)uVar4 >> 8,0);
  this[0x38ca] = dStack254;
  dStack253 = SUB41(uVar4,0);
  this[0x38cb] = dStack253;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3650) + 0x108);
  local_104 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38c4] = local_104;
  dStack259 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38c5] = dStack259;
  dStack258 = SUB41((uint)uVar4 >> 8,0);
  this[0x38c6] = dStack258;
  dStack257 = SUB41(uVar4,0);
  this[0x38c7] = dStack257;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3650) + 0x104);
  local_108 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38cc] = local_108;
  dStack263 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38cd] = dStack263;
  dStack262 = SUB41((uint)uVar4 >> 8,0);
  this[0x38ce] = dStack262;
  dStack261 = SUB41(uVar4,0);
  this[0x38cf] = dStack261;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3730) + 0x108);
  local_10c = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38d0] = local_10c;
  dStack267 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38d1] = dStack267;
  dStack266 = SUB41((uint)uVar4 >> 8,0);
  this[0x38d2] = dStack266;
  dStack265 = SUB41(uVar4,0);
  this[0x38d3] = dStack265;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3730) + 0x104);
  local_110 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38d8] = local_110;
  dStack271 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38d9] = dStack271;
  dStack270 = SUB41((uint)uVar4 >> 8,0);
  this[0x38da] = dStack270;
  dStack269 = SUB41(uVar4,0);
  this[0x38db] = dStack269;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3768) + 0x108);
  local_114 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38d4] = local_114;
  dStack275 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38d5] = dStack275;
  dStack274 = SUB41((uint)uVar4 >> 8,0);
  this[0x38d6] = dStack274;
  dStack273 = SUB41(uVar4,0);
  this[0x38d7] = dStack273;
  uVar4 = *(undefined4 *)(*(int *)(this + 0x3768) + 0x104);
  local_118 = SUB41((uint)uVar4 >> 0x18,0);
  this[0x38dc] = local_118;
  dStack279 = SUB41((uint)uVar4 >> 0x10,0);
  this[0x38dd] = dStack279;
  dStack278 = SUB41((uint)uVar4 >> 8,0);
  this[0x38de] = dStack278;
  dStack277 = SUB41(uVar4,0);
  this[0x38df] = dStack277;
  return;
}


/* __thiscall dFile_select_c::paneTransInit(void) */

void __thiscall dFile_select_c::paneTransInit(dFile_select_c *this)

{
  *(undefined2 *)(this + 0x3930) = 0;
  PaneTranceTitle(this,*(short *)(this + 0x3930),DAT_803e4a54,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a94 ^ 0x80000000) -
                         d_file_select::_4148),d_file_select::_4050,DAT_803e4a53,0);
  PaneTranceRecTlt1(this,*(short *)(this + 0x3930),DAT_803e4a58,
                    (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                           d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                    d_file_select::_4050,'\x01',0);
  PaneTranceRecTlt2(this,*(short *)(this + 0x3930),DAT_803e4a59,
                    (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                           d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                    d_file_select::_4050,'\x01',0);
  PaneTranceRecTlt3(this,*(short *)(this + 0x3930),DAT_803e4a5a,
                    (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a64 ^ 0x80000000) -
                           d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                    d_file_select::_4050,'\x01',0);
  PaneTranceRecInfo1(this,*(short *)(this + 0x3930),DAT_803e4a5d,d_file_select::_4050,
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a66 ^ 0x80000000) -
                            d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,'\x01',0
                    );
  PaneTranceRecInfo2(this,*(short *)(this + 0x3930),DAT_803e4a5e,d_file_select::_4050,
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a68 ^ 0x80000000) -
                            d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,'\x01',0
                    );
  PaneTranceRecInfo3(this,*(short *)(this + 0x3930),DAT_803e4a5f,d_file_select::_4050,
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a68 ^ 0x80000000) -
                            d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,'\x01',0
                    );
  PaneTranceMessageBase
            (this,*(short *)(this + 0x3930),DAT_803e4a7e,
             (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                    d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
             d_file_select::_4050,'\x01',0);
  PaneTranceRecBase(this,*(short *)(this + 0x3930),DAT_803e4a7b,
                    (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                           d_file_select::_4148),d_file_select::_4050,d_file_select::_4050,
                    d_file_select::_4050,'\x01',0);
  menuPaneMoveSet(this);
  yesNoPaneMoveSet(this);
  return;
}


/* __thiscall dFile_select_c::menuPaneMoveSet(void) */

void __thiscall dFile_select_c::menuPaneMoveSet(dFile_select_c *this)

{
  PaneTranceStart(this,*(short *)(this + 0x3930),DAT_803e4a80,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                         d_file_select::_4148),d_file_select::_4050,'\x01',0);
  PaneTranceCopy(this,*(short *)(this + 0x3930),DAT_803e4a80,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                        d_file_select::_4148),d_file_select::_4050,'\x01',0);
  PaneTranceErase(this,*(short *)(this + 0x3930),DAT_803e4a80,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                         d_file_select::_4148),d_file_select::_4050,'\x01',0);
  PaneTranceBack(this,*(short *)(this + 0x3930),DAT_803e4a80,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                        d_file_select::_4148),d_file_select::_4050,'\x01',0);
  return;
}


/* __thiscall dFile_select_c::yesNoPaneMoveSet(void) */

void __thiscall dFile_select_c::yesNoPaneMoveSet(dFile_select_c *this)

{
  PaneTranceYes(this,*(short *)(this + 0x3930),DAT_803e4a80,
                (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                       d_file_select::_4148),d_file_select::_4050,'\x01',0);
  PaneTranceNo(this,*(short *)(this + 0x3930),DAT_803e4a80,
               (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                      d_file_select::_4148),d_file_select::_4050,'\x01',0);
  return;
}


/* __thiscall dFile_select_c::MessagePaneMove(float,
                                              float,
                                              float,
                                              float,
                                              short,
                                              unsigned char,
                                              int) */

void __thiscall
dFile_select_c::MessagePaneMove
          (dFile_select_c *this,float param_1,float param_2,float param_3,float param_4,
          short param_5,uchar param_6,int param_7)

{
  PaneTranceMessageBase
            (this,*(short *)(this + 0x3930) - param_5,DAT_803e4a7e,param_1,param_2,param_3,param_4,
             param_6,param_7);
  return;
}


/* __thiscall dFile_select_c::recInfoPaneMove(float,
                                              float,
                                              float,
                                              float,
                                              short,
                                              unsigned char,
                                              int) */

void __thiscall
dFile_select_c::recInfoPaneMove
          (dFile_select_c *this,float param_1,float param_2,float param_3,float param_4,
          short param_5,uchar param_6,int param_7)

{
  PaneTranceRecBase(this,*(short *)(this + 0x3930) - param_5,DAT_803e4a7b,param_1,param_2,param_3,
                    param_4,param_6,param_7);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dFile_select_c::menuPaneMove(float,
                                           float,
                                           short,
                                           unsigned char,
                                           int) */

undefined4 __thiscall
dFile_select_c::menuPaneMove
          (dFile_select_c *this,float param_1,float param_2,short param_3,uchar param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  
  dVar7 = (double)param_2;
  dVar6 = (double)param_1;
  iVar1 = PaneTranceStart(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a80,param_1,param_2,
                          param_4,param_5);
  iVar2 = PaneTranceCopy(this,*(short *)(this + 0x3930) - (param_3 + (ushort)DAT_803e4a83),
                         DAT_803e4a80,(float)dVar6,(float)dVar7,param_4,param_5);
  iVar3 = PaneTranceErase(this,*(short *)(this + 0x3930) - (param_3 + (ushort)DAT_803e4a83 * 2),
                          DAT_803e4a80,(float)dVar6,(float)dVar7,param_4,param_5);
  iVar4 = PaneTranceBack(this,*(short *)(this + 0x3930) - (param_3 + (ushort)DAT_803e4a83 * 3),
                         DAT_803e4a80,(float)dVar6,(float)dVar7,param_4,param_5);
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (iVar4 == 1)) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dFile_select_c::yesNoPaneMove(float,
                                            float,
                                            short,
                                            unsigned char,
                                            int) */

undefined4 __thiscall
dFile_select_c::yesNoPaneMove
          (dFile_select_c *this,float param_1,float param_2,short param_3,uchar param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  
  dVar5 = (double)param_2;
  dVar4 = (double)param_1;
  iVar1 = PaneTranceYes(this,*(short *)(this + 0x3930) - param_3,DAT_803e4a80,param_1,param_2,
                        param_4,param_5);
  iVar2 = PaneTranceNo(this,*(short *)(this + 0x3930) - (param_3 + (ushort)DAT_803e4a83),
                       DAT_803e4a80,(float)dVar4,(float)dVar5,param_4,param_5);
  if ((iVar1 == 1) && (iVar2 == 1)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Removing unreachable block (ram,0x8018a814) */
/* WARNING: Removing unreachable block (ram,0x8018a80c) */
/* WARNING: Removing unreachable block (ram,0x8018a81c) */
/* __thiscall dFile_select_c::PaneTranceTitle(short,
                                              unsigned char,
                                              float,
                                              float,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dFile_select_c::PaneTranceTitle
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x10),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x10),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x48),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x392d] * 0x38 + 0x80),
                   (float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x10));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x48));
        f_op_msg_mng::fopMsgM_setAlpha
                  ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x392d] * 0x38 + 0x80));
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


/* WARNING: Removing unreachable block (ram,0x8018a8d8) */
/* __thiscall dFile_select_c::PaneAlphaTitleTxt(short,
                                                unsigned char) */

undefined4 __thiscall
dFile_select_c::PaneAlphaTitleTxt(dFile_select_c *this,short param_1,uchar param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease((uint)param_2,(int)param_1,0);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x392d] * 0x38 + 0x80),
                 (float)((double)d_file_select::_4329 - dVar3));
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + ((byte)this[0x392d] ^ 1) * 0x38 + 0x80),(float)dVar3)
      ;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x80));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb8));
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018aa60) */
/* WARNING: Removing unreachable block (ram,0x8018aa50) */
/* WARNING: Removing unreachable block (ram,0x8018aa48) */
/* WARNING: Removing unreachable block (ram,0x8018aa58) */
/* WARNING: Removing unreachable block (ram,0x8018aa68) */
/* __thiscall dFile_select_c::PaneTranceRecTlt1(short,
                                                unsigned char,
                                                float,
                                                float,
                                                float,
                                                float,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecTlt1
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_5;
  dVar7 = (double)param_6;
  dVar9 = (double)param_4;
  dVar8 = (double)param_3;
  uVar4 = 0;
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
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      dVar8 = (double)(float)(dVar8 + (double)(float)(dVar5 * (double)(float)(dVar6 - dVar8)));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar5 * (double)(float)(dVar7 - dVar9)));
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1238),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x10e8),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1120),dVar8,dVar9);
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar5 = (double)(float)((double)d_file_select::_4329 - dVar5);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x10e8),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x10e8));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 2);
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1238),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1238));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 3);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018abf4) */
/* WARNING: Removing unreachable block (ram,0x8018abe4) */
/* WARNING: Removing unreachable block (ram,0x8018abdc) */
/* WARNING: Removing unreachable block (ram,0x8018abec) */
/* WARNING: Removing unreachable block (ram,0x8018abfc) */
/* __thiscall dFile_select_c::PaneTranceRecTlt2(short,
                                                unsigned char,
                                                float,
                                                float,
                                                float,
                                                float,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecTlt2
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_5;
  dVar7 = (double)param_6;
  dVar9 = (double)param_4;
  dVar8 = (double)param_3;
  uVar4 = 0;
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
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      dVar8 = (double)(float)(dVar8 + (double)(float)(dVar5 * (double)(float)(dVar6 - dVar8)));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar5 * (double)(float)(dVar7 - dVar9)));
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x15b8),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1158),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1190),dVar8,dVar9);
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar5 = (double)(float)((double)d_file_select::_4329 - dVar5);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1158),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1158));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 2);
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x15b8),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x15b8));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 3);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018ad88) */
/* WARNING: Removing unreachable block (ram,0x8018ad78) */
/* WARNING: Removing unreachable block (ram,0x8018ad70) */
/* WARNING: Removing unreachable block (ram,0x8018ad80) */
/* WARNING: Removing unreachable block (ram,0x8018ad90) */
/* __thiscall dFile_select_c::PaneTranceRecTlt3(short,
                                                unsigned char,
                                                float,
                                                float,
                                                float,
                                                float,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecTlt3
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_5;
  dVar7 = (double)param_6;
  dVar9 = (double)param_4;
  dVar8 = (double)param_3;
  uVar4 = 0;
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
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      dVar8 = (double)(float)(dVar8 + (double)(float)(dVar5 * (double)(float)(dVar6 - dVar8)));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar5 * (double)(float)(dVar7 - dVar9)));
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1938),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x11c8),dVar8,dVar9);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1200),dVar8,dVar9);
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar5 = (double)(float)((double)d_file_select::_4329 - dVar5);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x11c8),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x11c8));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 2);
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1938),(float)dVar5);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1938));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 3);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018aec0) */
/* WARNING: Removing unreachable block (ram,0x8018aeb0) */
/* WARNING: Removing unreachable block (ram,0x8018aea8) */
/* WARNING: Removing unreachable block (ram,0x8018aeb8) */
/* WARNING: Removing unreachable block (ram,0x8018aec8) */
/* __thiscall dFile_select_c::PaneTranceRecInfo1(short,
                                                 unsigned char,
                                                 float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecInfo1
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  dVar9 = (double)param_6;
  dVar7 = (double)param_4;
  dVar5 = (double)param_3;
  uVar4 = 0;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1cb8),
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar5))),
                 (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar9 - dVar7))));
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar6 = (double)(float)((double)d_file_select::_4329 - dVar6);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x1cb8),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x1cb8));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 4);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018aff8) */
/* WARNING: Removing unreachable block (ram,0x8018afe8) */
/* WARNING: Removing unreachable block (ram,0x8018afe0) */
/* WARNING: Removing unreachable block (ram,0x8018aff0) */
/* WARNING: Removing unreachable block (ram,0x8018b000) */
/* __thiscall dFile_select_c::PaneTranceRecInfo2(short,
                                                 unsigned char,
                                                 float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecInfo2
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  dVar9 = (double)param_6;
  dVar7 = (double)param_4;
  dVar5 = (double)param_3;
  uVar4 = 0;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2310),
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar5))),
                 (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar9 - dVar7))));
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar6 = (double)(float)((double)d_file_select::_4329 - dVar6);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x2310),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x2310));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 4);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018b130) */
/* WARNING: Removing unreachable block (ram,0x8018b120) */
/* WARNING: Removing unreachable block (ram,0x8018b118) */
/* WARNING: Removing unreachable block (ram,0x8018b128) */
/* WARNING: Removing unreachable block (ram,0x8018b138) */
/* __thiscall dFile_select_c::PaneTranceRecInfo3(short,
                                                 unsigned char,
                                                 float,
                                                 float,
                                                 float,
                                                 float,
                                                 unsigned char,
                                                 int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecInfo3
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  dVar9 = (double)param_6;
  dVar7 = (double)param_4;
  dVar5 = (double)param_3;
  uVar4 = 0;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x2968),
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar5))),
                 (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar9 - dVar7))));
      if (param_8 != 2) {
        if (param_8 == 1) {
          dVar6 = (double)(float)((double)d_file_select::_4329 - dVar6);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x2968),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x2968));
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0x38;
        } while (iVar2 < 4);
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
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8018b46c) */
/* WARNING: Removing unreachable block (ram,0x8018b45c) */
/* WARNING: Removing unreachable block (ram,0x8018b454) */
/* WARNING: Removing unreachable block (ram,0x8018b464) */
/* WARNING: Removing unreachable block (ram,0x8018b474) */
/* __thiscall dFile_select_c::PaneTranceRecBase(short,
                                                unsigned char,
                                                float,
                                                float,
                                                float,
                                                float,
                                                unsigned char,
                                                int) */

undefined4 __thiscall
dFile_select_c::PaneTranceRecBase
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  dFile_select_c *pdVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_5;
  dVar8 = (double)param_6;
  dVar10 = (double)param_4;
  dVar9 = (double)param_3;
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
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      dVar9 = (double)(float)(dVar9 + (double)(float)(dVar6 * (double)(float)(dVar7 - dVar9)));
      dVar10 = (double)(float)(dVar10 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar10)));
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x198),dVar9,dVar10);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x1d0),dVar9,dVar10);
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x208),dVar9,dVar10);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 0xc);
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x4a8),dVar9,dVar10);
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x550),dVar9,dVar10);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 3);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0x5f8),dVar9,dVar10);
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x630),dVar9,dVar10);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 9);
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0x828),dVar9,dVar10);
        f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + iVar4 + 0xc88),dVar9,dVar10);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 0x14);
      if (param_8 == 1) {
        dVar6 = (double)(float)((double)d_file_select::_4329 - dVar6);
      }
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x198),(float)dVar6)
        ;
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x198));
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 2);
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x208),(float)dVar6)
        ;
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x208));
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 0xc);
      iVar2 = 0;
      iVar4 = 0;
      do {
        pdVar3 = this + iVar4;
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar3 + 0x4a8),(float)dVar6);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar3 + 0x550),(float)dVar6);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar3 + 0x4a8));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar3 + 0x550));
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 3);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x5f8),(float)dVar6);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x5f8));
      iVar2 = 0;
      iVar4 = 0;
      do {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x630),(float)dVar6)
        ;
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x630));
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 9);
      iVar2 = 0;
      iVar4 = 0;
      do {
        pdVar3 = this + iVar4;
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar3 + 0x828),(float)dVar6);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar3 + 0xc88),(float)dVar6);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar3 + 0x828));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar3 + 0xc88));
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar2 < 0x14);
      uVar1 = 0;
    }
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
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018b5b0) */
/* WARNING: Removing unreachable block (ram,0x8018b5a0) */
/* WARNING: Removing unreachable block (ram,0x8018b598) */
/* WARNING: Removing unreachable block (ram,0x8018b5a8) */
/* WARNING: Removing unreachable block (ram,0x8018b5b8) */
/* __thiscall dFile_select_c::PaneTranceMessageBase(short,
                                                    unsigned char,
                                                    float,
                                                    float,
                                                    float,
                                                    float,
                                                    unsigned char,
                                                    int) */

undefined4 __thiscall
dFile_select_c::PaneTranceMessageBase
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          float param_5,float param_6,uchar param_7,int param_8)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  dVar9 = (double)param_6;
  dVar7 = (double)param_4;
  dVar5 = (double)param_3;
  uVar4 = 0;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_7));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xf0),
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar8 - dVar5))),
                 (double)(float)(dVar7 + (double)(float)(dVar6 * (double)(float)(dVar9 - dVar7))));
      if (param_8 == 1) {
        dVar6 = (double)(float)((double)d_file_select::_4329 - dVar6);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x160),(float)dVar6);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x160));
      iVar2 = 0;
      iVar3 = 0;
      do {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xf0),(float)dVar6);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0xf0));
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x38;
      } while (iVar2 < 2);
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x8018b6b8) */
/* WARNING: Removing unreachable block (ram,0x8018b6b0) */
/* WARNING: Removing unreachable block (ram,0x8018b6c0) */
/* __thiscall dFile_select_c::PaneTranceYes(short,
                                            unsigned char,
                                            float,
                                            float,
                                            unsigned char,
                                            int) */

undefined4 __thiscall
dFile_select_c::PaneTranceYes
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x3148),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3148),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x31b8),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3228),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3148));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x31b8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3228));
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


/* WARNING: Removing unreachable block (ram,0x8018b7c0) */
/* WARNING: Removing unreachable block (ram,0x8018b7b8) */
/* WARNING: Removing unreachable block (ram,0x8018b7c8) */
/* __thiscall dFile_select_c::PaneTranceNo(short,
                                           unsigned char,
                                           float,
                                           float,
                                           unsigned char,
                                           int) */

undefined4 __thiscall
dFile_select_c::PaneTranceNo
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x3260),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3260),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x32d0),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3340),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3260));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x32d0));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3340));
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


/* WARNING: Removing unreachable block (ram,0x8018b8c8) */
/* WARNING: Removing unreachable block (ram,0x8018b8c0) */
/* WARNING: Removing unreachable block (ram,0x8018b8d0) */
/* __thiscall dFile_select_c::PaneTranceStart(short,
                                              unsigned char,
                                              float,
                                              float,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dFile_select_c::PaneTranceStart
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x3378),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3378),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x33e8),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3458),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3378));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x33e8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3458));
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


/* WARNING: Removing unreachable block (ram,0x8018b9d0) */
/* WARNING: Removing unreachable block (ram,0x8018b9c8) */
/* WARNING: Removing unreachable block (ram,0x8018b9d8) */
/* __thiscall dFile_select_c::PaneTranceCopy(short,
                                             unsigned char,
                                             float,
                                             float,
                                             unsigned char,
                                             int) */

undefined4 __thiscall
dFile_select_c::PaneTranceCopy
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x35a8),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x35a8),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3618),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3688),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x35a8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3618));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3688));
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


/* WARNING: Removing unreachable block (ram,0x8018bad8) */
/* WARNING: Removing unreachable block (ram,0x8018bad0) */
/* WARNING: Removing unreachable block (ram,0x8018bae0) */
/* __thiscall dFile_select_c::PaneTranceErase(short,
                                              unsigned char,
                                              float,
                                              float,
                                              unsigned char,
                                              int) */

undefined4 __thiscall
dFile_select_c::PaneTranceErase
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x36c0),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x36c0),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3730),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x37a0),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x36c0));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3730));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x37a0));
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


/* WARNING: Removing unreachable block (ram,0x8018bbe0) */
/* WARNING: Removing unreachable block (ram,0x8018bbd8) */
/* WARNING: Removing unreachable block (ram,0x8018bbe8) */
/* __thiscall dFile_select_c::PaneTranceBack(short,
                                             unsigned char,
                                             float,
                                             float,
                                             unsigned char,
                                             int) */

undefined4 __thiscall
dFile_select_c::PaneTranceBack
          (dFile_select_c *this,short param_1,uchar param_2,float param_3,float param_4,
          uchar param_5,int param_6)

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
                ((fopMsgM_pane_class *)(this + 0x3490),(double)d_file_select::_4050,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 == 1) {
        dVar4 = (double)(float)((double)d_file_select::_4329 - dVar4);
      }
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3490),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3500),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x3570),(float)dVar4);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3490));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3500));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x3570));
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


/* __thiscall dFile_select_c::displayInit(void) */

void __thiscall dFile_select_c::displayInit(dFile_select_c *this)

{
  this[0x3941] = (dFile_select_c)0x0;
  this[0x3936] = (dFile_select_c)0x6;
  this[0x392d] = (dFile_select_c)0x0;
  this[0x392c] = (dFile_select_c)0x0;
  this[0x392e] = (dFile_select_c)0x0;
  **(undefined **)(this + 0x38f0) = 0;
  *(undefined2 *)(this + 0x3932) = DAT_803e4a96;
  *(float *)(this + 0x3948) = d_file_select::_4050;
  recCursorAlphaInit(this);
  recCursorMove(this);
  *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
  this[0x3928] = (dFile_select_c)0x0;
  menuCursorAlphaInit(this);
  if (*(int *)(this + 0x3938) != 0) {
    setSaveData(this);
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb8),d_file_select::_4050);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb8));
  if (this[0x3940] == (dFile_select_c)0x0) {
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + (uint)(byte)this[0x392d] * 4 + 0x38e8),0x1b);
    this[0x392a] = (dFile_select_c)0x0;
    this[0x392b] = (dFile_select_c)0x0;
  }
  else {
    if (this[0x3940] == (dFile_select_c)0x1) {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + (uint)(byte)this[0x392d] * 4 + 0x38e8),0x4e);
      this[0x392b] = (dFile_select_c)0x1a;
    }
  }
  *(undefined *)(*(int *)(this + 0x7f0) + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8018c0a0) */
/* __thiscall dFile_select_c::setSaveData(void) */

void __thiscall dFile_select_c::setSaveData(dFile_select_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  J2DScreen *pJVar4;
  int iVar5;
  int iVar6;
  fopMsgM_pane_class *unaff_r28;
  card_savedata *pData;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  OSCalendarTime local_58;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pData = *(card_savedata **)(this + 0x3938);
  iVar7 = 0;
  iVar6 = 0;
  dVar10 = (double)d_file_select::_4050;
  do {
    if (iVar7 == 1) {
      unaff_r28 = (fopMsgM_pane_class *)(this + 0x2348);
    }
    else {
      if (iVar7 < 1) {
        if (-1 < iVar7) {
          unaff_r28 = (fopMsgM_pane_class *)(this + 0x1cf0);
        }
      }
      else {
        if (iVar7 < 3) {
          unaff_r28 = (fopMsgM_pane_class *)(this + 0x29a0);
        }
      }
    }
    f_op_msg_mng::fopMsgM_paneScaleXY(unaff_r28,d_file_select::_4329);
    fVar3 = *(float *)(this + 0x38e4);
    pJVar4 = unaff_r28->mpPane;
    dVar9 = dVar10;
    if (dVar10 < (double)*(float *)(this + 0x38e0)) {
      dVar9 = (double)*(float *)(this + 0x38e0);
    }
    pJVar4[1].parent.mPosBR.x = (float)dVar9;
    dVar9 = dVar10;
    if (dVar10 < (double)fVar3) {
      dVar9 = (double)fVar3;
    }
    pJVar4[1].parent.mPosBR.y = (float)dVar9;
    f_op_msg_mng::fopMsgM_paneTrans
              (unaff_r28,(double)d_file_select::_4050,(double)d_file_select::_4050);
    iVar5 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(pData);
    if (iVar5 == 0) {
      changeBrokenColor(this,iVar7);
      f_op_msg_mng::fopMsgM_paneScaleXY(unaff_r28,DAT_803e4aa0);
      fVar3 = *(float *)(this + 0x38e4) * DAT_803e4aa0;
      fVar1 = d_file_select::_4053 * *(float *)(this + 0x38e0);
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + iVar6 + 0x38f4),"This data is corrupted.");
      pJVar4 = unaff_r28->mpPane;
      fVar2 = d_file_select::_4050;
      if (d_file_select::_4050 < fVar1) {
        fVar2 = fVar1;
      }
      pJVar4[1].parent.mPosBR.x = fVar2;
      fVar1 = d_file_select::_4050;
      if (d_file_select::_4050 < fVar3) {
        fVar1 = fVar3;
      }
      pJVar4[1].parent.mPosBR.y = fVar1;
      f_op_msg_mng::fopMsgM_paneTrans
                (unaff_r28,(double)((unaff_r28->mPosTopLeftOrig).x - (unaff_r28->mPosTopLeft).x),
                 (double)(DAT_803e4aa4 +
                         ((unaff_r28->mPosTopLeftOrig).y - (unaff_r28->mPosTopLeft).y)));
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + iVar6 + 0x3900),"");
      (this + iVar7)[0x3917] = (dFile_select_c)0x1;
      (this + iVar7)[0x3914] = (dFile_select_c)0x0;
    }
    else {
      if (pData->mData[0x19b] == 0) {
        (this + iVar7)[0x391a] = (dFile_select_c)0x0;
        (this + iVar7)[0x391d] = (dFile_select_c)0x0;
      }
      else {
        (this + iVar7)[0x391a] = (dFile_select_c)0x1;
        (this + iVar7)[0x391d] = (dFile_select_c)(pData->mData[0x64d] >> 4 & 1 ^ 1);
      }
      changeExtraColor(this,iVar7);
      if (pData->mData[0x157] == 0) {
        f_op_msg_mng::fopMsgM_paneScaleXY(unaff_r28,DAT_803e4aa0);
        fVar3 = *(float *)(this + 0x38e0) * DAT_803e4aa0;
        fVar1 = *(float *)(this + 0x38e4) * DAT_803e4aa0;
        MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + iVar6 + 0x38f4),"New Game");
        pJVar4 = unaff_r28->mpPane;
        fVar2 = d_file_select::_4050;
        if (d_file_select::_4050 < fVar3) {
          fVar2 = fVar3;
        }
        pJVar4[1].parent.mPosBR.x = fVar2;
        fVar3 = d_file_select::_4050;
        if (d_file_select::_4050 < fVar1) {
          fVar3 = fVar1;
        }
        pJVar4[1].parent.mPosBR.y = fVar3;
        f_op_msg_mng::fopMsgM_paneTrans
                  (unaff_r28,(double)((unaff_r28->mPosTopLeftOrig).x - (unaff_r28->mPosTopLeft).x),
                   (double)(DAT_803e4aa4 +
                           ((unaff_r28->mPosTopLeftOrig).y - (unaff_r28->mPosTopLeft).y)));
        MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + iVar6 + 0x3900),"");
        this[iVar7 + 0x3914] = (dFile_select_c)0x1;
      }
      else {
        MSL_C.PPCEABI.bare.H::strcpy
                  (*(char **)(this + iVar6 + 0x38f4),(char *)(pData->mData + 0x157));
        os::OSTicksToCalendarTime
                  (*(int32_t *)(pData->mData + 0x18),*(int32_t *)(pData->mData + 0x1c),&local_58);
        MSL_C.PPCEABI.bare.H::sprintf
                  (*(char **)(this + iVar6 + 0x3900),"%02d/%02d/%d %02d:%02d:%02d",local_58.mon + 1,
                   local_58.mday,local_58.year,local_58.hour,local_58.min,local_58.sec);
        this[iVar7 + 0x3914] = (dFile_select_c)0x0;
      }
      this[iVar7 + 0x3917] = (dFile_select_c)0x0;
    }
    iVar7 = iVar7 + 1;
    pData = pData + 1;
    iVar6 = iVar6 + 4;
  } while (iVar7 < 3);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* __thiscall dFile_select_c::changeExtraColor(int) */

void __thiscall dFile_select_c::changeExtraColor(dFile_select_c *this,int param_1)

{
  dFile_select_c *in_r5;
  dFile_select_c *in_r6;
  int *in_r7;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 1) {
    in_r5 = this + 0x15b8;
    in_r6 = this + 0x2310;
    in_r7 = (int *)(this + 0x1158);
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        in_r5 = this + 0x1238;
        in_r6 = this + 0x1cb8;
        in_r7 = (int *)(this + 0x10e8);
      }
    }
    else {
      if (param_1 < 3) {
        in_r5 = this + 0x1938;
        in_r6 = this + 0x2968;
        in_r7 = (int *)(this + 0x11c8);
      }
    }
  }
  iVar1 = *(int *)(in_r5 + 0x38);
  *(undefined *)(iVar1 + 0x108) = 0;
  *(undefined *)(iVar1 + 0x109) = 0;
  *(undefined *)(iVar1 + 0x10a) = 0;
  *(undefined *)(iVar1 + 0x10b) = 0;
  *(undefined *)(iVar1 + 0x104) = 0xdc;
  *(undefined *)(iVar1 + 0x105) = 0xff;
  *(undefined *)(iVar1 + 0x106) = 100;
  *(undefined *)(iVar1 + 0x107) = 0xff;
  if (this[param_1 + 0x391a] == (dFile_select_c)0x1) {
    iVar1 = 0x70;
    iVar3 = 5;
    do {
      iVar2 = *(int *)(in_r5 + iVar1);
      *(undefined *)(iVar2 + 0x108) = 0x6e;
      *(undefined *)(iVar2 + 0x109) = 0x50;
      *(undefined *)(iVar2 + 0x10a) = 0;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0x96;
      *(undefined *)(iVar2 + 0x105) = 0x78;
      *(undefined *)(iVar2 + 0x106) = 0;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar2 = *(int *)((int)(in_r5 + iVar1) + 0x118);
      *(undefined *)(iVar2 + 0x108) = 0xdc;
      *(undefined *)(iVar2 + 0x109) = 0xa0;
      *(undefined *)(iVar2 + 0x10a) = 0;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0xff;
      *(undefined *)(iVar2 + 0x105) = 0xb4;
      *(undefined *)(iVar2 + 0x106) = 0xf;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar1 = 0xa8;
    iVar3 = 9;
    do {
      iVar2 = *(int *)(in_r6 + iVar1);
      *(undefined *)(iVar2 + 0x108) = 0x6e;
      *(undefined *)(iVar2 + 0x109) = 0x50;
      *(undefined *)(iVar2 + 0x10a) = 0;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0x96;
      *(undefined *)(iVar2 + 0x105) = 0x78;
      *(undefined *)(iVar2 + 0x106) = 0;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar2 = *(int *)((int)(in_r6 + iVar1) + 0x1f8);
      *(undefined *)(iVar2 + 0x108) = 0xdc;
      *(undefined *)(iVar2 + 0x109) = 0xb4;
      *(undefined *)(iVar2 + 0x10a) = 0x5a;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0xff;
      *(undefined *)(iVar2 + 0x105) = 200;
      *(undefined *)(iVar2 + 0x106) = 0x5f;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*in_r7 + 0xaa) = 1;
    *(undefined *)(in_r7[0xe] + 0xaa) = 1;
  }
  else {
    iVar1 = 0x70;
    iVar3 = 5;
    do {
      iVar2 = *(int *)(in_r5 + iVar1);
      *(undefined *)(iVar2 + 0x108) = 0x28;
      *(undefined *)(iVar2 + 0x109) = 0x6e;
      *(undefined *)(iVar2 + 0x10a) = 0x1e;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0x8c;
      *(undefined *)(iVar2 + 0x105) = 0xb4;
      *(undefined *)(iVar2 + 0x106) = 0x50;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar2 = *(int *)((int)(in_r5 + iVar1) + 0x118);
      *(undefined *)(iVar2 + 0x108) = 0xbe;
      *(undefined *)(iVar2 + 0x109) = 0xdc;
      *(undefined *)(iVar2 + 0x10a) = 0x8c;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0xd2;
      *(undefined *)(iVar2 + 0x105) = 0xff;
      *(undefined *)(iVar2 + 0x106) = 0x73;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar1 = 0xa8;
    iVar3 = 9;
    do {
      iVar2 = *(int *)(in_r6 + iVar1);
      *(undefined *)(iVar2 + 0x108) = 0xff;
      *(undefined *)(iVar2 + 0x109) = 0xf0;
      *(undefined *)(iVar2 + 0x10a) = 0xbe;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0xff;
      *(undefined *)(iVar2 + 0x105) = 0xff;
      *(undefined *)(iVar2 + 0x106) = 0xff;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar2 = *(int *)((int)(in_r6 + iVar1) + 0x1f8);
      *(undefined *)(iVar2 + 0x108) = 100;
      *(undefined *)(iVar2 + 0x109) = 0x96;
      *(undefined *)(iVar2 + 0x10a) = 0x32;
      *(undefined *)(iVar2 + 0x10b) = 0;
      *(undefined *)(iVar2 + 0x104) = 0xb4;
      *(undefined *)(iVar2 + 0x105) = 0xdc;
      *(undefined *)(iVar2 + 0x106) = 100;
      *(undefined *)(iVar2 + 0x107) = 0xff;
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (*(char *)(*in_r7 + 0xaa) != '\0') {
      *(undefined *)(*in_r7 + 0xaa) = 0;
      *(undefined *)(in_r7[0xe] + 0xaa) = 0;
    }
  }
  return;
}


/* __thiscall dFile_select_c::changeBrokenColor(int) */

void __thiscall dFile_select_c::changeBrokenColor(dFile_select_c *this,int param_1)

{
  dFile_select_c *in_r0;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 1) {
    param_1 = (int)(this + 0x15b8);
    in_r0 = this + 0x2310;
    this = this + 0x1158;
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        param_1 = (int)(this + 0x1238);
        in_r0 = this + 0x1cb8;
        this = this + 0x10e8;
      }
    }
    else {
      if (param_1 < 3) {
        param_1 = (int)(this + 0x1938);
        in_r0 = this + 0x2968;
        this = this + 0x11c8;
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0x38);
  *(undefined *)(iVar1 + 0x108) = 0;
  *(undefined *)(iVar1 + 0x109) = 0;
  *(undefined *)(iVar1 + 0x10a) = 0;
  *(undefined *)(iVar1 + 0x10b) = 0;
  *(undefined *)(iVar1 + 0x104) = 0xdc;
  *(undefined *)(iVar1 + 0x105) = 0xff;
  *(undefined *)(iVar1 + 0x106) = 100;
  *(undefined *)(iVar1 + 0x107) = 0xff;
  iVar1 = 0x70;
  iVar3 = 5;
  do {
    iVar2 = *(int *)(param_1 + iVar1);
    *(undefined *)(iVar2 + 0x108) = 0x28;
    *(undefined *)(iVar2 + 0x109) = 0x6e;
    *(undefined *)(iVar2 + 0x10a) = 0x1e;
    *(undefined *)(iVar2 + 0x10b) = 0;
    *(undefined *)(iVar2 + 0x104) = 0x8c;
    *(undefined *)(iVar2 + 0x105) = 0xb4;
    *(undefined *)(iVar2 + 0x106) = 0x50;
    *(undefined *)(iVar2 + 0x107) = 0xff;
    iVar2 = ((int *)(param_1 + iVar1))[0x46];
    *(undefined *)(iVar2 + 0x108) = 0xbe;
    *(undefined *)(iVar2 + 0x109) = 0xdc;
    *(undefined *)(iVar2 + 0x10a) = 0x8c;
    *(undefined *)(iVar2 + 0x10b) = 0;
    *(undefined *)(iVar2 + 0x104) = 0xd2;
    *(undefined *)(iVar2 + 0x105) = 0xff;
    *(undefined *)(iVar2 + 0x106) = 0x73;
    *(undefined *)(iVar2 + 0x107) = 0xff;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0xa8;
  iVar3 = 9;
  do {
    iVar2 = *(int *)(in_r0 + iVar1);
    *(undefined *)(iVar2 + 0x108) = 0x50;
    *(undefined *)(iVar2 + 0x109) = 0x50;
    *(undefined *)(iVar2 + 0x10a) = 0x50;
    *(undefined *)(iVar2 + 0x10b) = 0;
    *(undefined *)(iVar2 + 0x104) = 0x78;
    *(undefined *)(iVar2 + 0x105) = 0x78;
    *(undefined *)(iVar2 + 0x106) = 0x78;
    *(undefined *)(iVar2 + 0x107) = 0xff;
    iVar2 = *(int *)((int)(in_r0 + iVar1) + 0x1f8);
    *(undefined *)(iVar2 + 0x108) = 0x96;
    *(undefined *)(iVar2 + 0x109) = 0x96;
    *(undefined *)(iVar2 + 0x10a) = 0x96;
    *(undefined *)(iVar2 + 0x10b) = 0;
    *(undefined *)(iVar2 + 0x104) = 200;
    *(undefined *)(iVar2 + 0x105) = 200;
    *(undefined *)(iVar2 + 0x106) = 200;
    *(undefined *)(iVar2 + 0x107) = 0xff;
    iVar1 = iVar1 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (*(char *)(*(int *)this + 0xaa) != '\0') {
    *(undefined *)(*(int *)this + 0xaa) = 0;
    *(undefined *)(*(int *)((int)this + 0x38) + 0xaa) = 0;
  }
  return;
}


/* __thiscall dFile_select_c::_draw(void) */

void __thiscall dFile_select_c::_draw(dFile_select_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 4));
  return;
}


/* __thiscall dDlst_FileSel_c::draw(void) */

void __thiscall dDlst_FileSel_c::draw(dDlst_FileSel_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_file_select::_4050,d_file_select::_4050,&pCtx->parent)
  ;
  return;
}


/* __thiscall dFile_select_c::dataSelectEx(void) */

void __thiscall dFile_select_c::dataSelectEx(dFile_select_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0x3910));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) {
      if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 0;
        *(undefined2 *)(this + 0x3930) = 0;
        this[0x392e] = (dFile_select_c)0x0;
        this[0x392c] = (dFile_select_c)0x3;
        this[0x3936] = (dFile_select_c)0x3;
        this[0x392b] = (dFile_select_c)0x26;
      }
      else {
        cVar1 = STControl::checkUpTrigger(*(STControl **)(this + 0x3910));
        if (cVar1 == '\0') {
          cVar1 = STControl::checkDownTrigger(*(STControl **)(this + 0x3910));
          if ((cVar1 != '\0') && (this[0x3922] != (dFile_select_c)0x2)) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
            this[0x3922] = (dFile_select_c)((char)this[0x3922] + '\x01');
            *(float *)(this + 0x3948) = d_file_select::_4050;
            this[0x3923] = (dFile_select_c)0x1;
            *(undefined2 *)(this + 0x3930) = 0;
            this[0x392b] = (dFile_select_c)0x1;
            recCursorMove(this);
          }
        }
        else {
          if (this[0x3922] != (dFile_select_c)0x0) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                       d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
            this[0x3922] = (dFile_select_c)((char)this[0x3922] + -1);
            *(float *)(this + 0x3948) = d_file_select::_4050;
            this[0x3923] = (dFile_select_c)0xff;
            *(undefined2 *)(this + 0x3930) = 0;
            this[0x392b] = (dFile_select_c)0x1;
            recCursorMove(this);
          }
        }
      }
      goto LAB_8018cc74;
    }
  }
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x831,(cXyz *)0x0,0,0,d_file_select::_4329,d_file_select::_4329,
             d_file_select::_4330,d_file_select::_4330,0);
  this[0x3936] = (dFile_select_c)0x4;
  *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 0;
  f_op_msg_mng::fopMsgM_messageGet
            (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x4f);
  dataSelMoveSet(this);
  this[0x392b] = (dFile_select_c)0x1b;
LAB_8018cc74:
  recCursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_select_c::ExSavePaneMove(void) */

void __thiscall dFile_select_c::ExSavePaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = recDataPaneMove(this);
  if (this[(byte)this[0x3922] + 0x3917] == (dFile_select_c)0x0) {
    iVar2 = recInfoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4050,
                            d_file_select::_4050,d_file_select::_4050,
                            (ushort)DAT_803e4a7c + (ushort)(byte)this[0x3920],'\x01',0);
  }
  else {
    iVar2 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000)
                                        - d_file_select::_4148),d_file_select::_4050,
                            d_file_select::_4050,d_file_select::_4050,
                            (ushort)DAT_803e4a7c + (ushort)(byte)this[0x3920],'\x01',0);
  }
  iVar3 = yesNoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                                    d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a84,
                        '\x01',0);
  iVar4 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) && (iVar4 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    menuCursorAlphaInit(this);
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 1;
    this[0x3928] = (dFile_select_c)0x1;
    yesNoCursorMove(this);
    this[0x392b] = (dFile_select_c)0x1c;
  }
  return;
}


/* __thiscall dFile_select_c::YesNoSelectEx(void) */

void __thiscall dFile_select_c::YesNoSelectEx(dFile_select_c *this)

{
  int iVar1;
  char cVar2;
  
  STControl::checkTrigger(*(STControl **)(this + 0x390c));
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      this[0x3936] = (dFile_select_c)0x4;
      *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
      this[0x3928] = (dFile_select_c)0x1;
      this[0x392b] = (dFile_select_c)0x1d;
      **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
    }
    else {
      cVar2 = STControl::checkRightTrigger(*(STControl **)(this + 0x390c));
      if (cVar2 == '\0') {
        cVar2 = STControl::checkLeftTrigger(*(STControl **)(this + 0x390c));
        if ((cVar2 != '\0') && (this[0x3928] != (dFile_select_c)0x0)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          this[0x3928] = (dFile_select_c)0x0;
          *(undefined2 *)(this + 0x3930) = 0;
          yesNoCursorMove(this);
        }
      }
      else {
        if (this[0x3928] != (dFile_select_c)0x1) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x830,(cXyz *)0x0,0,0,d_file_select::_4329,
                     d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
          this[0x3928] = (dFile_select_c)0x1;
          *(undefined2 *)(this + 0x3930) = 0;
          yesNoCursorMove(this);
        }
      }
    }
  }
  else {
    if (this[0x3928] == (dFile_select_c)0x0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x89a,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      iVar1 = ExCardCheck(this);
      if (iVar1 == 0) {
        this[0x392b] = (dFile_select_c)0x1d;
      }
      else {
        this[0x392e] = (dFile_select_c)0x1;
        this[0x392f] = SUB41(iVar1,0);
        this[0x392a] = (dFile_select_c)0x6;
        this[0x392c] = (dFile_select_c)0x2;
        this[0x3936] = (dFile_select_c)0x3;
        this[0x392b] = (dFile_select_c)0x26;
      }
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x832,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      this[0x3936] = (dFile_select_c)0x5;
      this[0x392b] = (dFile_select_c)0x1d;
    }
    *(undefined *)(*(int *)(this + 0x30d8) + 0xaa) = 0;
    **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
  }
  menuCursorAnime(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dFile_select_c::ExSavePaneMove0(void) */

void __thiscall dFile_select_c::ExSavePaneMove0(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (this[(byte)this[0x3922] + 0x3917] == (dFile_select_c)0x0) {
    iVar1 = recInfoPaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                            (ushort)DAT_803e4a7d,'\0',1);
  }
  else {
    iVar1 = MessagePaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                            (ushort)DAT_803e4a7d,'\0',1);
  }
  iVar2 = yesNoPaneMove(this,d_file_select::_4050,
                        (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a8e ^ 0x80000000) -
                               d_file_select::_4148),(ushort)DAT_803e4a82,'\0',1);
  iVar3 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar1 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    if (this[0x3928] == (dFile_select_c)0x0) {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x50);
      f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),0x25);
      MessagePaneMoveSet(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                     d_file_select::_4148),*(float *)(this + 0x3944),
                         d_file_select::_4050,*(float *)(this + 0x3944),'\x01',0);
      this[0x392b] = (dFile_select_c)0x1e;
    }
    else {
      this[0x3929] = (dFile_select_c)0xff;
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x4e);
      this[0x392b] = (dFile_select_c)0x21;
    }
  }
  return;
}


/* __thiscall dFile_select_c::ExCardCheck(void) */

byte __thiscall dFile_select_c::ExCardCheck(dFile_select_c *this)

{
  mDoMemCd_Ctrl_status mVar1;
  byte bVar2;
  
  mVar1 = mDoMemCd_Ctrl_c::getStatus(&m_Do_MemCard::g_mDoMemCd_control,0);
  if (mVar1 == CREATE) {
    if (d_com_inf_game::g_dComIfG_gameInfo._4753_1_ == '\x01') {
      bVar2 = 0;
    }
    else {
      if ((d_com_inf_game::g_dComIfG_gameInfo._4764_4_ ^ DAT_803b502c |
          d_com_inf_game::g_dComIfG_gameInfo._4760_4_ ^ DAT_CardSerialNo) == 0) {
        bVar2 = -(d_com_inf_game::g_dComIfG_gameInfo._4754_1_ != '\0') & 2;
      }
      else {
        bVar2 = 2;
      }
    }
  }
  else {
    bVar2 = 1;
  }
  return bVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dFile_select_c::ExBackDatSelPaneMove(void) */

void __thiscall dFile_select_c::ExBackDatSelPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = DataSelectPaneBackMove
                    (this,(ushort)DAT_803e4a75,(ushort)DAT_803e4a76,(ushort)DAT_803e4a75);
  if ((this[0x3929] != (dFile_select_c)0xff) && (this[0x3929] == (dFile_select_c)0x1)) {
    iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4050,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                   d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a7d,
                            '\0',1);
  }
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((iVar1 == 1) && (iVar3 == 1)) && (iVar2 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3932) = DAT_803e4a96;
    *(undefined *)(*(int *)(this + 0x2fc0) + 0xaa) = 1;
    recCursorMove(this);
    this[0x392b] = (dFile_select_c)0x1a;
  }
  return;
}


/* __thiscall dFile_select_c::ExSavePaneMove1(void) */

void __thiscall dFile_select_c::ExSavePaneMove1(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                      d_file_select::_4148),*(float *)(this + 0x3944),
                          d_file_select::_4050,*(float *)(this + 0x3944),(ushort)DAT_803e4a7d,'\x01'
                          ,0);
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    this[0x392b] = (dFile_select_c)0x1f;
  }
  else {
    *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  }
  return;
}


/* __thiscall dFile_select_c::ExDataSave(void) */

void __thiscall dFile_select_c::ExDataSave(dFile_select_c *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  dSv_info_c::reinit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo);
  dSv_info_c::memory_to_card
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(char **)(this + 0x3938),
             (uint)(byte)this[0x3922]);
  m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(*(undefined4 *)(this + 0x3938),this[0x3922]);
  uVar2 = 0;
  uVar1 = (uint)d_com_inf_game::g_dComIfG_gameInfo._23547_1_;
  iVar3 = 3;
  do {
    uVar1 = uVar1 | 1 << (uVar2 & 0xff) & 0xffU;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  d_com_inf_game::g_dComIfG_gameInfo._23547_1_ = (byte)uVar1;
  d_com_inf_game::g_dComIfG_gameInfo._4752_1_ = this[0x3922];
  DAT_803b4ff4 = 0;
  mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,*(void **)(this + 0x3938),0x1650,0);
  this[0x392b] = (dFile_select_c)0x20;
  return;
}


/* __thiscall dFile_select_c::ExDataSaveWait(void) */

void __thiscall dFile_select_c::ExDataSaveWait(dFile_select_c *this)

{
  int iVar1;
  
  iVar1 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  if (iVar1 != 0) {
    if (iVar1 == 2) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8be,(cXyz *)0x0,0,0,d_file_select::_4329,
                 d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
      *(undefined2 *)(this + 0x3930) = 0;
      this[0x3929] = (dFile_select_c)0x1;
      *(float *)(this + 0x3944) = d_file_select::_4050;
      **(undefined **)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8) = 0;
      this[0x392b] = (dFile_select_c)0x24;
    }
    else {
      if (iVar1 == 1) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8bd,(cXyz *)0x0,0,0,d_file_select::_4329,
                   d_file_select::_4329,d_file_select::_4330,d_file_select::_4330,0);
        *(undefined2 *)(this + 0x3930) = 0;
        this[0x3929] = (dFile_select_c)0x0;
        DAT_803b4ff4 = 0;
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x392d] ^ 1) * 4 + 0x38e8),0x51);
        this[0x392b] = (dFile_select_c)0x22;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8018d7a0) */
/* __thiscall dFile_select_c::ExDataSavePaneMoveOk(void) */

void __thiscall dFile_select_c::ExDataSavePaneMoveOk(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int iVar3;
  int unaff_r29;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r29 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                   DAT_803e4a5e,d_file_select::_4050,d_file_select::_4196,
                                   d_file_select::_4050,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a8a ^ 0x80000000) -
                                          d_file_select::_4148) - d_file_select::_4299,DAT_803e4a53,
                                   1);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r29 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                     DAT_803e4a5d,d_file_select::_4050,d_file_select::_4050,
                                     d_file_select::_4050,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a8a ^ 0x80000000) -
                                            d_file_select::_4148),DAT_803e4a53,1);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r29 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a86,
                                       DAT_803e4a5f,d_file_select::_4050,d_file_select::_4197,
                                       d_file_select::_4050,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a8a ^ 0x80000000) -
                                              d_file_select::_4148) - d_file_select::_5953,
                                       DAT_803e4a53,1);
      }
    }
  }
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  iVar3 = MessagePaneMove(this,d_file_select::_4050,d_file_select::_4050,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                 d_file_select::_4148),d_file_select::_4050,(ushort)DAT_803e4a87,
                          '\x01',1);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (((unaff_r29 == 1) && (iVar2 == 1)) && (iVar3 == 1)) {
    setSaveData(this);
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x23;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8018d9d0) */
/* __thiscall dFile_select_c::ExDataSavePaneMoveOk2(void) */

void __thiscall dFile_select_c::ExDataSavePaneMoveOk2(dFile_select_c *this)

{
  dFile_select_c dVar1;
  int iVar2;
  int unaff_r30;
  
  dVar1 = this[0x3922];
  if (dVar1 == (dFile_select_c)0x1) {
    unaff_r30 = PaneTranceRecInfo2(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                   DAT_803e4a5e,
                                   (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_803e4a88 ^ 0x80000000) -
                                          d_file_select::_4148),d_file_select::_4196,
                                   d_file_select::_4050,d_file_select::_4196,DAT_803e4a53,0);
  }
  else {
    if (dVar1 == (dFile_select_c)0x0) {
      unaff_r30 = PaneTranceRecInfo1(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                     DAT_803e4a5d,
                                     (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_803e4a88 ^ 0x80000000) -
                                            d_file_select::_4148),d_file_select::_4050,
                                     d_file_select::_4050,d_file_select::_4050,DAT_803e4a53,0);
    }
    else {
      if ((byte)dVar1 < 3) {
        unaff_r30 = PaneTranceRecInfo3(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a87,
                                       DAT_803e4a5f,
                                       (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_803e4a88 ^ 0x80000000) -
                                              d_file_select::_4148),d_file_select::_4197,
                                       d_file_select::_4050,d_file_select::_4197,DAT_803e4a53,0);
      }
    }
  }
  iVar2 = recInfoPaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                      d_file_select::_4148),d_file_select::_4050,
                          d_file_select::_4050,d_file_select::_4050,(ushort)DAT_803e4a7c,'\x01',0);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((unaff_r30 == 1) && (iVar2 == 1)) {
    this[0x392c] = (dFile_select_c)0x1;
  }
  return;
}


/* __thiscall dFile_select_c::ExErrorMsgPaneMove(void) */

void __thiscall dFile_select_c::ExErrorMsgPaneMove(dFile_select_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MessagePaneMove(this,d_file_select::_4050,*(float *)(this + 0x3944),
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e4a92 ^ 0x80000000) -
                                 d_file_select::_4148),*(float *)(this + 0x3944),
                          (ushort)DAT_803e4a7d,'\0',1);
  iVar2 = PaneAlphaTitleTxt(this,*(short *)(this + 0x3930) - (ushort)DAT_803e4a75,DAT_803e4a55);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x392d] = (dFile_select_c)((byte)this[0x392d] ^ 1);
    f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + 0x38f0),0x3d);
    MessagePaneMoveSet(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                   d_file_select::_4148),*(float *)(this + 0x3944),
                       d_file_select::_4050,*(float *)(this + 0x3944),'\x01',0);
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392b] = (dFile_select_c)0x25;
  }
  return;
}


/* __thiscall dFile_select_c::ExErrorMsgPaneMove2(void) */

void __thiscall dFile_select_c::ExErrorMsgPaneMove2(dFile_select_c *this)

{
  int iVar1;
  
  iVar1 = MessagePaneMove(this,(float)((double)CONCAT44(0x43300000,(int)DAT_803e4a90 ^ 0x80000000) -
                                      d_file_select::_4148),*(float *)(this + 0x3944),
                          d_file_select::_4050,*(float *)(this + 0x3944),(ushort)DAT_803e4a7d,'\x01'
                          ,0);
  *(short *)(this + 0x3930) = *(short *)(this + 0x3930) + 1;
  if (iVar1 == 1) {
    *(undefined2 *)(this + 0x3930) = 0;
    this[0x392a] = (dFile_select_c)0x5;
    this[0x392b] = (dFile_select_c)0x18;
  }
  return;
}


/* __thiscall dDlst_FileSel_c::~dDlst_FileSel_c(void) */

void __thiscall dDlst_FileSel_c::_dDlst_FileSel_c(dDlst_FileSel_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FileSel_c *)0x0) {
    *(char **)this = d_file_select::l_Collec_6111 + 0x1a8;
    if (this != (dDlst_FileSel_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dFs_HIO_c::~dFs_HIO_c(void) */

void __thiscall dFs_HIO_c::_dFs_HIO_c(dFs_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dFs_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_file_select {

void __sinit_d_file_select_cpp(void)

{
  ::dFs_HIO_c::dFs_HIO_c((dFs_HIO_c *)&g_fsHIO);
  Runtime.PPCEABI.H::__register_global_object();
  DataSelProc = _4076;
  DAT_80391598 = DAT_803913c4;
  DAT_8039159c = PTR_dataSelect_803913c8;
  DAT_803915a0 = _4077;
  DAT_803915a4 = DAT_803913d0;
  DAT_803915a8 = PTR_SelectTitAnime_803913d4;
  DAT_803915ac = _4078;
  DAT_803915b0 = DAT_803913dc;
  DAT_803915b4 = PTR_dataSelectPaneMove_803913e0;
  DAT_803915b8 = _4079;
  DAT_803915bc = DAT_803913e8;
  DAT_803915c0 = PTR_menuSelect_803913ec;
  DAT_803915c4 = _4080;
  DAT_803915c8 = DAT_803913f4;
  DAT_803915cc = PTR_ToCopyPaneMove_803913f8;
  DAT_803915d0 = _4081;
  DAT_803915d4 = DAT_80391400;
  DAT_803915d8 = PTR_ToErasePaneMove_80391404;
  DAT_803915dc = _4082;
  DAT_803915e0 = DAT_8039140c;
  DAT_803915e4 = PTR_ToBackPaneMove_80391410;
  DAT_803915e8 = _4083;
  DAT_803915ec = DAT_80391418;
  DAT_803915f0 = PTR_copyDataToSelect_8039141c;
  DAT_803915f4 = _4084;
  DAT_803915f8 = DAT_80391424;
  DAT_803915fc = PTR_copyDataSelAnime_80391428;
  DAT_80391600 = _4085;
  DAT_80391604 = DAT_80391430;
  DAT_80391608 = PTR_copyToSelBack_80391434;
  DAT_8039160c = _4086;
  DAT_80391610 = DAT_8039143c;
  DAT_80391614 = PTR_copyToSelPaneMove_80391440;
  DAT_80391618 = _4087;
  DAT_8039161c = DAT_80391448;
  DAT_80391620 = PTR_YesNoSelect_8039144c;
  DAT_80391624 = _4088;
  DAT_80391628 = DAT_80391454;
  DAT_8039162c = PTR_CmdExecPaneMove0_80391458;
  DAT_80391630 = _4089;
  DAT_80391634 = DAT_80391460;
  DAT_80391638 = PTR_CmdExecPaneMove2_80391464;
  DAT_8039163c = _4090;
  DAT_80391640 = DAT_8039146c;
  DAT_80391644 = PTR_CommandExec_80391470;
  DAT_80391648 = _4091;
  DAT_8039164c = DAT_80391478;
  DAT_80391650 = PTR_DataEraseWait_8039147c;
  DAT_80391654 = _4092;
  DAT_80391658 = DAT_80391484;
  DAT_8039165c = PTR_DataCopyWait_80391488;
  DAT_80391660 = _4093;
  DAT_80391664 = DAT_80391490;
  DAT_80391668 = PTR_copyPaneMoveOk_80391494;
  DAT_8039166c = _4094;
  DAT_80391670 = DAT_8039149c;
  DAT_80391674 = PTR_copyPaneMoveOk2_803914a0;
  DAT_80391678 = _4095;
  DAT_8039167c = DAT_803914a8;
  DAT_80391680 = PTR_ErasePaneMoveOk_803914ac;
  DAT_80391684 = _4096;
  DAT_80391688 = DAT_803914b4;
  DAT_8039168c = PTR_ErasePaneMoveOk2_803914b8;
  DAT_80391690 = _4097;
  DAT_80391694 = DAT_803914c0;
  DAT_80391698 = PTR_ErrorMsgPaneMove_803914c4;
  DAT_8039169c = _4098;
  DAT_803916a0 = DAT_803914cc;
  DAT_803916a4 = PTR_ErrorMsgPaneMove2_803914d0;
  DAT_803916a8 = _4099;
  DAT_803916ac = DAT_803914d8;
  DAT_803916b0 = PTR_backDatSelWait_803914dc;
  DAT_803916b4 = _4100;
  DAT_803916b8 = DAT_803914e4;
  DAT_803916bc = PTR_backDatSelWait2_803914e8;
  DAT_803916c0 = _4101;
  DAT_803916c4 = DAT_803914f0;
  DAT_803916c8 = PTR_backDatSelPaneMove_803914f4;
  DAT_803916cc = _4102;
  DAT_803916d0 = DAT_803914fc;
  DAT_803916d4 = PTR_dataSelectEx_80391500;
  DAT_803916d8 = _4103;
  DAT_803916dc = DAT_80391508;
  DAT_803916e0 = PTR_ExSavePaneMove_8039150c;
  DAT_803916e4 = _4104;
  DAT_803916e8 = DAT_80391514;
  DAT_803916ec = PTR_YesNoSelectEx_80391518;
  DAT_803916f0 = _4105;
  DAT_803916f4 = DAT_80391520;
  DAT_803916f8 = PTR_ExSavePaneMove0_80391524;
  DAT_803916fc = _4106;
  DAT_80391700 = DAT_8039152c;
  DAT_80391704 = PTR_ExSavePaneMove1_80391530;
  DAT_80391708 = _4107;
  DAT_8039170c = DAT_80391538;
  DAT_80391710 = PTR_ExDataSave_8039153c;
  DAT_80391714 = _4108;
  DAT_80391718 = DAT_80391544;
  DAT_8039171c = PTR_ExDataSaveWait_80391548;
  DAT_80391720 = _4109;
  DAT_80391724 = DAT_80391550;
  DAT_80391728 = PTR_ExBackDatSelPaneMove_80391554;
  DAT_8039172c = _4110;
  DAT_80391730 = DAT_8039155c;
  DAT_80391734 = PTR_ExDataSavePaneMoveOk_80391560;
  DAT_80391738 = _4111;
  DAT_8039173c = DAT_80391568;
  DAT_80391740 = PTR_ExDataSavePaneMoveOk2_8039156c;
  DAT_80391744 = _4112;
  DAT_80391748 = DAT_80391574;
  DAT_8039174c = PTR_ExErrorMsgPaneMove_80391578;
  DAT_80391750 = _4113;
  DAT_80391754 = DAT_80391580;
  DAT_80391758 = PTR_ExErrorMsgPaneMove2_80391584;
  DAT_8039175c = _4114;
  DAT_80391760 = DAT_8039158c;
  DAT_80391764 = PTR_nextModeWait_80391590;
  return;
}

