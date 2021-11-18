#include <d_menu_save.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_lib.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_ext.h>
#include <d_file_error.h>
#include <m_Do_hostIO.h>
#include <d_menu_save.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_meter.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <f_op_msg_mng.h>
#include <m_Do_MemCard.h>
#include <os/OSReset.h>
#include <d_save.h>
#include <m_Do_MemCardRWmng.h>
#include <d_com_inf_game.h>
#include <J2DGraph/J2DTextBox.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMenu_save_c.h>
#include <dFile_error_c.h>
#include <dMs_HIO_c.h>
#include <dDlst_MenuSave_c.h>


namespace d_menu_save {
}

namespace d_menu_save {
undefined g_msHIO;
}

/* __thiscall dMs_HIO_c::dMs_HIO_c(void) */

void __thiscall dMs_HIO_c::dMs_HIO_c(dMs_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[5] = (dMs_HIO_c)0x5;
  this[6] = (dMs_HIO_c)0x0;
  this[7] = (dMs_HIO_c)0x0;
  this[8] = (dMs_HIO_c)0x5;
  *(undefined2 *)(this + 0xc) = 0xfe0c;
  *(undefined2 *)(this + 0xe) = 200;
  this[9] = (dMs_HIO_c)0x0;
  this[10] = (dMs_HIO_c)0x0;
  this[0xb] = (dMs_HIO_c)0x3;
  this[0x10] = (dMs_HIO_c)0x5;
  this[0x11] = (dMs_HIO_c)0x8;
  this[0x12] = (dMs_HIO_c)0x5;
  this[0x13] = (dMs_HIO_c)0x0;
  *(undefined2 *)(this + 0x14) = 0xff9c;
  *(undefined2 *)(this + 0x16) = 0x96;
  this[0x18] = (dMs_HIO_c)0x5;
  this[0x19] = (dMs_HIO_c)0x8;
  this[0x1a] = (dMs_HIO_c)0x5;
  this[0x1b] = (dMs_HIO_c)0x6;
  this[0x1c] = (dMs_HIO_c)0x2;
  *(undefined2 *)(this + 0x1e) = 200;
  this[0x20] = (dMs_HIO_c)0xc;
  this[0x21] = (dMs_HIO_c)0x8c;
  this[0x22] = (dMs_HIO_c)0x46;
  this[0x23] = (dMs_HIO_c)0x6;
  this[0x24] = (dMs_HIO_c)0x8;
  this[0x25] = (dMs_HIO_c)0x0;
  *(undefined2 *)(this + 0x26) = 3;
  this[0x28] = (dMs_HIO_c)0x5a;
  this[0x29] = (dMs_HIO_c)0xa;
  this[0x2a] = (dMs_HIO_c)0x0;
  *(undefined2 *)(this + 0x2c) = 0xffc4;
  this[0x2e] = (dMs_HIO_c)0x0;
  return;
}


/* __thiscall dMenu_save_c::_create(void) */

void __thiscall dMenu_save_c::_create(dMenu_save_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  STControl *this_01;
  JUTFont *pJVar2;
  undefined4 *puVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_menu_save::_4059;
    local_18.mTL.y = d_menu_save::_4059;
    local_18.mBR.x = d_menu_save::_4060;
    local_18.mBR.y = d_menu_save::_4061;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0xc) = this_00;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_save.cpp",0xa5,"MenuSave.Scr != 0");
    m_Do_printf::OSPanic("d_menu_save.cpp",0xa5,&DAT_8036072a);
  }
  this_01 = (STControl *)JKernel::operator_new(0x28);
  if (this_01 != (STControl *)0x0) {
    STControl::STControl(this_01,5,2,3,2,d_menu_save::_4062,d_menu_save::_4063,0,0x2000);
  }
  *(STControl **)(this + 0x528) = this_01;
  if (*(int *)(this + 0x528) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_save.cpp",0xaa,"stick != 0");
    m_Do_printf::OSPanic("d_menu_save.cpp",0xaa,&DAT_8036072a);
  }
  *(JKRArchive **)(this + 4) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSaveResArchive;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_save.cpp",0xae,"archive != 0");
    m_Do_printf::OSPanic("d_menu_save.cpp",0xae,&DAT_8036072a);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"menu_save.blo",*(JKRArchive **)(this + 4));
  pJVar2 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0x10) = pJVar2;
  if (*(int *)(this + 0x10) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_save.cpp",0xb4,"MenuSave.font != 0");
    m_Do_printf::OSPanic("d_menu_save.cpp",0xb4,&DAT_8036072a);
  }
  puVar3 = (undefined4 *)JKernel::operator_new(0x30c);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = &dFile_error_c::__vt;
    puVar3[2] = &dDlst_base_c::__vt;
    puVar3[2] = &dDlst_FileErr_c::__vt;
  }
  *(undefined4 **)(this + 0x524) = puVar3;
  if (*(int *)(this + 0x524) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_save.cpp",0xb8,"dFe_c != 0");
    m_Do_printf::OSPanic("d_menu_save.cpp",0xb8,&DAT_8036072a);
  }
  dFile_error_c::_create(*(dFile_error_c **)(this + 0x524));
  DAT_803e62f8 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"セーブ画面",
                            (JORReflexible *)&d_menu_save::g_msHIO);
  screenSet(this);
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dMenu_save_c::initialize(void) */

void __thiscall dMenu_save_c::initialize(dMenu_save_c *this)

{
  displayInit(this);
  paneTransInit(this);
  return;
}


/* __thiscall dMenu_save_c::_open(void) */

bool __thiscall dMenu_save_c::_open(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = openNormal(this);
  return iVar1 != 0;
}


/* WARNING: Removing unreachable block (ram,0x801d61d0) */
/* __thiscall dMenu_save_c::openNormal(void) */

undefined4 __thiscall dMenu_save_c::openNormal(dMenu_save_c *this)

{
  dMenu_save_c dVar1;
  dMenu_save_c *pdVar2;
  undefined4 uVar3;
  
  dVar1 = this[0x537];
  if (dVar1 == (dMenu_save_c)0x2) {
    pdVar2 = (dMenu_save_c *)openForGameover(this);
  }
  else {
    if ((byte)dVar1 < 2) {
      if (dVar1 == (dMenu_save_c)0x0) {
        pdVar2 = (dMenu_save_c *)openForItem(this);
      }
      else {
        pdVar2 = (dMenu_save_c *)openForCollect(this);
      }
    }
    else {
      pdVar2 = this;
      if ((byte)dVar1 < 4) {
        if (this[0x53c] == (dMenu_save_c)0x0) {
          pdVar2 = (dMenu_save_c *)openForEnding(this);
        }
        else {
          if (this[0x53d] == (dMenu_save_c)0x2) {
            pdVar2 = (dMenu_save_c *)openForEnding2(this);
          }
          else {
            pdVar2 = (dMenu_save_c *)&DAT_00000001;
          }
        }
      }
    }
  }
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (pdVar2 == (dMenu_save_c *)&DAT_00000001) {
    *(undefined2 *)(this + 0x544) = 0;
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    if (this[0x537] == (dMenu_save_c)0x3) {
      if (this[0x53c] == (dMenu_save_c)0x0) {
        this[0x53a] = (dMenu_save_c)0x0;
        this[0x52c] = (dMenu_save_c)0x0;
      }
      else {
        if (this[0x53d] == (dMenu_save_c)0x2) {
          this[0x53a] = (dMenu_save_c)0x0;
          this[0x535] = (dMenu_save_c)0x1;
          this[0x52c] = (dMenu_save_c)0x1b;
        }
        else {
          this[0x53a] = (dMenu_save_c)0x1;
          this[0x52c] = (dMenu_save_c)0x1;
        }
      }
    }
    else {
      this[0x53a] = (dMenu_save_c)0x0;
      this[0x52c] = (dMenu_save_c)0x0;
    }
    this[0x531] = (dMenu_save_c)0x2;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall dMenu_save_c::_close(void) */

bool __thiscall dMenu_save_c::_close(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = closeNormal(this);
  return iVar1 != 0;
}


/* WARNING: Removing unreachable block (ram,0x801d6328) */
/* __thiscall dMenu_save_c::closeNormal(void) */

bool __thiscall dMenu_save_c::closeNormal(dMenu_save_c *this)

{
  dMenu_save_c dVar1;
  dMenu_save_c *pdVar2;
  
  dVar1 = this[0x537];
  if (dVar1 == (dMenu_save_c)0x2) {
    pdVar2 = (dMenu_save_c *)closeForGameover(this);
  }
  else {
    if ((byte)dVar1 < 2) {
      if (dVar1 == (dMenu_save_c)0x0) {
        pdVar2 = (dMenu_save_c *)closeForItem(this);
      }
      else {
        pdVar2 = (dMenu_save_c *)closeForCollect(this);
      }
    }
    else {
      pdVar2 = this;
      if ((byte)dVar1 < 4) {
        pdVar2 = (dMenu_save_c *)closeForEnding(this);
      }
    }
  }
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (pdVar2 == (dMenu_save_c *)&DAT_00000001) {
    this[0x52c] = (dMenu_save_c)0x1a;
    this[0x531] = (dMenu_save_c)0x0;
    *(undefined2 *)(this + 0x544) = 0;
    this[0x53a] = (dMenu_save_c)0x1;
  }
  return pdVar2 == (dMenu_save_c *)&DAT_00000001;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_save_c::openForCollect(void) */

undefined4 __thiscall dMenu_save_c::openForCollect(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8b9,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  d_meter::dMenu_setPushMenuButton(0);
  iVar7 = 0;
  iVar1 = PaneAlphaMask(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fa,DAT_803e62f9,'\x01',0);
  iVar2 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4160,'\x01',0);
  if (iVar2 == 1) {
    iVar7 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fd + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4160,d_menu_save::_4059,'\x04',2);
  }
  iVar3 = PaneScaleAlphaWipe(this,*(short *)(this + 0x544) - (ushort)DAT_803e6318,DAT_803e6317,
                             (float)((double)CONCAT44(0x43300000,(int)DAT_803e631a ^ 0x80000000) -
                                    d_menu_save::_4162),'\x01',0);
  iVar4 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  iVar5 = menuUp(this);
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar7 == 1)) &&
     (((iVar3 == 1 && (iVar4 == 1)) && (iVar5 == 1)))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_save_c::openForItem(void) */

undefined4 __thiscall dMenu_save_c::openForItem(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8b9,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  d_meter::dMenu_setPushMenuButton(0);
  iVar7 = 0;
  iVar1 = PaneAlphaMask(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fa,DAT_803e62f9,'\x01',0);
  iVar2 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4160,'\x01',0);
  if (iVar2 == 1) {
    iVar7 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fd + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4160,d_menu_save::_4059,'\x04',2);
  }
  iVar3 = PaneScaleAlphaWipe(this,*(short *)(this + 0x544) - (ushort)DAT_803e6318,DAT_803e6317,
                             (float)((double)CONCAT44(0x43300000,(int)DAT_803e631a ^ 0x80000000) -
                                    d_menu_save::_4162),'\x01',0);
  iVar4 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  iVar5 = menuUp(this);
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar7 == 1)) &&
     (((iVar3 == 1 && (iVar4 == 1)) && (iVar5 == 1)))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_save_c::closeForCollect(void) */

undefined4 __thiscall dMenu_save_c::closeForCollect(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ba,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar7 = 0;
  d_meter::dMenu_setPushMenuButton(2);
  iVar1 = PaneAlphaMask(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fb,DAT_803e62f9,'\0',1);
  iVar2 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fe,DAT_803e62fc,
                         d_menu_save::_4059,d_menu_save::_4160,'\x04',2);
  if (iVar2 == 1) {
    iVar7 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fe + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar3 = PaneScaleAlphaWipe(this,*(short *)(this + 0x544) - (ushort)DAT_803e6319,DAT_803e6317,
                             d_menu_save::_4158,'\0',1);
  iVar4 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6306,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),'\0',1);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar5 = menuDown(this);
  }
  else {
    iVar5 = 1;
  }
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar7 == 1)) &&
     (((iVar3 == 1 && (iVar4 == 1)) && (iVar5 == 1)))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMenu_save_c::closeForItem(void) */

undefined4 __thiscall dMenu_save_c::closeForItem(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ba,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar7 = 0;
  d_meter::dMenu_setPushMenuButton(1);
  iVar1 = PaneAlphaMask(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fb,DAT_803e62f9,'\0',1);
  iVar2 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fe,DAT_803e62fc,
                         d_menu_save::_4059,d_menu_save::_4160,'\x04',2);
  if (iVar2 == 1) {
    iVar7 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fe + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar3 = PaneScaleAlphaWipe(this,*(short *)(this + 0x544) - (ushort)DAT_803e6319,DAT_803e6317,
                             d_menu_save::_4158,'\0',1);
  iVar4 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6306,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),'\0',1);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar5 = menuDown(this);
  }
  else {
    iVar5 = 1;
  }
  if ((((iVar1 == 1) && (iVar2 == 1)) && (iVar7 == 1)) &&
     (((iVar3 == 1 && (iVar4 == 1)) && (iVar5 == 1)))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801d6e40) */
/* WARNING: Removing unreachable block (ram,0x801d6e48) */
/* __thiscall dMenu_save_c::openForGameover(void) */

undefined4 __thiscall dMenu_save_c::openForGameover(dMenu_save_c *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  cXyz local_58;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8b9,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar5 = 0;
  uStack68 = (int)DAT_803e6300 ^ 0x80000000;
  local_48 = 0x43300000;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_save::_4162),
                         d_menu_save::_4059,'\x01',0);
  if ((*(short *)(this + 0x544) == (ushort)((ushort)DAT_803e62fd + (DAT_803e62fc - 2))) &&
     (this[0x539] != (dMenu_save_c)0x0)) {
    iVar3 = 0;
    iVar4 = 0;
    dVar7 = (double)d_menu_save::_4281;
    dVar8 = (double)d_menu_save::_4059;
    do {
      local_58.x = *(float *)((int)&d_menu_save::x_4244 + iVar4);
      local_58.y = (float)dVar7;
      local_58.z = (float)dVar8;
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,0x2e,&local_58,
                         (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                         (_GXColor *)0x0,(cXyz *)0x0);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < 4);
    this[0x539] = (dMenu_save_c)0x0;
  }
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fd + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,d_menu_save::_4282,'\x05',2);
  }
  uStack68 = (int)DAT_803e6308 ^ 0x80000000;
  local_48 = 0x43300000;
  iVar3 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,uStack68) - d_menu_save::_4162),
                          d_menu_save::_4059,'\x01',0);
  iVar4 = menuUp(this);
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar3 == 1)) && (iVar4 == 1)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return uVar2;
}


/* WARNING: Removing unreachable block (ram,0x801d6e8c) */
/* __thiscall dMenu_save_c::closeForGameover(void) */

void __thiscall dMenu_save_c::closeForGameover(dMenu_save_c *this)

{
  if (this[0x538] == (dMenu_save_c)0x1) {
    closeForGameover_1(this);
  }
  else {
    if (this[0x538] == (dMenu_save_c)0x0) {
      closeForGameover_2(this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::closeForGameover_1(void) */

undefined4 __thiscall dMenu_save_c::closeForGameover_1(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ba,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar5 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fe,DAT_803e62fc,
                         d_menu_save::_4059,d_menu_save::_4160,'\x04',2);
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fe + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6306,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),'\0',1);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar3 = menuDown(this);
  }
  else {
    iVar3 = 1;
  }
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar2 == 1)) && (iVar3 == 1)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dMenu_save_c::closeForGameover_2(void) */

undefined4 __thiscall dMenu_save_c::closeForGameover_2(dMenu_save_c *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
  iVar1 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6307,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                 d_menu_save::_4162),'\x01',2);
  PaneRotate(this,*(short *)(this + 0x544) - (ushort)DAT_803e6307,DAT_803e6304,
             (fopMsgM_pane_class *)(this + 0x324),d_menu_save::_4347,
             *(float *)(this + 0x34c) * d_menu_save::_4063,d_menu_save::_4348,'\0');
  if (iVar1 == 1) {
    iVar6 = PaneTranceTitle(this,*(short *)(this + 0x544) -
                                 ((ushort)DAT_803e6307 + (ushort)DAT_803e6304),DAT_803e6304,
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                   d_menu_save::_4162),
                            (float)((double)CONCAT44(0x43300000,(int)DAT_803e630a ^ 0x80000000) -
                                   d_menu_save::_4162),'\0',1);
  }
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62ff,DAT_803e62fc,
                         d_menu_save::_4059,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                d_menu_save::_4162),'\x01',2);
  PaneRotate(this,*(short *)(this + 0x544) - (ushort)DAT_803e62ff,DAT_803e6304,
             (fopMsgM_pane_class *)(this + 0x20c),d_menu_save::_4349,d_menu_save::_4059,
             d_menu_save::_4350,'\0');
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62ff + (ushort)DAT_803e62fc),DAT_803e62fc,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                  d_menu_save::_4162),
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6302 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar1 = PaneTranceMenu(this,*(short *)(this + 0x544) - (ushort)DAT_803e630f,DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x3cc),d_menu_save::_4059,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                d_menu_save::_4162),'\x01',2);
  PaneRotate(this,*(short *)(this + 0x544) - (ushort)DAT_803e630f,DAT_803e6304,
             (fopMsgM_pane_class *)(this + 0x3cc),d_menu_save::_4351,d_menu_save::_4352,
             d_menu_save::_4350,'\0');
  if (iVar1 == 1) {
    iVar4 = PaneTranceMenu(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e630f + (ushort)DAT_803e630c),DAT_803e630c,
                           (fopMsgM_pane_class *)(this + 0x3cc),
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                  d_menu_save::_4162),
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar1 = PaneTranceMenu(this,*(short *)(this + 0x544) -
                              ((ushort)DAT_803e630f + (ushort)DAT_803e6310),DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x474),d_menu_save::_4059,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                d_menu_save::_4162),'\x01',2);
  PaneRotate(this,*(short *)(this + 0x544) - ((ushort)DAT_803e630f + (ushort)DAT_803e6310),
             DAT_803e6304,(fopMsgM_pane_class *)(this + 0x474),d_menu_save::_4351,d_menu_save::_4352
             ,d_menu_save::_4348,'\0');
  if (iVar1 == 1) {
    iVar3 = PaneTranceMenu(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e630f + (ushort)DAT_803e6310 + (ushort)DAT_803e630c)
                           ,DAT_803e630c,(fopMsgM_pane_class *)(this + 0x474),
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6320 ^ 0x80000000) -
                                  d_menu_save::_4162),
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  if ((((iVar6 == 1) && (iVar5 == 1)) && (iVar4 == 1)) && (iVar3 == 1)) {
    PaneRotate(this,0,DAT_803e6304,(fopMsgM_pane_class *)(this + 0x324),d_menu_save::_4347,
               *(float *)(this + 0x34c) * d_menu_save::_4063,d_menu_save::_4059,'\0');
    PaneRotate(this,0,DAT_803e6304,(fopMsgM_pane_class *)(this + 0x20c),d_menu_save::_4353,
               d_menu_save::_4059,d_menu_save::_4059,'\0');
    PaneRotate(this,0,DAT_803e6304,(fopMsgM_pane_class *)(this + 0x3cc),d_menu_save::_4351,
               d_menu_save::_4352,d_menu_save::_4059,'\0');
    PaneRotate(this,0,DAT_803e6304,(fopMsgM_pane_class *)(this + 0x474),d_menu_save::_4351,
               d_menu_save::_4352,d_menu_save::_4059,'\0');
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::openForEnding(void) */

undefined4 __thiscall dMenu_save_c::openForEnding(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8b9,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar5 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fd + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,d_menu_save::_4282,'\x05',2);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  iVar3 = menuUp(this);
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar2 == 1)) && (iVar3 == 1)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::openForEnding2(void) */

undefined4 __thiscall dMenu_save_c::openForEnding2(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8b9,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar4 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  if (iVar1 == 1) {
    iVar4 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fd + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,d_menu_save::_4282,'\x05',2);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  if (((iVar1 == 1) && (iVar4 == 1)) && (iVar2 == 1)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::closeForEnding(void) */

undefined4 __thiscall dMenu_save_c::closeForEnding(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(short *)(this + 0x544) == 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ba,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
  }
  iVar5 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fe,DAT_803e62fc,
                         d_menu_save::_4059,d_menu_save::_4160,'\x04',2);
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,*(short *)(this + 0x544) -
                                ((ushort)DAT_803e62fe + (ushort)DAT_803e62fc),DAT_803e62fc,
                           d_menu_save::_4059,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6306,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),'\0',1);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar3 = menuDown(this);
  }
  else {
    iVar3 = 1;
  }
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar2 == 1)) && (iVar3 == 1)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* __thiscall dMenu_save_c::_delete(void) */

void __thiscall dMenu_save_c::_delete(dMenu_save_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  m_Do_ext::mDoExt_removeMesgFont();
  JKernel::operator_delete(*(JKRHeap **)(this + 0x528));
  dFile_error_c::_delete(*(dFile_error_c **)(this + 0x524));
  piVar1 = *(int **)(this + 0x524);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  (**(code **)(**(int **)(this + 4) + 0x24))();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e62f8);
  return;
}


/* __thiscall dMenu_save_c::_move(void) */

void __thiscall dMenu_save_c::_move(dMenu_save_c *this)

{
  if (*mDoRst::mResetData == 0) {
    if ((DAT_file_cursor == 0) || (DAT_file_cursor == 1)) {
      if ((this[0x53b] == (dMenu_save_c)0x0) &&
         ((*(dFile_error_c **)(this + 0x524))[0x2f5] == (dFile_error_c)0x1)) {
        dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x524));
        this[0x533] = (dMenu_save_c)0xff;
        this[0x52d] = (dMenu_save_c)0x1;
        this[0x52c] = (dMenu_save_c)0x6;
      }
      DAT_file_cursor = 2;
    }
    dFile_error_c::_move(*(dFile_error_c **)(this + 0x524));
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_menu_save::MenuSaveProc + (uint)(byte)this[0x52c] * 3),this,&DAT_80390000
              );
  }
  return;
}


/* __thiscall dMenu_save_c::noSave(void) */

void __thiscall dMenu_save_c::noSave(dMenu_save_c *this)

{
  this[0x533] = (dMenu_save_c)0xff;
  dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x524),0x65,0);
  this[0x52c] = (dMenu_save_c)0x6;
  this[0x52d] = (dMenu_save_c)0x26;
  return;
}


/* __thiscall dMenu_save_c::noSave2(void) */

void __thiscall dMenu_save_c::noSave2(dMenu_save_c *this)

{
  this[0x52c] = (dMenu_save_c)0x1a;
  this[0x531] = (dMenu_save_c)0x3;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801d7c84) */
/* __thiscall dMenu_save_c::saveQuestion(void) */

void __thiscall dMenu_save_c::saveQuestion(dMenu_save_c *this)

{
  int iVar1;
  
  if ((this[0x537] == (dMenu_save_c)0x2) || (this[0x537] == (dMenu_save_c)0x3)) {
    iVar1 = YesNoSelect2(this,0);
  }
  else {
    iVar1 = YesNoSelect(this,0);
  }
  if (iVar1 != 0) {
    if (this[0x52f] == (dMenu_save_c)0x0) {
      **(undefined **)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c) = 0;
      this[0x52c] = (dMenu_save_c)0x1;
    }
    else {
      if (this[0x52f] == (dMenu_save_c)0x2) {
        this[0x52c] = (dMenu_save_c)0x1a;
        this[0x531] = (dMenu_save_c)0x3;
      }
      else {
        *(undefined2 *)(this + 0x544) = 0;
        if (this[0x537] == (dMenu_save_c)0x3) {
          f_op_msg_mng::fopMsgM_messageGet
                    (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x4d);
          this[0x52c] = (dMenu_save_c)0x21;
        }
        else {
          if ((byte)this[0x537] < 3) {
            f_op_msg_mng::fopMsgM_messageGet
                      (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x40);
            this[0x52c] = (dMenu_save_c)0x1d;
          }
        }
      }
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardCheck(void) */

void __thiscall dMenu_save_c::memCardCheck(dMenu_save_c *this)

{
  mDoMemCd_Ctrl_status mVar1;
  
  mVar1 = mDoMemCd_Ctrl_c::getStatus(&m_Do_MemCard::g_mDoMemCd_control,0);
  switch(mVar1) {
  case STANDBY:
    this[0x532] = (dMenu_save_c)0x29;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x4;
    break;
  case RESTORE:
    this[0x532] = (dMenu_save_c)0x34;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0xd;
    break;
  case CREATE:
    DAT_803b4ff0 = 0;
    mDoMemCd_Ctrl_c::load(&m_Do_MemCard::g_mDoMemCd_control);
    this[0x52c] = (dMenu_save_c)0x10;
    break;
  case ENCODING:
  case ERROR:
    this[0x532] = (dMenu_save_c)0x2d;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x9;
    break;
  case 8:
    this[0x532] = (dMenu_save_c)0x2a;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x4;
    break;
  case 9:
    this[0x532] = (dMenu_save_c)0x2b;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x4;
    break;
  case WRONG_DEVICE:
    this[0x532] = (dMenu_save_c)0x2c;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x4;
    break;
  case 0xb:
  case IOERROR:
    this[0x532] = (dMenu_save_c)0x2e;
    this[0x52c] = (dMenu_save_c)0x3;
    this[0x52d] = (dMenu_save_c)0x5;
    this[0x533] = (dMenu_save_c)0x62;
    this[0x52e] = (dMenu_save_c)0x7;
  }
  return;
}


/* __thiscall dMenu_save_c::openSaveMenu(void) */

void __thiscall dMenu_save_c::openSaveMenu(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = openSave(this);
  if (iVar1 == 1) {
    this[0x53a] = (dMenu_save_c)0x0;
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    CursorAlphaInit(this);
    this[0x52c] = (dMenu_save_c)0x0;
  }
  return;
}


/* __thiscall dMenu_save_c::closeSaveMenu(void) */

void __thiscall dMenu_save_c::closeSaveMenu(dMenu_save_c *this)

{
  int iVar1;
  
  if (this[0x53a] == (dMenu_save_c)0x1) {
    iVar1 = 1;
  }
  else {
    iVar1 = closeSave(this);
  }
  if (iVar1 == 1) {
    this[0x53a] = (dMenu_save_c)0x1;
    if (this[0x537] == (dMenu_save_c)0x3) {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + (uint)(byte)this[0x536] * 4 + 0x51c),0x4c);
    }
    else {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + (uint)(byte)this[0x536] * 4 + 0x51c),0x39);
    }
    dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x524),(uint)(byte)this[0x532],0);
    this[0x52c] = this[0x52d];
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrMsgWaitKey(void) */

void __thiscall dMenu_save_c::memCardErrMsgWaitKey(dMenu_save_c *this)

{
  if (*(char *)(*(int *)(this + 0x524) + 0x2f5) != '\x02') {
    return;
  }
  this[0x52c] = (dMenu_save_c)0x2;
  return;
}


/* __thiscall dMenu_save_c::memCardErrMsgWaitKey2(void) */

void __thiscall dMenu_save_c::memCardErrMsgWaitKey2(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if ((byte)this[0x533] == 0xff) {
      dFile_error_c::setErrMessage(this_00,99,0);
      this[0x52c] = this[0x52e];
    }
    else {
      dFile_error_c::setErrMessage(this_00,(uint)(byte)this[0x533],0);
      this[0x533] = (dMenu_save_c)0xff;
      this[0x52c] = (dMenu_save_c)0x5;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrMsgWaitKey3(void) */

void __thiscall dMenu_save_c::memCardErrMsgWaitKey3(dMenu_save_c *this)

{
  if ((*(dFile_error_c **)(this + 0x524))[0x2f5] == (dFile_error_c)0x2) {
    if ((byte)this[0x533] != 0xff) {
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x524),(uint)(byte)this[0x533],0);
      this[0x533] = (dMenu_save_c)0xff;
    }
    this[0x52c] = this[0x52d];
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrGoIPLSel(void) */

void __thiscall dMenu_save_c::memCardErrGoIPLSel(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      this[0x52c] = (dMenu_save_c)0x2;
    }
    else {
      dFile_error_c::setErrMessage(this_00,100,0);
      this[0x52c] = (dMenu_save_c)0x8;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrGoIPLSel2(void) */

void __thiscall dMenu_save_c::memCardErrGoIPLSel2(dMenu_save_c *this)

{
  if (*(char *)(*(int *)(this + 0x524) + 0x2f5) == '\x02') {
    if (*(char *)(*(int *)(this + 0x524) + 0x2f6) == '\x01') {
      this[0x52c] = (dMenu_save_c)0x2;
    }
    else {
      os::OSResetSystem(1,1,1);
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrMsgWaitFormatSel(void) */

void __thiscall dMenu_save_c::memCardErrMsgWaitFormatSel(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x2f,0);
      this[0x52c] = (dMenu_save_c)0x4;
    }
    else {
      dFile_error_c::setErrMessage(this_00,0x30,0);
      this[0x52c] = (dMenu_save_c)0xa;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardErrMsgWaitFormatSel2(void) */

void __thiscall dMenu_save_c::memCardErrMsgWaitFormatSel2(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x2f,0);
      this[0x52c] = (dMenu_save_c)0x4;
    }
    else {
      mDoMemCd_Ctrl_c::command_format(&m_Do_MemCard::g_mDoMemCd_control);
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x524),0x31,1);
      this[0x52c] = (dMenu_save_c)0xb;
      this[0x53b] = (dMenu_save_c)0x1;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardFormat(void) */

void __thiscall dMenu_save_c::memCardFormat(dMenu_save_c *this)

{
  undefined4 uVar1;
  
  uVar1 = mDoMemCd_Ctrl_c::FormatSync(&m_Do_MemCard::g_mDoMemCd_control);
  *(undefined4 *)(this + 0x540) = uVar1;
  if (*(int *)(this + 0x540) != 0) {
    dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x524));
    this[0x52c] = (dMenu_save_c)0xc;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardFormatCheck(void) */

void __thiscall dMenu_save_c::memCardFormatCheck(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (*(int *)(this + 0x540) == 2) {
      dFile_error_c::setErrMessage(this_00,0x33,0);
      this[0x52c] = (dMenu_save_c)0x6;
      this[0x52d] = (dMenu_save_c)0x1;
    }
    else {
      if (*(int *)(this + 0x540) == 1) {
        dFile_error_c::setErrMessage(this_00,0x32,0);
        *(undefined *)(*(int *)(this + 0x524) + 0x2fc) = 1;
        this[0x52c] = (dMenu_save_c)0x6;
        this[0x52d] = (dMenu_save_c)0x1;
      }
    }
    this[0x53b] = (dMenu_save_c)0x0;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardMakeGameFileSel(void) */

void __thiscall dMenu_save_c::memCardMakeGameFileSel(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x35,0);
      this[0x52c] = (dMenu_save_c)0x4;
    }
    else {
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x554),0);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x554,0);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x554),1);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x554,1);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x554),2);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x554,2);
      mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,this + 0x554,0x1650,0);
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x524),0x36,1);
      this[0x52c] = (dMenu_save_c)0xe;
      this[0x53b] = (dMenu_save_c)0x1;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardMakeGameFile(void) */

void __thiscall dMenu_save_c::memCardMakeGameFile(dMenu_save_c *this)

{
  undefined4 uVar1;
  
  uVar1 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  *(undefined4 *)(this + 0x540) = uVar1;
  if (*(int *)(this + 0x540) != 0) {
    dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x524));
    this[0x52c] = (dMenu_save_c)0xf;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardMakeGameFileCheck(void) */

void __thiscall dMenu_save_c::memCardMakeGameFileCheck(dMenu_save_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x524);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (*(int *)(this + 0x540) == 2) {
      dFile_error_c::setErrMessage(this_00,0x37,0);
      this[0x52c] = (dMenu_save_c)0x6;
      this[0x52d] = (dMenu_save_c)0x1;
    }
    else {
      if (*(int *)(this + 0x540) == 1) {
        d_com_inf_game::g_dComIfG_gameInfo._4753_1_ = 1;
        dFile_error_c::setErrMessage(this_00,0x38,0);
        this[0x52c] = (dMenu_save_c)0x4;
      }
    }
    this[0x53b] = (dMenu_save_c)0x0;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataLoadWait(void) */

void __thiscall dMenu_save_c::memCardDataLoadWait(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = mDoMemCd_Ctrl_c::LoadSync(&m_Do_MemCard::g_mDoMemCd_control,this + 0x554,0x1650,0);
  if (iVar1 != 0) {
    if (iVar1 == 2) {
      this[0x52c] = (dMenu_save_c)0x1;
    }
    else {
      if (iVar1 == 1) {
        if (this[0x53a] == (dMenu_save_c)0x1) {
          this[0x52c] = (dMenu_save_c)0x2;
        }
        else {
          if (this[0x537] == (dMenu_save_c)0x3) {
            this[0x52c] = (dMenu_save_c)0x24;
          }
          else {
            this[0x52c] = (dMenu_save_c)0x11;
          }
        }
      }
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataLoadWait2(void) */

void __thiscall dMenu_save_c::memCardDataLoadWait2(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = menuDown(this);
  iVar2 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x1;
    this[0x52c] = (dMenu_save_c)0x12;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataSave(void) */

void __thiscall dMenu_save_c::memCardDataSave(dMenu_save_c *this)

{
  bool bVar1;
  int iVar2;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._4753_1_ == '\x01') {
    bVar1 = true;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo._4754_1_ == '\0') {
      if ((d_com_inf_game::g_dComIfG_gameInfo._4764_4_ ^ DAT_803b502c |
          d_com_inf_game::g_dComIfG_gameInfo._4760_4_ ^ DAT_CardSerialNo) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
  }
  if (bVar1) {
    d_com_inf_game::dComIfGs_exchangePlayerRecollectionData();
    iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
    dSv_info_c::putSave(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                        (uint)(*(byte *)(iVar2 + 9) >> 1));
    d_com_inf_game::dComIfGs_setGameStartStage();
    iVar2 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData
                      ((card_savedata *)
                       (this + (uint)d_com_inf_game::g_dComIfG_gameInfo._4752_1_ * 0x770 + 0x554));
    if (iVar2 == 0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8be,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
                 d_menu_save::_4159,d_menu_save::_4159,0);
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3b);
      this[0x52c] = (dMenu_save_c)0x13;
    }
    else {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3c);
      dataWrite(this);
      this[0x52c] = (dMenu_save_c)0x16;
    }
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8be,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3a);
    this[0x52c] = (dMenu_save_c)0x1b;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataSaveUpMenu(void) */

void __thiscall dMenu_save_c::memCardDataSaveUpMenu(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = menuUp(this);
  iVar2 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x0;
    CursorAlphaInit(this);
    this[0x52f] = (dMenu_save_c)0x1;
    CursorMove(this);
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    this[0x52c] = (dMenu_save_c)0x14;
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataSaveSel(void) */

void __thiscall dMenu_save_c::memCardDataSaveSel(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = YesNoSelect(this,0);
  if (iVar1 != 0) {
    if (this[0x52f] == (dMenu_save_c)0x0) {
      this[0x52c] = (dMenu_save_c)0x15;
    }
    else {
      CursorAlphaInit(this);
      this[0x52f] = (dMenu_save_c)0x0;
      CursorMove(this);
      *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x39);
      this[0x52c] = (dMenu_save_c)0x17;
      this[0x52d] = (dMenu_save_c)0x0;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::memCardDataSaveDownMenu(void) */

void __thiscall dMenu_save_c::memCardDataSaveDownMenu(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = menuDown(this);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (iVar1 == 1) {
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x1;
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3c);
    dataWrite(this);
    this[0x52c] = (dMenu_save_c)0x16;
  }
  return;
}


/* __thiscall dMenu_save_c::dataWrite(void) */

void __thiscall dMenu_save_c::dataWrite(dMenu_save_c *this)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  iVar1 = dSv_info_c::memory_to_card
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x554),
                     (uint)d_com_inf_game::g_dComIfG_gameInfo._4752_1_);
  if (iVar1 == -1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_save.cpp",0x700,"res != -1");
    m_Do_printf::OSPanic("d_menu_save.cpp",0x700,&DAT_8036072a);
  }
  m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData
            (this + 0x554,d_com_inf_game::g_dComIfG_gameInfo._4752_1_);
  mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,this + 0x554,0x1650,0);
  uVar3 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  *(undefined4 *)(this + 0x540) = uVar3;
  return;
}


/* __thiscall dMenu_save_c::memCardDataSaveWait(void) */

void __thiscall dMenu_save_c::memCardDataSaveWait(dMenu_save_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (*(int *)(this + 0x540) == 0) {
    uVar2 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
    *(undefined4 *)(this + 0x540) = uVar2;
  }
  if ((*(int *)(this + 0x540) != 0) && (iVar1 == 1)) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x534] = DAT_803e631c;
    if (*(int *)(this + 0x540) == 1) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8bd,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
                 d_menu_save::_4159,d_menu_save::_4159,0);
      d_com_inf_game::dComIfGs_exchangePlayerRecollectionData();
      d_com_inf_game::g_dComIfG_gameInfo._4764_4_ = DAT_803b502c;
      d_com_inf_game::g_dComIfG_gameInfo._4760_4_ = DAT_CardSerialNo;
      d_com_inf_game::g_dComIfG_gameInfo._4753_1_ = 0;
      d_com_inf_game::g_dComIfG_gameInfo._4754_1_ = 0;
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3e);
      this[0x52c] = (dMenu_save_c)0x17;
      this[0x52d] = (dMenu_save_c)0x19;
    }
    else {
      if (*(int *)(this + 0x540) == 2) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8be,(cXyz *)0x0,0,0,d_menu_save::_4158,
                   d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        f_op_msg_mng::fopMsgM_messageGet
                  (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3d);
        this[0x52c] = (dMenu_save_c)0x18;
        this[0x52d] = (dMenu_save_c)0x1;
      }
    }
  }
  return;
}


/* __thiscall dMenu_save_c::msgWait(void) */

void __thiscall dMenu_save_c::msgWait(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (iVar1 == 1) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x52c] = this[0x52d];
  }
  return;
}


/* __thiscall dMenu_save_c::msgWait2(void) */

void __thiscall dMenu_save_c::msgWait2(dMenu_save_c *this)

{
  int iVar1;
  
  if (this[0x534] != (dMenu_save_c)0x0) {
    this[0x534] = (dMenu_save_c)((char)this[0x534] + -1);
  }
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  if (iVar1 == 1) {
    if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
           (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
          ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
         (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
          ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
        (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
         (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
          ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) &&
       (this[0x534] != (dMenu_save_c)0x0)) {
      return;
    }
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x52c] = this[0x52d];
  }
  else {
    *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  }
  return;
}


/* __thiscall dMenu_save_c::saveEndWait(void) */

void __thiscall dMenu_save_c::saveEndWait(dMenu_save_c *this)

{
  if (this[0x534] != (dMenu_save_c)0x0) {
    this[0x534] = (dMenu_save_c)((char)this[0x534] + -1);
  }
  if (((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
      (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) &&
     (this[0x534] != (dMenu_save_c)0x0)) {
    return;
  }
  *(undefined2 *)(this + 0x544) = 0;
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x40)
  ;
  this[0x52c] = (dMenu_save_c)0x1d;
  return;
}


/* __thiscall dMenu_save_c::canNotSave(void) */

void __thiscall dMenu_save_c::canNotSave(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  if (iVar1 == 0) {
    *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  }
  if (iVar1 == 1) {
    if ((((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
          (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)) &&
        (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 &&
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) == 0)))) &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0 &&
        (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0 &&
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)))))) {
      return;
    }
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    if (this[0x537] == (dMenu_save_c)0x3) {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x4c);
    }
    else {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x39);
    }
    this[0x52c] = (dMenu_save_c)0x1c;
  }
  return;
}


/* __thiscall dMenu_save_c::canNotSave2(void) */

void __thiscall dMenu_save_c::canNotSave2(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = menuUp(this);
  }
  iVar2 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x0;
    CursorAlphaInit(this);
    this[0x52f] = (dMenu_save_c)0x0;
    CursorMove(this);
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    this[0x52c] = (dMenu_save_c)0x0;
  }
  return;
}


/* __thiscall dMenu_save_c::gameContinue(void) */

void __thiscall dMenu_save_c::gameContinue(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar2 = 1;
  }
  else {
    iVar2 = menuUp(this);
  }
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x0;
    CursorAlphaInit(this);
    this[0x52f] = (dMenu_save_c)0x0;
    CursorMove(this);
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    this[0x52c] = (dMenu_save_c)0x1e;
  }
  return;
}


/* __thiscall dMenu_save_c::gameContinue2(void) */

void __thiscall dMenu_save_c::gameContinue2(dMenu_save_c *this)

{
  int iVar1;
  
  if ((this[0x537] == (dMenu_save_c)0x2) || (this[0x537] == (dMenu_save_c)0x3)) {
    iVar1 = YesNoSelect2(this,1);
  }
  else {
    iVar1 = YesNoSelect(this,2);
  }
  if (iVar1 != 0) {
    if (this[0x52f] == (dMenu_save_c)0x0) {
      if (this[0x537] == (dMenu_save_c)0x2) {
        this[0x538] = (dMenu_save_c)0x1;
      }
      this[0x52c] = (dMenu_save_c)0x1a;
      this[0x531] = (dMenu_save_c)0x3;
    }
    else {
      if (this[0x537] == (dMenu_save_c)0x2) {
        this[0x534] = (dMenu_save_c)0xf;
        this[0x52c] = (dMenu_save_c)0x20;
      }
      else {
        if (this[0x52f] == (dMenu_save_c)0x2) {
          this[0x52c] = (dMenu_save_c)0x1a;
          this[0x531] = (dMenu_save_c)0x3;
        }
        else {
          *(undefined2 *)(this + 0x544) = 0;
          this[0x534] = (dMenu_save_c)0x1e;
          this[0x52c] = (dMenu_save_c)0x1f;
        }
      }
    }
  }
  return;
}


/* __thiscall dMenu_save_c::gameContinue3(void) */

void __thiscall dMenu_save_c::gameContinue3(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = PaneScaleAlphaWipe(this,*(short *)(this + 0x544),DAT_803e6317,d_menu_save::_4158,'\0',1);
  iVar2 = closeForGameover_2(this);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((iVar1 == 1) && (iVar2 == 1)) {
    if (this[0x534] == (dMenu_save_c)0x0) {
      *mDoRst::mResetData = 1;
    }
    else {
      this[0x534] = (dMenu_save_c)((char)this[0x534] + -1);
    }
  }
  return;
}


/* __thiscall dMenu_save_c::gameContinue4(void) */

void __thiscall dMenu_save_c::gameContinue4(dMenu_save_c *this)

{
  if (this[0x534] != (dMenu_save_c)0x0) {
    this[0x534] = (dMenu_save_c)((char)this[0x534] + -1);
    return;
  }
  this[0x52c] = (dMenu_save_c)0x1a;
  this[0x531] = (dMenu_save_c)0x3;
  this[0x538] = (dMenu_save_c)0x0;
  return;
}


/* __thiscall dMenu_save_c::endingNoSave(void) */

void __thiscall dMenu_save_c::endingNoSave(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (iVar1 == 1) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x0;
    CursorAlphaInit(this);
    this[0x52f] = (dMenu_save_c)0x1;
    CursorMove(this);
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    this[0x52c] = (dMenu_save_c)0x22;
  }
  return;
}


/* __thiscall dMenu_save_c::endingNoSave2(void) */

void __thiscall dMenu_save_c::endingNoSave2(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = YesNoSelect2(this,1);
  if (iVar1 != 0) {
    if (this[0x52f] == (dMenu_save_c)0x0) {
      this[0x538] = (dMenu_save_c)0x0;
      this[0x52c] = (dMenu_save_c)0x1a;
      this[0x531] = (dMenu_save_c)0x3;
    }
    else {
      f_op_msg_mng::fopMsgM_messageGet
                (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x4c);
      this[0x52c] = (dMenu_save_c)0x23;
    }
  }
  return;
}


/* __thiscall dMenu_save_c::endingNoSave3(void) */

void __thiscall dMenu_save_c::endingNoSave3(dMenu_save_c *this)

{
  int iVar1;
  
  iVar1 = PaneAlphaMsgTxt(this,*(short *)(this + 0x544),DAT_803e631d);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if (iVar1 == 1) {
    this[0x536] = (dMenu_save_c)((byte)this[0x536] ^ 1);
    *(undefined2 *)(this + 0x544) = 0;
    this[0x535] = (dMenu_save_c)0x0;
    CursorAlphaInit(this);
    this[0x52f] = (dMenu_save_c)0x0;
    CursorMove(this);
    *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 1;
    this[0x52c] = (dMenu_save_c)0x0;
  }
  return;
}


/* __thiscall dMenu_save_c::endingDataCheck(void) */

void __thiscall dMenu_save_c::endingDataCheck(dMenu_save_c *this)

{
  bool bVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._4753_1_ == '\x01') {
    bVar1 = true;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo._4754_1_ == '\0') {
      if ((d_com_inf_game::g_dComIfG_gameInfo._4764_4_ ^ DAT_803b502c |
          d_com_inf_game::g_dComIfG_gameInfo._4760_4_ ^ DAT_CardSerialNo) == 0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
  }
  if (bVar1) {
    this[0x52c] = (dMenu_save_c)0x1a;
    this[0x531] = (dMenu_save_c)0x3;
  }
  else {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8be,(cXyz *)0x0,0,0,d_menu_save::_4158,d_menu_save::_4158,
               d_menu_save::_4159,d_menu_save::_4159,0);
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3a);
    this[0x52c] = (dMenu_save_c)0x1b;
  }
  return;
}


/* __thiscall dMenu_save_c::saveWait(void) */

void __thiscall dMenu_save_c::saveWait(dMenu_save_c *this)

{
  return;
}


/* __thiscall dMenu_save_c::YesNoSelect(int) */

undefined4 __thiscall dMenu_save_c::YesNoSelect(dMenu_save_c *this,int param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  if (*(char *)(*(int *)(this + 0x394) + 0xaa) == '\0') {
    uVar1 = 1;
  }
  else {
    STControl::checkTrigger(*(STControl **)(this + 0x528));
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
        if (param_1 == 1) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c1,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c0,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 0;
        this[0x52f] = (dMenu_save_c)0x2;
        uVar1 = 1;
      }
      else {
        cVar2 = STControl::checkRightTrigger(*(STControl **)(this + 0x528));
        if (cVar2 == '\0') {
          cVar2 = STControl::checkLeftTrigger(*(STControl **)(this + 0x528));
          if ((cVar2 != '\0') && (this[0x52f] != (dMenu_save_c)0x0)) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_save::_4158,
                       d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
            this[0x52f] = (dMenu_save_c)0x0;
            CursorMove(this);
          }
        }
        else {
          if (this[0x52f] != (dMenu_save_c)0x1) {
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_save::_4158,
                       d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
            this[0x52f] = (dMenu_save_c)0x1;
            CursorMove(this);
          }
        }
        CursorAnime(this);
        uVar1 = 0;
      }
    }
    else {
      *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 0;
      if (this[0x52f] == (dMenu_save_c)0x0) {
        if (param_1 == 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8bb,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c0,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
      }
      else {
        if (param_1 == 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8bc,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c1,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall dMenu_save_c::YesNoSelect2(int) */

undefined4 __thiscall dMenu_save_c::YesNoSelect2(dMenu_save_c *this,int param_1)

{
  undefined4 uVar1;
  char cVar2;
  
  if (*(char *)(*(int *)(this + 0x394) + 0xaa) == '\0') {
    uVar1 = 1;
  }
  else {
    STControl::checkTrigger(*(STControl **)(this + 0x528));
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      cVar2 = STControl::checkRightTrigger(*(STControl **)(this + 0x528));
      if (cVar2 == '\0') {
        cVar2 = STControl::checkLeftTrigger(*(STControl **)(this + 0x528));
        if ((cVar2 != '\0') && (this[0x52f] != (dMenu_save_c)0x0)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
          this[0x52f] = (dMenu_save_c)0x0;
          CursorMove(this);
        }
      }
      else {
        if (this[0x52f] != (dMenu_save_c)0x1) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
          this[0x52f] = (dMenu_save_c)0x1;
          CursorMove(this);
        }
      }
      CursorAnime(this);
      uVar1 = 0;
    }
    else {
      *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 0;
      if (this[0x52f] == (dMenu_save_c)0x0) {
        if (param_1 == 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8bb,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c0,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
      }
      else {
        if (param_1 == 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8bc,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
        else {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8c1,(cXyz *)0x0,0,0,d_menu_save::_4158,
                     d_menu_save::_4158,d_menu_save::_4159,d_menu_save::_4159,0);
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall dMenu_save_c::CursorAlphaInit(void) */

void __thiscall dMenu_save_c::CursorAlphaInit(dMenu_save_c *this)

{
  this[0x3c9] = (dMenu_save_c)0x0;
  *(undefined2 *)(this + 0x3ca) = 0;
  this[0x530] = (dMenu_save_c)0x0;
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x394));
  return;
}


/* __thiscall dMenu_save_c::CursorMove(void) */

void __thiscall dMenu_save_c::CursorMove(dMenu_save_c *this)

{
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x394),
             (double)(d_menu_save::_5166 *
                     (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x52f]) -
                            d_menu_save::_5168)),(double)d_menu_save::_4059);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_save_c::CursorAnime(void) */

void __thiscall dMenu_save_c::CursorAnime(dMenu_save_c *this)

{
  byte bVar1;
  char cVar2;
  double dVar3;
  
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(DAT_803e6314,(int)*(short *)(this + 0x3ca),0);
  bVar1 = DAT_803e6316;
  if (this[0x530] != (dMenu_save_c)0x0) {
    dVar3 = (double)(float)((double)d_menu_save::_4158 - dVar3);
  }
  cVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                    ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      (uint)DAT_803e6315 -
                                                                      (uint)DAT_803e6316 ^
                                                                      0x80000000) -
                                                    d_menu_save::_4162) * dVar3));
  this[0x3c9] = (dMenu_save_c)(bVar1 + cVar2);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x394));
  if (*(short *)(this + 0x3ca) == 0) {
    *(ushort *)(this + 0x3ca) = (ushort)DAT_803e6314;
    this[0x530] = (dMenu_save_c)((byte)this[0x530] ^ 1);
  }
  else {
    *(short *)(this + 0x3ca) = *(short *)(this + 0x3ca) + -1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::openSave(void) */

undefined4 __thiscall dMenu_save_c::openSave(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fd,DAT_803e62fc,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4160,'\x01',0);
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,(*(short *)(this + 0x544) - (ushort)DAT_803e62fd) -
                                (ushort)DAT_803e62fc,DAT_803e62fc,d_menu_save::_4160,
                           d_menu_save::_4059,'\x04',2);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6305,DAT_803e6304,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  iVar3 = menuUp(this);
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar2 == 1)) && (iVar3 == 1)) {
    *(undefined2 *)(this + 0x544) = 0;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::closeSave(void) */

undefined4 __thiscall dMenu_save_c::closeSave(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = PaneTranceBase(this,*(short *)(this + 0x544) - (ushort)DAT_803e62fe,DAT_803e62fc,
                         d_menu_save::_4059,d_menu_save::_4160,'\x04',2);
  if (iVar1 == 1) {
    iVar5 = PaneTranceBase(this,(*(short *)(this + 0x544) - (ushort)DAT_803e62fe) -
                                (ushort)DAT_803e62fc,DAT_803e62fc,d_menu_save::_4059,
                           (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                                  d_menu_save::_4162),'\0',1);
  }
  iVar2 = PaneTranceTitle(this,*(short *)(this + 0x544) - (ushort)DAT_803e6306,DAT_803e6304,
                          d_menu_save::_4059,
                          (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                                 d_menu_save::_4162),'\0',1);
  if (this[0x535] == (dMenu_save_c)0x0) {
    iVar3 = menuDown(this);
  }
  else {
    iVar3 = 1;
  }
  *(short *)(this + 0x544) = *(short *)(this + 0x544) + 1;
  if ((((iVar1 == 1) && (iVar5 == 1)) && (iVar2 == 1)) && (iVar3 == 1)) {
    this[0x535] = (dMenu_save_c)0x0;
    *(undefined2 *)(this + 0x544) = 0;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMenu_save_c::screenSet(void) */

void __thiscall dMenu_save_c::screenSet(dMenu_save_c *this)

{
  J2DScreen *pJVar1;
  char *pcVar2;
  undefined4 uVar3;
  ___ in_r5;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_118 [255];
  undefined local_19;
  
  iVar4 = 0x77703030;
  iVar5 = 0;
  iVar6 = 0;
  do {
    pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),iVar4);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x14),pJVar1);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 8);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6d736b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1d4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63633031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x20c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63633132);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x244),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63633233);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x27c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x73743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2b4),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x73743031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2ec),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x2b4),*(JUTFont **)(this + 0x10));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x2ec),*(JUTFont **)(this + 0x10));
  pcVar2 = local_118;
  iVar4 = 0x100;
  do {
    *pcVar2 = 'A';
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_19 = 0;
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x2b4),local_118,in_r5);
  J2DTextBox::setString(*(J2DTextBox **)(this + 0x2ec),local_118,in_r5);
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x2b4));
  *(undefined4 *)(this + 0x51c) = uVar3;
  **(undefined **)(this + 0x51c) = 0;
  uVar3 = J2DTextBox::getStringPtr(*(J2DTextBox **)(this + 0x2ec));
  *(undefined4 *)(this + 0x520) = uVar3;
  **(undefined **)(this + 0x520) = 0;
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x746b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x324),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x746c3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x35c),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x63757231);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x394),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x79736b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3cc),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x79733030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x404),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x796573)
  ;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x43c),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x43c),*(JUTFont **)(this + 0x10));
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6e6f6b30);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x474),pJVar1);
  pJVar1 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6e6f3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4ac),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6e6f);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4e4),pJVar1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x4e4),*(JUTFont **)(this + 0x10));
  return;
}


/* __thiscall dMenu_save_c::paneTransInit(void) */

void __thiscall dMenu_save_c::paneTransInit(dMenu_save_c *this)

{
  *(undefined2 *)(this + 0x544) = 0;
  PaneScaleAlphaWipe(this,*(short *)(this + 0x544),DAT_803e6317,
                     (float)((double)CONCAT44(0x43300000,(int)DAT_803e631a ^ 0x80000000) -
                            d_menu_save::_4162),'\x01',0);
  PaneAlphaMask(this,*(short *)(this + 0x544),DAT_803e62f9,'\x01',0);
  PaneTranceBase(this,*(short *)(this + 0x544),DAT_803e62fc,
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6300 ^ 0x80000000) -
                        d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  PaneTranceTitle(this,*(short *)(this + 0x544),DAT_803e6304,
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6308 ^ 0x80000000) -
                         d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  PaneTranceMenu(this,*(short *)(this + 0x544),DAT_803e630c,(fopMsgM_pane_class *)(this + 0x3cc),
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                        d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  PaneTranceMenu(this,*(short *)(this + 0x544),DAT_803e630c,(fopMsgM_pane_class *)(this + 0x474),
                 (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                        d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  *(undefined *)(*(int *)(this + 0x394) + 0xaa) = 0;
  return;
}


/* __thiscall dMenu_save_c::displayInit(void) */

void __thiscall dMenu_save_c::displayInit(dMenu_save_c *this)

{
  this[0x536] = (dMenu_save_c)0x0;
  this[0x53c] = (dMenu_save_c)0x0;
  this[0x53d] = (dMenu_save_c)0x0;
  this[0x53b] = (dMenu_save_c)0x0;
  this[0x52c] = (dMenu_save_c)0x1a;
  this[0x531] = (dMenu_save_c)0x1;
  this[0x53a] = (dMenu_save_c)0x1;
  this[0x538] = (dMenu_save_c)0x2;
  this[0x535] = (dMenu_save_c)0x0;
  CursorAlphaInit(this);
  this[0x52f] = (dMenu_save_c)0x0;
  CursorMove(this);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2b4),d_menu_save::_4158);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x2ec),d_menu_save::_4059);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2b4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2ec));
  this[0x539] = (dMenu_save_c)0x1;
  if (this[0x537] == (dMenu_save_c)0x3) {
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + (uint)(byte)this[0x536] * 4 + 0x51c),0x4c);
  }
  else {
    f_op_msg_mng::fopMsgM_messageGet
              (*(undefined4 *)(this + (uint)(byte)this[0x536] * 4 + 0x51c),0x39);
  }
  **(undefined **)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c) = 0;
  return;
}


/* __thiscall dMenu_save_c::initializeEx(void) */

void __thiscall dMenu_save_c::initializeEx(dMenu_save_c *this)

{
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + (uint)(byte)this[0x536] * 4 + 0x51c),0x3a)
  ;
  f_op_msg_mng::fopMsgM_messageGet(*(undefined4 *)(this + ((byte)this[0x536] ^ 1) * 4 + 0x51c),0x3a)
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_save_c::menuUp(void) */

undefined4 __thiscall dMenu_save_c::menuUp(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = PaneTranceMenu(this,*(short *)(this + 0x544),DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x3cc),
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  iVar2 = PaneTranceMenu(this,*(short *)(this + 0x544) - (ushort)DAT_803e6310,DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x474),
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                d_menu_save::_4162),d_menu_save::_4059,'\x01',0);
  if ((iVar1 == 1) && (iVar2 == 1)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMenu_save_c::menuDown(void) */

undefined4 __thiscall dMenu_save_c::menuDown(dMenu_save_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = PaneTranceMenu(this,*(short *)(this + 0x544),DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x3cc),d_menu_save::_4059,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                d_menu_save::_4162),'\0',1);
  iVar2 = PaneTranceMenu(this,*(short *)(this + 0x544) - (ushort)DAT_803e6310,DAT_803e630c,
                         (fopMsgM_pane_class *)(this + 0x474),d_menu_save::_4059,
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6312 ^ 0x80000000) -
                                d_menu_save::_4162),'\0',1);
  if ((iVar1 == 1) && (iVar2 == 1)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Removing unreachable block (ram,0x801da694) */
/* __thiscall dMenu_save_c::PaneAlphaMsgTxt(short,
                                            unsigned char) */

undefined4 __thiscall dMenu_save_c::PaneAlphaMsgTxt(dMenu_save_c *this,short param_1,uchar param_2)

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
                ((fopMsgM_pane_class *)(this + ((byte)this[0x536] + 3) * 0x38 + 0x20c),
                 (float)((double)d_menu_save::_4158 - dVar3));
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(this + (((byte)this[0x536] ^ 1) + 3) * 0x38 + 0x20c),
                 (float)dVar3);
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2b4));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x2ec));
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801da790) */
/* WARNING: Removing unreachable block (ram,0x801da788) */
/* WARNING: Removing unreachable block (ram,0x801da798) */
/* __thiscall dMenu_save_c::PaneTranceBase(short,
                                           unsigned char,
                                           float,
                                           float,
                                           unsigned char,
                                           int) */

undefined4 __thiscall
dMenu_save_c::PaneTranceBase
          (dMenu_save_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
          int param_6)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_4;
  dVar5 = (double)param_3;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x20c),(double)d_menu_save::_4059,
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar7 - dVar5))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar6 = (double)(float)((double)d_menu_save::_4158 - dVar6);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x20c),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x20c));
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
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801daa58) */
/* WARNING: Removing unreachable block (ram,0x801daa60) */
/* __thiscall dMenu_save_c::PaneScaleAlphaWipe(short,
                                               unsigned char,
                                               float,
                                               unsigned char,
                                               int) */

undefined4 __thiscall
dMenu_save_c::PaneScaleAlphaWipe
          (dMenu_save_c *this,short param_1,uchar param_2,float param_3,uchar param_4,int param_5)

{
  undefined4 uVar1;
  dMenu_save_c *pdVar2;
  undefined3 in_register_00000018;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_3;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_4));
      dVar7 = (double)d_menu_save::_4158;
      if (d_menu_save::_4059 <= (float)(dVar8 - dVar7)) {
        iVar3 = 0;
        iVar4 = 0;
        dVar8 = (double)(float)(dVar7 + (double)((float)(dVar7 - dVar6) * (float)(dVar8 - dVar7)));
        do {
          pdVar2 = this + iVar4;
          *(float *)(pdVar2 + 0x40) = (float)((double)*(float *)(pdVar2 + 0x38) * dVar8);
          *(float *)(pdVar2 + 0x44) = (float)((double)*(float *)(pdVar2 + 0x3c) * dVar8);
          (**(code **)(**(int **)(pdVar2 + 0x14) + 0x18))
                    ((double)*(float *)(pdVar2 + 0x40),(double)*(float *)(pdVar2 + 0x44));
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar3 < 8);
        *(float *)(this + 0x20) =
             *(float *)(this + 0x18) - (*(float *)(this + 0x40) - *(float *)(this + 0x38));
        (**(code **)(**(int **)(this + 0x14) + 0x10))
                  ((double)*(float *)(this + 0x20),(double)*(float *)(this + 0x1c));
        *(float *)(this + 0x94) =
             *(float *)(this + 0x8c) - (*(float *)(this + 0xb4) - *(float *)(this + 0xac));
        (**(code **)(**(int **)(this + 0x84) + 0x10))
                  ((double)*(float *)(this + 0x88),(double)*(float *)(this + 0x94));
        *(float *)(this + 0x5c) =
             *(float *)(this + 0x54) - (*(float *)(this + 0x7c) - *(float *)(this + 0x74));
        *(undefined4 *)(this + 0x58) = *(undefined4 *)(this + 0xb0);
        (**(code **)(**(int **)(this + 0x4c) + 0x10))
                  ((double)*(float *)(this + 0x58),(double)*(float *)(this + 0x5c));
        *(undefined4 *)(this + 200) = *(undefined4 *)(this + 0x40);
        (**(code **)(**(int **)(this + 0xbc) + 0x10))
                  ((double)*(float *)(this + 200),(double)*(float *)(this + 0xc4));
        (**(code **)(**(int **)(this + 0xf4) + 0x10))
                  ((double)(*(float *)(this + 0xb0) + *(float *)(this + 0x78)),
                   -(double)*(float *)(this + 0x7c));
        (**(code **)(**(int **)(this + 300) + 0x10))
                  (-(double)*(float *)(this + 0x158),-(double)*(float *)(this + 0xb4));
        (**(code **)(**(int **)(this + 0x164) + 0x10))
                  (-(double)(*(float *)(this + 0x40) + *(float *)(this + 0x158)),
                   -(double)(*(float *)(this + 0xb4) + *(float *)(this + 0x194)));
        (**(code **)(**(int **)(this + 0x19c) + 0x10))
                  (-(double)(*(float *)(this + 0x40) + *(float *)(this + 0x158)),
                   (double)(*(float *)(this + 0x44) + *(float *)(this + 0x1cc)));
      }
      if (param_5 != 2) {
        if (param_5 == 1) {
          dVar6 = (double)(float)((double)d_menu_save::_4158 - dVar6);
        }
        iVar3 = 0;
        iVar4 = 0;
        do {
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)(this + iVar4 + 0x14),(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x14));
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar3 < 8);
      }
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return uVar1;
}


/* __thiscall dMenu_save_c::PaneAlphaMask(short,
                                          unsigned char,
                                          unsigned char,
                                          int) */

undefined4 __thiscall
dMenu_save_c::PaneAlphaMask
          (dMenu_save_c *this,short param_1,uchar param_2,uchar param_3,int param_4)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  double dVar2;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_3));
      if (param_4 != 2) {
        if (param_4 == 1) {
          dVar2 = (double)(float)((double)d_menu_save::_4158 - dVar2);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1d4),(float)dVar2);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1d4));
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x801dabe4) */
/* WARNING: Removing unreachable block (ram,0x801dabdc) */
/* WARNING: Removing unreachable block (ram,0x801dabec) */
/* __thiscall dMenu_save_c::PaneTranceTitle(short,
                                            unsigned char,
                                            float,
                                            float,
                                            unsigned char,
                                            int) */

undefined4 __thiscall
dMenu_save_c::PaneTranceTitle
          (dMenu_save_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5,
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
                ((fopMsgM_pane_class *)(this + 0x324),(double)d_menu_save::_4059,
                 (double)(float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar5 - dVar3))));
      if (param_6 != 2) {
        if (param_6 == 1) {
          dVar4 = (double)(float)((double)d_menu_save::_4158 - dVar4);
        }
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x324),(float)dVar4);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x35c),(float)dVar4);
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x324));
        f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x35c));
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


/* WARNING: Removing unreachable block (ram,0x801dacac) */
/* WARNING: Removing unreachable block (ram,0x801daca4) */
/* WARNING: Removing unreachable block (ram,0x801dacb4) */
/* __thiscall dMenu_save_c::PaneRotate(short,
                                       unsigned char,
                                       fopMsgM_pane_class *,
                                       float,
                                       float,
                                       float,
                                       unsigned char) */

undefined4 __thiscall
dMenu_save_c::PaneRotate
          (dMenu_save_c *this,short param_1,uchar param_2,fopMsgM_pane_class *param_3,float param_4,
          float param_5,float param_6,uchar param_7)

{
  undefined4 uVar1;
  J2DScreen *pJVar2;
  undefined3 in_register_0000001c;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_6;
  dVar6 = (double)param_5;
  dVar4 = (double)param_4;
  uVar3 = 0;
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
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_0000001c,param_7));
      pJVar2 = param_3->mpPane;
      (pJVar2->parent).mBasePosition.x = (float)dVar4;
      (pJVar2->parent).mBasePosition.y = (float)dVar6;
      (pJVar2->parent).mRotationAxis = 'z';
      (pJVar2->parent).mRotation = (float)(dVar7 * dVar5);
      (*(code *)((pJVar2->parent).vtbl)->calcMtx)();
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801dadac) */
/* WARNING: Removing unreachable block (ram,0x801dada4) */
/* WARNING: Removing unreachable block (ram,0x801dadb4) */
/* __thiscall dMenu_save_c::PaneTranceMenu(short,
                                           unsigned char,
                                           fopMsgM_pane_class *,
                                           float,
                                           float,
                                           unsigned char,
                                           int) */

undefined4 __thiscall
dMenu_save_c::PaneTranceMenu
          (dMenu_save_c *this,short param_1,uchar param_2,fopMsgM_pane_class *param_3,float param_4,
          float param_5,uchar param_6,int param_7)

{
  undefined4 uVar1;
  undefined3 in_register_0000001c;
  int iVar2;
  fopMsgM_pane_class *this_00;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_5;
  dVar5 = (double)param_4;
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
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_0000001c,param_6));
      f_op_msg_mng::fopMsgM_paneTrans
                (param_3,(double)d_menu_save::_4059,
                 (double)(float)(dVar5 + (double)(float)(dVar6 * (double)(float)(dVar7 - dVar5))));
      if (param_7 != 2) {
        if (param_7 == 1) {
          dVar6 = (double)(float)((double)d_menu_save::_4158 - dVar6);
        }
        iVar2 = 0;
        iVar3 = 0;
        do {
          this_00 = (fopMsgM_pane_class *)((int)&param_3->mpPane + iVar3);
          f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar6);
          f_op_msg_mng::fopMsgM_setAlpha(this_00);
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
  return uVar1;
}


/* __thiscall dMenu_save_c::_draw(void) */

void __thiscall dMenu_save_c::_draw(dMenu_save_c *this)

{
  J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_menu_save::_4059,d_menu_save::_4059,
                  &(d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent);
  dFile_error_c::draw2(*(dFile_error_c **)(this + 0x524));
  return;
}


/* __thiscall dMenu_save_c::_draw2(void) */

void __thiscall dMenu_save_c::_draw2(dMenu_save_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 8));
  dFile_error_c::_draw(*(dFile_error_c **)(this + 0x524));
  return;
}


/* __thiscall dDlst_MenuSave_c::draw(void) */

void __thiscall dDlst_MenuSave_c::draw(dDlst_MenuSave_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_menu_save::_4059,d_menu_save::_4059,&pCtx->parent);
  return;
}


/* __thiscall dFile_error_c::~dFile_error_c(void) */

void __thiscall dFile_error_c::_dFile_error_c(dFile_error_c *this)

{
  short in_r4;
  
  if (this != (dFile_error_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dFile_error_c *)&DAT_fffffff8) {
      *(undefined1 **)(this + 8) = &dDlst_FileErr_c::__vt;
      if (this != (dFile_error_c *)&DAT_fffffff8) {
        *(undefined ***)(this + 8) = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMs_HIO_c::~dMs_HIO_c(void) */

void __thiscall dMs_HIO_c::_dMs_HIO_c(dMs_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMs_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_save {

void __sinit_d_menu_save_cpp(void)

{
  ::dMs_HIO_c::dMs_HIO_c((dMs_HIO_c *)&g_msHIO);
  Runtime.PPCEABI.H::__register_global_object();
  MenuSaveProc = _4450;
  DAT_80392c08 = DAT_80392a34;
  DAT_80392c0c = PTR_saveQuestion_80392a38;
  DAT_80392c10 = _4451;
  DAT_80392c14 = DAT_80392a40;
  DAT_80392c18 = PTR_memCardCheck_80392a44;
  DAT_80392c1c = _4452;
  DAT_80392c20 = DAT_80392a4c;
  DAT_80392c24 = PTR_openSaveMenu_80392a50;
  DAT_80392c28 = _4453;
  DAT_80392c2c = DAT_80392a58;
  DAT_80392c30 = PTR_closeSaveMenu_80392a5c;
  DAT_80392c34 = _4454;
  DAT_80392c38 = DAT_80392a64;
  DAT_80392c3c = PTR_memCardErrMsgWaitKey_80392a68;
  DAT_80392c40 = _4455;
  DAT_80392c44 = DAT_80392a70;
  DAT_80392c48 = PTR_memCardErrMsgWaitKey2_80392a74;
  DAT_80392c4c = _4456;
  DAT_80392c50 = DAT_80392a7c;
  DAT_80392c54 = PTR_memCardErrMsgWaitKey3_80392a80;
  DAT_80392c58 = _4457;
  DAT_80392c5c = DAT_80392a88;
  DAT_80392c60 = PTR_memCardErrGoIPLSel_80392a8c;
  DAT_80392c64 = _4458;
  DAT_80392c68 = DAT_80392a94;
  DAT_80392c6c = PTR_memCardErrGoIPLSel2_80392a98;
  DAT_80392c70 = _4459;
  DAT_80392c74 = DAT_80392aa0;
  DAT_80392c78 = PTR_memCardErrMsgWaitFormatSel_80392aa4;
  DAT_80392c7c = _4460;
  DAT_80392c80 = DAT_80392aac;
  DAT_80392c84 = PTR_memCardErrMsgWaitFormatSel2_80392ab0;
  DAT_80392c88 = _4461;
  DAT_80392c8c = DAT_80392ab8;
  DAT_80392c90 = PTR_memCardFormat_80392abc;
  DAT_80392c94 = _4462;
  DAT_80392c98 = DAT_80392ac4;
  DAT_80392c9c = PTR_memCardFormatCheck_80392ac8;
  DAT_80392ca0 = _4463;
  DAT_80392ca4 = DAT_80392ad0;
  DAT_80392ca8 = PTR_memCardMakeGameFileSel_80392ad4;
  DAT_80392cac = _4464;
  DAT_80392cb0 = DAT_80392adc;
  DAT_80392cb4 = PTR_memCardMakeGameFile_80392ae0;
  DAT_80392cb8 = _4465;
  DAT_80392cbc = DAT_80392ae8;
  DAT_80392cc0 = PTR_memCardMakeGameFileCheck_80392aec;
  DAT_80392cc4 = _4466;
  DAT_80392cc8 = DAT_80392af4;
  DAT_80392ccc = PTR_memCardDataLoadWait_80392af8;
  DAT_80392cd0 = _4467;
  DAT_80392cd4 = DAT_80392b00;
  DAT_80392cd8 = PTR_memCardDataLoadWait2_80392b04;
  DAT_80392cdc = _4468;
  DAT_80392ce0 = DAT_80392b0c;
  DAT_80392ce4 = PTR_memCardDataSave_80392b10;
  DAT_80392ce8 = _4469;
  DAT_80392cec = DAT_80392b18;
  DAT_80392cf0 = PTR_memCardDataSaveUpMenu_80392b1c;
  DAT_80392cf4 = _4470;
  DAT_80392cf8 = DAT_80392b24;
  DAT_80392cfc = PTR_memCardDataSaveSel_80392b28;
  DAT_80392d00 = _4471;
  DAT_80392d04 = DAT_80392b30;
  DAT_80392d08 = PTR_memCardDataSaveDownMenu_80392b34;
  DAT_80392d0c = _4472;
  DAT_80392d10 = DAT_80392b3c;
  DAT_80392d14 = PTR_memCardDataSaveWait_80392b40;
  DAT_80392d18 = _4473;
  DAT_80392d1c = DAT_80392b48;
  DAT_80392d20 = PTR_msgWait_80392b4c;
  DAT_80392d24 = _4474;
  DAT_80392d28 = DAT_80392b54;
  DAT_80392d2c = PTR_msgWait2_80392b58;
  DAT_80392d30 = _4475;
  DAT_80392d34 = DAT_80392b60;
  DAT_80392d38 = PTR_saveEndWait_80392b64;
  DAT_80392d3c = _4476;
  DAT_80392d40 = DAT_80392b6c;
  DAT_80392d44 = PTR_saveWait_80392b70;
  DAT_80392d48 = _4477;
  DAT_80392d4c = DAT_80392b78;
  DAT_80392d50 = PTR_canNotSave_80392b7c;
  DAT_80392d54 = _4478;
  DAT_80392d58 = DAT_80392b84;
  DAT_80392d5c = PTR_canNotSave2_80392b88;
  DAT_80392d60 = _4479;
  DAT_80392d64 = DAT_80392b90;
  DAT_80392d68 = PTR_gameContinue_80392b94;
  DAT_80392d6c = _4480;
  DAT_80392d70 = DAT_80392b9c;
  DAT_80392d74 = PTR_gameContinue2_80392ba0;
  DAT_80392d78 = _4481;
  DAT_80392d7c = DAT_80392ba8;
  DAT_80392d80 = PTR_gameContinue3_80392bac;
  DAT_80392d84 = _4482;
  DAT_80392d88 = DAT_80392bb4;
  DAT_80392d8c = PTR_gameContinue4_80392bb8;
  DAT_80392d90 = _4483;
  DAT_80392d94 = DAT_80392bc0;
  DAT_80392d98 = PTR_endingNoSave_80392bc4;
  DAT_80392d9c = _4484;
  DAT_80392da0 = DAT_80392bcc;
  DAT_80392da4 = PTR_endingNoSave2_80392bd0;
  DAT_80392da8 = _4485;
  DAT_80392dac = DAT_80392bd8;
  DAT_80392db0 = PTR_endingNoSave3_80392bdc;
  DAT_80392db4 = _4486;
  DAT_80392db8 = DAT_80392be4;
  DAT_80392dbc = PTR_endingDataCheck_80392be8;
  DAT_80392dc0 = _4487;
  DAT_80392dc4 = DAT_80392bf0;
  DAT_80392dc8 = PTR_noSave_80392bf4;
  DAT_80392dcc = _4488;
  DAT_80392dd0 = DAT_80392bfc;
  DAT_80392dd4 = PTR_noSave2_80392c00;
  return;
}

