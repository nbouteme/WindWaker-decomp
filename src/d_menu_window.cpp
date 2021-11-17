#include <d_menu_window.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_menu_window.h>
#include <f_op_msg_mng.h>
#include <d_menu_collect.h>
#include <d_menu_fmap.h>
#include <d_name.h>
#include <d_menu_save.h>
#include <d_menu_cloth.h>
#include <JKernel/JKRExpHeap.h>
#include <d_event.h>
#include <d_meter.h>
#include <d_event_manager.h>
#include <d_save.h>
#include <d_drawlist.h>
#include <m_Do_ext.h>
#include <f_op_overlap_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_a_player_main.h>
#include <d_menu_item.h>
#include <d_menu_dmap.h>
#include <m_Do_hostIO.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <gx/GXTexture.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <mtx/mtx44.h>
#include <gx/GXTransform.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMenu_Fmap2_c.h>
#include <dDlst_NameIN_c.h>
#include <dMw_DHIO_c.h>
#include <dName_c.h>
#include <dDlst_MENU_CAPTURE_c.h>
#include <dDlst_MENU_CLOTH_c.h>
#include <dMenu_Fmap_c.h>
#include <dMw_HIO_c.h>
#include <dMenu_FmapSv_c.h>


namespace d_menu_window {
undefined1 dMv_CIO_c;
undefined g_mwHIO;
undefined g_mwDHIO;
undefined4 cloth_c;
undefined4 fonttype;
undefined4 rfonttype;
struct dDlst_MENU_CAPTURE_c * dMs_capture_c;
undefined4 dMs_cloth_c;
undefined4 dMi_c;
undefined4 dMc_c;
undefined4 dMd_c;
undefined4 dMf_c;
undefined4 dNm_c;
undefined4 dMs_c;
undefined1 event_wait_frame;
undefined2 timer$7109;
undefined1 init$7110;
}

/* __thiscall dMw_HIO_c::dMw_HIO_c(void) */

void __thiscall dMw_HIO_c::dMw_HIO_c(dMw_HIO_c *this)

{
  dMw_HIO_c *pdVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 **)this = &__vt;
  *(undefined2 *)(this + 0x12) = 0;
  *(undefined2 *)(this + 6) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 8) = 0;
  this[0x16] = (dMw_HIO_c)0x0;
  this[10] = (dMw_HIO_c)0x0;
  this[0x17] = (dMw_HIO_c)0x0;
  this[0xb] = (dMw_HIO_c)0x0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x1a) = 0;
  *(undefined2 *)(this + 0xe) = 0;
  this[0x1c] = (dMw_HIO_c)0x0;
  this[0x10] = (dMw_HIO_c)0x0;
  this[0x1d] = (dMw_HIO_c)0x0;
  this[0x11] = (dMw_HIO_c)0x0;
  this[0x1f] = (dMw_HIO_c)0x0;
  this[0x1e] = (dMw_HIO_c)0x0;
  iVar2 = 0;
  iVar3 = 0x15;
  do {
    (this + iVar2)[0x38] = (dMw_HIO_c)0xff;
    (this + iVar2)[0x20] = (dMw_HIO_c)0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this[0x9d] = (dMw_HIO_c)0x0;
  this[0x9c] = (dMw_HIO_c)0x0;
  this[0x9b] = (dMw_HIO_c)0x0;
  this[0x82] = (dMw_HIO_c)0x0;
  this[0x81] = (dMw_HIO_c)0x0;
  this[0x80] = (dMw_HIO_c)0x0;
  iVar2 = 0;
  iVar3 = 8;
  do {
    pdVar1 = this + iVar2;
    pdVar1[0x58] = (dMw_HIO_c)0x0;
    pdVar1[0x50] = (dMw_HIO_c)0x0;
    pdVar1[0x68] = (dMw_HIO_c)0x0;
    pdVar1[0x60] = (dMw_HIO_c)0x0;
    pdVar1[0xa6] = (dMw_HIO_c)0x0;
    pdVar1[0x9e] = (dMw_HIO_c)0x0;
    pdVar1[0x8b] = (dMw_HIO_c)0x0;
    pdVar1[0x83] = (dMw_HIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    (this + iVar2)[0x78] = (dMw_HIO_c)0xff;
    (this + iVar2)[0x70] = (dMw_HIO_c)0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 6;
  do {
    (this + iVar2)[0xbc] = (dMw_HIO_c)0x0;
    (this + iVar2)[0xb6] = (dMw_HIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    (this + iVar2)[0xca] = (dMw_HIO_c)0x0;
    (this + iVar2)[0xc2] = (dMw_HIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 3;
  do {
    (this + iVar2)[0xd5] = (dMw_HIO_c)0x0;
    (this + iVar2)[0xd2] = (dMw_HIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    (this + iVar2)[0xe0] = (dMw_HIO_c)0x0;
    (this + iVar2)[0xd8] = (dMw_HIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall dMw_DHIO_c::dMw_DHIO_c(void) */

void __thiscall dMw_DHIO_c::dMw_DHIO_c(dMw_DHIO_c *this)

{
  dMw_DHIO_c *pdVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 **)this = &__vt;
  iVar2 = 0;
  iVar3 = 0x10;
  do {
    pdVar1 = this + iVar2;
    pdVar1[5] = (dMw_DHIO_c)0x0;
    pdVar1[0x15] = (dMw_DHIO_c)0x0;
    pdVar1[0x25] = (dMw_DHIO_c)0x0;
    pdVar1[0x35] = (dMw_DHIO_c)0x0;
    pdVar1[0x45] = (dMw_DHIO_c)0x0;
    pdVar1[0x55] = (dMw_DHIO_c)0x0;
    pdVar1[0x65] = (dMw_DHIO_c)0x0;
    pdVar1[0x75] = (dMw_DHIO_c)0x0;
    pdVar1[0x85] = (dMw_DHIO_c)0x0;
    pdVar1[0x95] = (dMw_DHIO_c)0x0;
    pdVar1[0xa5] = (dMw_DHIO_c)0x0;
    pdVar1[0xb5] = (dMw_DHIO_c)0x0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


namespace d_menu_window {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_item_create(sub_ms_screen_class *) */

void dMs_item_create(int param_1)

{
  undefined **ppuVar1;
  void *pvVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(JKRArchive **)(param_1 + 0x104) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemResArchive;
  iVar10 = 0;
  iVar9 = 0;
  do {
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x20,4);
    iVar11 = param_1 + iVar9;
    *(void **)(iVar11 + 0x10c) = pvVar2;
    if (*(int *)(iVar11 + 0x10c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x790,"i_Ms->name[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x790,&DAT_80360851);
    }
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(iVar11 + 0x10c),"");
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar11 + 0x114) = pvVar2;
    if (*(int *)(iVar11 + 0x114) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x793,"i_Ms->note[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x793,&DAT_80360851);
    }
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(iVar11 + 0x114),"");
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar11 + 0x11c) = pvVar2;
    if (*(int *)(iVar11 + 0x11c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x796,"i_Ms->dummy[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x796,&DAT_80360851);
    }
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(iVar11 + 0x11c),"");
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 4;
  } while (iVar10 < 2);
  *(undefined *)(param_1 + 0x1b2) = 0;
  iVar9 = 0;
  iVar10 = 0;
  do {
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0xc00,0x20);
    *(void **)(param_1 + iVar10 + 0x128) = pvVar2;
    if (*(int *)(param_1 + iVar10 + 0x128) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x79f,"i_Ms->buffer_p[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x79f,&DAT_80360851);
    }
    *(char *)(param_1 + 0x1b2) = *(char *)(param_1 + 0x1b2) + '\x01';
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar9 < 0x21);
  dMi_c = (undefined **)JKernel::operator_new(0x2424);
  if (dMi_c == (undefined **)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x7aa,"dMi_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x7aa,&DAT_80360851);
  }
  else {
    *dMi_c = (undefined *)&dDlst_base_c::__vt;
    *dMi_c = &dMenu_base_c::__vt;
    *dMi_c = &dMenu_Item_c::__vt;
    dMi_c[0x8c8] = (undefined *)0xffffffff;
    dMi_c[0x8c9] = (undefined *)0xffffffff;
    dMi_c[0x8ca] = (undefined *)0xffffffff;
    dMi_c[0x8cb] = (undefined *)0xffffffff;
  }
  iVar9 = 0;
  iVar10 = 0x15;
  do {
    *(undefined4 *)((int)dMi_c + iVar9 + 0x2334) = *(undefined4 *)(param_1 + iVar9 + 0x128);
    iVar9 = iVar9 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar9 = 0;
  iVar10 = 9;
  do {
    *(undefined4 *)((int)dMi_c + iVar9 + 0x2394) = *(undefined4 *)(param_1 + iVar9 + 0x188);
    iVar9 = iVar9 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  dMi_c[0x8c4] = *(undefined **)(param_1 + 0x104);
  ppuVar1 = dMi_c;
  puVar4 = rfonttype;
  dMi_c[0x8c5] = fonttype;
  ppuVar1[0x8c6] = puVar4;
  ppuVar1 = dMi_c;
  puVar8 = *(undefined **)(param_1 + 0x120);
  puVar7 = *(undefined **)(param_1 + 0x11c);
  puVar6 = *(undefined **)(param_1 + 0x118);
  puVar5 = *(undefined **)(param_1 + 0x114);
  puVar4 = *(undefined **)(param_1 + 0x110);
  dMi_c[0x8f8] = *(undefined **)(param_1 + 0x10c);
  ppuVar1[0x8f9] = puVar4;
  ppuVar1[0x8fa] = puVar5;
  ppuVar1[0x8fb] = puVar6;
  ppuVar1[0x8fc] = puVar7;
  ppuVar1[0x8fd] = puVar8;
  *(undefined *)((int)dMi_c + 0x23ff) = d_com_inf_game::g_dComIfG_gameInfo._23523_1_;
  (**(code **)(*dMi_c + 0x10))();
  if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel != 0) {
      dMs_onButtonBit(param_1,2);
    }
  }
  else {
    dMs_onButtonBit(param_1,1);
  }
  lockFlag = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_item_delete(sub_ms_screen_class *) */

void dMs_item_delete(int param_1)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    if (*(void **)(iVar2 + 0x10c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x10c));
      *(undefined4 *)(iVar2 + 0x10c) = 0;
    }
    if (*(void **)(iVar2 + 0x114) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x114));
      *(undefined4 *)(iVar2 + 0x114) = 0;
    }
    if (*(void **)(iVar2 + 0x11c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x11c));
      *(undefined4 *)(iVar2 + 0x11c) = 0;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 2);
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x1b2); iVar1 = iVar1 + 1) {
    __ptr = *(void **)(param_1 + iVar3 + 0x128);
    if (__ptr != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),__ptr);
      *(undefined4 *)(param_1 + iVar3 + 0x128) = 0;
    }
    iVar3 = iVar3 + 4;
  }
  if (dMi_c != (int *)0x0) {
    d_com_inf_game::g_dComIfG_gameInfo._23523_1_ = *(undefined *)((int)dMi_c + 0x23ff);
    (**(code **)(*dMi_c + 0x14))();
    if (dMi_c != (int *)0x0) {
      (**(code **)(*dMi_c + 8))(dMi_c,1);
    }
    dMi_c = (int *)0x0;
  }
  lockFlag = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_collect_create(sub_ms_screen_class *) */

void dMs_collect_create(int param_1)

{
  void *pvVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(JKRArchive **)(param_1 + 0x104) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive;
  iVar11 = 0;
  iVar10 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x20,4);
    iVar9 = param_1 + iVar10;
    *(void **)(iVar9 + 0x10c) = pvVar1;
    if (*(int *)(iVar9 + 0x10c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x829,"i_Ms->name[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x829,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar9 + 0x114) = pvVar1;
    if (*(int *)(iVar9 + 0x114) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x82b,"i_Ms->note[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x82b,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar9 + 0x11c) = pvVar1;
    if (*(int *)(iVar9 + 0x11c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x82d,"i_Ms->dummy[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x82d,&DAT_80360851);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar11 < 2);
  *(undefined *)(param_1 + 0x1b2) = 0;
  iVar10 = 0;
  iVar11 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0xc00,0x20);
    *(void **)(param_1 + iVar11 + 0x128) = pvVar1;
    if (*(int *)(param_1 + iVar11 + 0x128) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x835,"i_Ms->buffer_p[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x835,&DAT_80360851);
    }
    *(char *)(param_1 + 0x1b2) = *(char *)(param_1 + 0x1b2) + '\x01';
    iVar10 = iVar10 + 1;
    iVar11 = iVar11 + 4;
  } while (iVar10 < 0x15);
  ppuVar3 = (undefined **)JKernel::operator_new(0x27f4);
  if (ppuVar3 == (undefined **)0x0) {
    dMc_c = ppuVar3;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x840,"dMc_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x840,&DAT_80360851);
  }
  else {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = &dMenu_base_c::__vt;
    *ppuVar3 = &dMenu_Collect_c::__vt;
    ppuVar3[0x922] = (undefined *)0xffffffff;
    ppuVar3[0x923] = (undefined *)0xffffffff;
    ppuVar3[0x924] = (undefined *)0xffffffff;
    ppuVar3[0x925] = (undefined *)0xffffffff;
    fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(ppuVar3 + 0x938));
    dMc_c = ppuVar3;
  }
  dMc_c[0x926] = *(undefined **)(param_1 + 0x128);
  iVar10 = 0;
  iVar11 = 3;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24c0) = *(undefined4 *)(param_1 + iVar10 + 300);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar10 = 0;
  iVar11 = 5;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24cc) = *(undefined4 *)(param_1 + iVar10 + 0x138);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar10 = 0;
  iVar11 = 8;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24a0) = *(undefined4 *)(param_1 + iVar10 + 0x14c);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  dMc_c[0x927] = *(undefined **)(param_1 + 0x16c);
  dMc_c[0x919] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive;
  dMc_c[0x91a] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpOptResArchive;
  dMc_c[0x91b] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSaveResArchive;
  ppuVar3 = dMc_c;
  puVar4 = rfonttype;
  dMc_c[0x91c] = fonttype;
  ppuVar3[0x91d] = puVar4;
  ppuVar3 = dMc_c;
  puVar8 = *(undefined **)(param_1 + 0x120);
  puVar7 = *(undefined **)(param_1 + 0x11c);
  puVar6 = *(undefined **)(param_1 + 0x118);
  puVar5 = *(undefined **)(param_1 + 0x114);
  puVar4 = *(undefined **)(param_1 + 0x110);
  dMc_c[0x9ec] = *(undefined **)(param_1 + 0x10c);
  ppuVar3[0x9ed] = puVar4;
  ppuVar3[0x9ee] = puVar5;
  ppuVar3[0x9ef] = puVar6;
  ppuVar3[0x9f0] = puVar7;
  ppuVar3[0x9f1] = puVar8;
  *(undefined *)((int)dMc_c + 0x27ed) = d_com_inf_game::g_dComIfG_gameInfo._23524_1_;
  (**(code **)(*dMc_c + 0x10))();
  if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel != 0) {
      dMs_onButtonBit(param_1,2);
    }
  }
  else {
    dMs_onButtonBit(param_1,1);
  }
  lockFlag = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_collect_create2(sub_ms_screen_class *) */

void dMs_collect_create2(int param_1)

{
  void *pvVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(JKRArchive **)(param_1 + 0x104) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive;
  iVar11 = 0;
  iVar10 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x20,4);
    iVar9 = param_1 + iVar10;
    *(void **)(iVar9 + 0x10c) = pvVar1;
    if (*(int *)(iVar9 + 0x10c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x887,"i_Ms->name[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x887,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar9 + 0x114) = pvVar1;
    if (*(int *)(iVar9 + 0x114) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x889,"i_Ms->note[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x889,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x200,4);
    *(void **)(iVar9 + 0x11c) = pvVar1;
    if (*(int *)(iVar9 + 0x11c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x88b,"i_Ms->dummy[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x88b,&DAT_80360851);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar11 < 2);
  *(undefined *)(param_1 + 0x1b2) = 0;
  iVar10 = 0;
  iVar11 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0xc00,0x20);
    *(void **)(param_1 + iVar11 + 0x128) = pvVar1;
    if (*(int *)(param_1 + iVar11 + 0x128) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x893,"i_Ms->buffer_p[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x893,&DAT_80360851);
    }
    *(char *)(param_1 + 0x1b2) = *(char *)(param_1 + 0x1b2) + '\x01';
    iVar10 = iVar10 + 1;
    iVar11 = iVar11 + 4;
  } while (iVar10 < 0x15);
  ppuVar3 = (undefined **)JKernel::operator_new(0x27f4);
  if (ppuVar3 == (undefined **)0x0) {
    dMc_c = ppuVar3;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x89d,"dMc_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x89d,&DAT_80360851);
  }
  else {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = &dMenu_base_c::__vt;
    *ppuVar3 = &dMenu_Collect_c::__vt;
    ppuVar3[0x922] = (undefined *)0xffffffff;
    ppuVar3[0x923] = (undefined *)0xffffffff;
    ppuVar3[0x924] = (undefined *)0xffffffff;
    ppuVar3[0x925] = (undefined *)0xffffffff;
    fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(ppuVar3 + 0x938));
    dMc_c = ppuVar3;
  }
  dMc_c[0x926] = *(undefined **)(param_1 + 0x128);
  iVar10 = 0;
  iVar11 = 3;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24c0) = *(undefined4 *)(param_1 + iVar10 + 300);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar10 = 0;
  iVar11 = 5;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24cc) = *(undefined4 *)(param_1 + iVar10 + 0x138);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar10 = 0;
  iVar11 = 8;
  do {
    *(undefined4 *)((int)dMc_c + iVar10 + 0x24a0) = *(undefined4 *)(param_1 + iVar10 + 0x14c);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  dMc_c[0x927] = *(undefined **)(param_1 + 0x16c);
  dMc_c[0x919] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive;
  dMc_c[0x91a] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpOptResArchive;
  dMc_c[0x91b] = (undefined *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSaveResArchive;
  ppuVar3 = dMc_c;
  puVar4 = rfonttype;
  dMc_c[0x91c] = fonttype;
  ppuVar3[0x91d] = puVar4;
  ppuVar3 = dMc_c;
  puVar8 = *(undefined **)(param_1 + 0x120);
  puVar7 = *(undefined **)(param_1 + 0x11c);
  puVar6 = *(undefined **)(param_1 + 0x118);
  puVar5 = *(undefined **)(param_1 + 0x114);
  puVar4 = *(undefined **)(param_1 + 0x110);
  dMc_c[0x9ec] = *(undefined **)(param_1 + 0x10c);
  ppuVar3[0x9ed] = puVar4;
  ppuVar3[0x9ee] = puVar5;
  ppuVar3[0x9ef] = puVar6;
  ppuVar3[0x9f0] = puVar7;
  ppuVar3[0x9f1] = puVar8;
  *(undefined *)((int)dMc_c + 0x27ed) = d_com_inf_game::g_dComIfG_gameInfo._23524_1_;
  dMenu_Collect_c::_create3((dMenu_Collect_c *)dMc_c);
  if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel != 0) {
      dMs_onButtonBit(param_1,2);
    }
  }
  else {
    dMs_onButtonBit(param_1,1);
  }
  lockFlag = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_collect_delete(sub_ms_screen_class *) */

void dMs_collect_delete(int param_1)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    if (*(void **)(iVar2 + 0x10c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x10c));
      *(undefined4 *)(iVar2 + 0x10c) = 0;
    }
    if (*(void **)(iVar2 + 0x114) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x114));
      *(undefined4 *)(iVar2 + 0x114) = 0;
    }
    if (*(void **)(iVar2 + 0x11c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar2 + 0x11c));
      *(undefined4 *)(iVar2 + 0x11c) = 0;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 2);
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x1b2); iVar1 = iVar1 + 1) {
    __ptr = *(void **)(param_1 + iVar3 + 0x128);
    if (__ptr != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),__ptr);
      *(undefined4 *)(param_1 + iVar3 + 0x128) = 0;
    }
    iVar3 = iVar3 + 4;
  }
  if (dMc_c != (int *)0x0) {
    d_com_inf_game::g_dComIfG_gameInfo._23524_1_ = *(undefined *)((int)dMc_c + 0x27ed);
    (**(code **)(*dMc_c + 0x14))();
    if (dMc_c != (int *)0x0) {
      (**(code **)(*dMc_c + 8))(dMc_c,1);
    }
    dMc_c = (int *)0x0;
  }
  lockFlag = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMs_fmap_create(sub_ms_screen_class *) */

void dMs_fmap_create(int param_1)

{
  dMenu_Fmap_c *pdVar1;
  void *pvVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 2;
  iVar11 = 0;
  iVar10 = 0;
  do {
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x40,4);
    iVar9 = param_1 + iVar10;
    *(void **)(iVar9 + 0x10c) = pvVar2;
    if (*(int *)(iVar9 + 0x10c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x927,"i_Ms->name[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x927,&DAT_80360851);
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x200,4);
    *(void **)(iVar9 + 0x114) = pvVar2;
    if (*(int *)(iVar9 + 0x114) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x929,"i_Ms->note[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x929,&DAT_80360851);
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x200,4);
    *(void **)(iVar9 + 0x11c) = pvVar2;
    if (*(int *)(iVar9 + 0x11c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x92b,"i_Ms->dummy[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x92b,&DAT_80360851);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar11 < 2);
  dMf_c = (dMenu_Fmap_c *)JKernel::operator_new(0x51b4);
  if (dMf_c == (dMenu_Fmap_c *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x930,"dMf_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x930,&DAT_80360851);
  }
  else {
    *(undefined1 **)dMf_c = &::dMenu_Fmap_c::__vt;
    *(undefined ***)&dMf_c->field_0x1c = &dDlst_base_c::__vt;
    *(undefined1 **)&dMf_c->field_0x1c = &dDlst_FMAP_c::__vt;
    *(undefined1 **)&dMf_c->field_0x24 = &::dMenu_Fmap2_c::__vt;
    *(undefined ***)&dMf_c->field_0x44 = &dDlst_base_c::__vt;
    *(undefined1 **)&dMf_c->field_0x44 = &dDlst_FMAP2_c::__vt;
    *(undefined ***)&dMf_c->field_0x4c = &dDlst_base_c::__vt;
    *(undefined1 **)&dMf_c->field_0x4c = &dDlst_FMAP2GS_c::__vt;
    *(undefined4 *)&dMf_c->field_0x2844 = 0xffffffff;
    *(undefined4 *)&dMf_c->field_0x2848 = 0xffffffff;
    *(undefined4 *)&dMf_c->field_0x284c = 0xffffffff;
    *(undefined4 *)&dMf_c->field_0x2850 = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x14 = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x18 = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x1c = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x20 = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x24 = 0xffffffff;
    *(undefined4 *)&dMf_c[1].field_0x28 = 0xffffffff;
  }
  dMf_c->mFmapSv = &dMv_CIO_c;
  pdVar1 = dMf_c;
  uVar4 = rfonttype;
  *(undefined4 *)&dMf_c->field_0x50d0 = fonttype;
  *(undefined4 *)&pdVar1->field_0x50d4 = uVar4;
  pdVar1 = dMf_c;
  uVar8 = *(undefined4 *)(param_1 + 0x120);
  uVar7 = *(undefined4 *)(param_1 + 0x11c);
  uVar6 = *(undefined4 *)(param_1 + 0x118);
  uVar5 = *(undefined4 *)(param_1 + 0x114);
  uVar4 = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)&dMf_c->field_0x5148 = *(undefined4 *)(param_1 + 0x10c);
  *(undefined4 *)&pdVar1->field_0x514c = uVar4;
  *(undefined4 *)&pdVar1->field_0x5154 = uVar5;
  *(undefined4 *)&pdVar1->field_0x5158 = uVar6;
  *(undefined4 *)&pdVar1->field_0x515c = uVar7;
  *(undefined4 *)&pdVar1->field_0x5160 = uVar8;
  ::dMenu_Fmap_c::_create(dMf_c);
  dMs_capture_c = (dDlst_MENU_CAPTURE_c *)JKernel::operator_new(8);
  if (dMs_capture_c == (dDlst_MENU_CAPTURE_c *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_menu_window.cpp",0x93a,"dMs_capture_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x93a,&DAT_80360851);
  }
  else {
    (dMs_capture_c->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    (dMs_capture_c->parent).vtbl = &::dDlst_MENU_CAPTURE_c::__vt;
    dMs_capture_c->mStatus = 0;
  }
  if (*(char *)(param_1 + 0x1b5) == '\x17') {
    dMs_capture_c->mStatus = 1;
  }
  if (*(char *)(param_1 + 0x1b5) == '\x15') {
    ::dMenu_Fmap_c::backClothDispInit(dMf_c);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMs_fmap_delete(sub_ms_screen_class *) */

void dMs_fmap_delete(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    if (*(void **)(iVar2 + 0x10c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x10c));
      *(undefined4 *)(iVar2 + 0x10c) = 0;
    }
    if (*(void **)(iVar2 + 0x114) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x114));
      *(undefined4 *)(iVar2 + 0x114) = 0;
    }
    if (*(void **)(iVar2 + 0x11c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x11c));
      *(undefined4 *)(iVar2 + 0x11c) = 0;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 2);
  if (dMf_c != (dMenu_Fmap_c *)0x0) {
    ::dMenu_Fmap_c::_delete(dMf_c);
    if (dMf_c != (dMenu_Fmap_c *)0x0) {
      (**(code **)(*(int *)dMf_c + 8))(dMf_c,1);
    }
    dMf_c = (dMenu_Fmap_c *)0x0;
  }
  if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      (**(code **)((dMs_capture_c->parent).vtbl + 8))(dMs_capture_c,1);
    }
    dMs_capture_c = (dDlst_MENU_CAPTURE_c *)0x0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMs_dmap_create(sub_ms_screen_class *) */

void dMs_dmap_create(int param_1)

{
  void *pvVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(JKRArchive **)(param_1 + 0x104) = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDMapResArchive;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 3;
  iVar11 = 0;
  iVar10 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x20,4);
    iVar9 = param_1 + iVar10;
    *(void **)(iVar9 + 0x10c) = pvVar1;
    if (*(int *)(iVar9 + 0x10c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9a0,"i_Ms->name[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x9a0,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x200,4);
    *(void **)(iVar9 + 0x114) = pvVar1;
    if (*(int *)(iVar9 + 0x114) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9a2,"i_Ms->note[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x9a2,&DAT_80360851);
    }
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x200,4);
    *(void **)(iVar9 + 0x11c) = pvVar1;
    if (*(int *)(iVar9 + 0x11c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9a4,"i_Ms->dummy[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x9a4,&DAT_80360851);
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar11 < 2);
  *(undefined *)(param_1 + 0x1b2) = 0;
  iVar10 = 0;
  iVar11 = 0;
  do {
    pvVar1 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0xc00,0x20);
    *(void **)(param_1 + iVar11 + 0x128) = pvVar1;
    if (*(int *)(param_1 + iVar11 + 0x128) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9ab,"i_Ms->buffer_p[i] != 0");
      m_Do_printf::OSPanic("d_menu_window.cpp",0x9ab,&DAT_80360851);
    }
    *(char *)(param_1 + 0x1b2) = *(char *)(param_1 + 0x1b2) + '\x01';
    iVar10 = iVar10 + 1;
    iVar11 = iVar11 + 4;
  } while (iVar10 < 3);
  ppuVar3 = (undefined **)JKernel::operator_new(0x1e38);
  if (ppuVar3 == (undefined **)0x0) {
    dMd_c = ppuVar3;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9b0,"dMd_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x9b0,&DAT_80360851);
  }
  else {
    *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
    *ppuVar3 = &dMenu_base_c::__vt;
    *ppuVar3 = &dMenu_Dmap_c::__vt;
    ppuVar3[0x52d] = (undefined *)0xffffffff;
    ppuVar3[0x52e] = (undefined *)0xffffffff;
    ppuVar3[0x52f] = (undefined *)0xffffffff;
    ppuVar3[0x530] = (undefined *)0xffffffff;
    ppuVar3[0x531] = (undefined *)0xffffffff;
    ppuVar3[0x532] = (undefined *)0xffffffff;
    fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(ppuVar3 + 0x6c2));
    dMd_c = ppuVar3;
  }
  iVar10 = 0;
  iVar11 = 3;
  do {
    *(undefined4 *)((int)dMd_c + iVar10 + 0x1afc) = *(undefined4 *)(param_1 + iVar10 + 0x128);
    iVar10 = iVar10 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  dMd_c[0x529] = *(undefined **)(param_1 + 0x104);
  ppuVar3 = dMd_c;
  puVar4 = rfonttype;
  dMd_c[0x52a] = fonttype;
  ppuVar3[0x52b] = puVar4;
  ppuVar3 = dMd_c;
  puVar8 = *(undefined **)(param_1 + 0x120);
  puVar7 = *(undefined **)(param_1 + 0x11c);
  puVar6 = *(undefined **)(param_1 + 0x118);
  puVar5 = *(undefined **)(param_1 + 0x114);
  puVar4 = *(undefined **)(param_1 + 0x110);
  dMd_c[0x76a] = *(undefined **)(param_1 + 0x10c);
  ppuVar3[0x76b] = puVar4;
  ppuVar3[0x76c] = puVar5;
  ppuVar3[0x76d] = puVar6;
  ppuVar3[0x76e] = puVar7;
  ppuVar3[0x76f] = puVar8;
  (**(code **)(*dMd_c + 0x10))();
  dMs_capture_c = (dDlst_MENU_CAPTURE_c *)JKernel::operator_new(8);
  if (dMs_capture_c == (dDlst_MENU_CAPTURE_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0x9bb,"dMs_capture_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x9bb,&DAT_80360851);
  }
  else {
    (dMs_capture_c->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    (dMs_capture_c->parent).vtbl = &::dDlst_MENU_CAPTURE_c::__vt;
    dMs_capture_c->mStatus = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMs_dmap_delete(sub_ms_screen_class *) */

void dMs_dmap_delete(int param_1)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    if (*(void **)(iVar2 + 0x10c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x10c));
      *(undefined4 *)(iVar2 + 0x10c) = 0;
    }
    if (*(void **)(iVar2 + 0x114) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x114));
      *(undefined4 *)(iVar2 + 0x114) = 0;
    }
    if (*(void **)(iVar2 + 0x11c) != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar2 + 0x11c));
      *(undefined4 *)(iVar2 + 0x11c) = 0;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 2);
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x1b2); iVar1 = iVar1 + 1) {
    __ptr = *(void **)(param_1 + iVar3 + 0x128);
    if (__ptr != (void *)0x0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),__ptr);
      *(undefined4 *)(param_1 + iVar3 + 0x128) = 0;
    }
    iVar3 = iVar3 + 4;
  }
  if (dMd_c != (int *)0x0) {
    (**(code **)(*dMd_c + 0x14))();
    if (dMd_c != (int *)0x0) {
      (**(code **)(*dMd_c + 8))(dMd_c,1);
    }
    dMd_c = (int *)0x0;
  }
  if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      (**(code **)((dMs_capture_c->parent).vtbl + 8))(dMs_capture_c,1);
    }
    dMs_capture_c = (dDlst_MENU_CAPTURE_c *)0x0;
  }
  return;
}


/* __stdcall dMs_name_create(sub_ms_screen_class *) */

void dMs_name_create(void)

{
  ulong uVar1;
  
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 10;
  dNm_c = (undefined4 *)JKernel::operator_new(0x2ae8);
  if (dNm_c == (undefined4 *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_window.cpp",0xa09,"dNm_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa09,&DAT_80360851);
  }
  else {
    *dNm_c = &::dName_c::__vt;
    dNm_c[2] = &dDlst_base_c::__vt;
    dNm_c[2] = &::dDlst_NameIN_c::__vt;
  }
  ::dName_c::_create((dName_c *)dNm_c);
  dMs_capture_c = (dDlst_MENU_CAPTURE_c *)JKernel::operator_new(8);
  if (dMs_capture_c == (dDlst_MENU_CAPTURE_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_window.cpp",0xa0d,"dMs_capture_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa0d,&DAT_80360851);
  }
  else {
    (dMs_capture_c->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    (dMs_capture_c->parent).vtbl = &::dDlst_MENU_CAPTURE_c::__vt;
    dMs_capture_c->mStatus = 0;
  }
  return;
}


/* __stdcall dMs_name_delete(sub_ms_screen_class *) */

void dMs_name_delete(void)

{
  if (dNm_c != (int *)0x0) {
    ::dName_c::_delete((dName_c *)dNm_c);
    if (dNm_c != (int *)0x0) {
      (**(code **)(*dNm_c + 8))(dNm_c,1);
    }
    dNm_c = (int *)0x0;
  }
  if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      (**(code **)((dMs_capture_c->parent).vtbl + 8))(dMs_capture_c,1);
    }
    dMs_capture_c = (dDlst_MENU_CAPTURE_c *)0x0;
  }
  return;
}


/* __stdcall dMs_save_delete(sub_ms_screen_class *) */

void dMs_save_delete(void)

{
  if (dMs_c != (int *)0x0) {
    dMenu_save_c::_delete((dMenu_save_c *)dMs_c);
    if (dMs_c != (int *)0x0) {
      (**(code **)(*dMs_c + 8))(dMs_c,1);
    }
    dMs_c = (int *)0x0;
  }
  if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      (**(code **)((dMs_capture_c->parent).vtbl + 8))(dMs_capture_c,1);
    }
    dMs_capture_c = (dDlst_MENU_CAPTURE_c *)0x0;
  }
  return;
}


/* __stdcall dMs_cloth_create(sub_ms_screen_class *) */

void dMs_cloth_create(int param_1,EVP_PKEY_CTX *param_2)

{
  JKRArchive *pJVar1;
  dMCloth_c *this;
  ulong uVar2;
  JKRExpHeap *pJVar3;
  EVP_PKEY_CTX *extraout_r4;
  
  pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 1;
  this = (dMCloth_c *)JKernel::operator_new(0x9168);
  if (this != (dMCloth_c *)0x0) {
    dMCloth_c::dMCloth_c(this);
  }
  cloth_c = this;
  if (this == (dMCloth_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xa72,"cloth_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa72,&DAT_80360851);
    param_2 = extraout_r4;
  }
  *(JKRArchive **)(cloth_c + 0x44) = pJVar1;
  dMCloth_c::init(cloth_c,param_2);
  dMs_cloth_c = (undefined **)JKernel::operator_new(4);
  if (dMs_cloth_c == (undefined **)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xa78,"dMs_cloth_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa78,&DAT_80360851);
  }
  else {
    *dMs_cloth_c = (undefined *)&dDlst_base_c::__vt;
    *dMs_cloth_c = &::dDlst_MENU_CLOTH_c::__vt;
  }
  dMs_capture_c = (dDlst_MENU_CAPTURE_c *)JKernel::operator_new(8);
  if (dMs_capture_c == (dDlst_MENU_CAPTURE_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xa7b,"dMs_capture_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa7b,&DAT_80360851);
  }
  else {
    (dMs_capture_c->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    (dMs_capture_c->parent).vtbl = &::dDlst_MENU_CAPTURE_c::__vt;
    dMs_capture_c->mStatus = 0;
  }
  pJVar3 = JKRExpHeap::create(0x506a1,*(JKRHeap **)(param_1 + 0xfc),false);
  *(JKRExpHeap **)(param_1 + 0x100) = pJVar3;
  if (*(int *)(param_1 + 0x100) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xa7e,"i_Ms->childHeap != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xa7e,&DAT_80360851);
  }
  return;
}


/* __stdcall dMs_cloth_delete(sub_ms_screen_class *) */

void dMs_cloth_delete(int param_1)

{
  if (*(JKRHeap **)(param_1 + 0x100) != (JKRHeap *)0x0) {
    JKRHeap::destroy(*(JKRHeap **)(param_1 + 0x100));
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  if (dMs_cloth_c != (int *)0x0) {
    if (dMs_cloth_c != (int *)0x0) {
      (**(code **)(*dMs_cloth_c + 8))(dMs_cloth_c,1);
    }
    dMs_cloth_c = (int *)0x0;
  }
  if (cloth_c != (int *)0x0) {
    if (cloth_c != (int *)0x0) {
      (**(code **)(*cloth_c + 8))(cloth_c,1);
    }
    cloth_c = (int *)0x0;
  }
  if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      (**(code **)((dMs_capture_c->parent).vtbl + 8))(dMs_capture_c,1);
    }
    dMs_capture_c = (dDlst_MENU_CAPTURE_c *)0x0;
  }
  return;
}


/* __stdcall dMs_clothOnly_create(sub_ms_screen_class *) */

void dMs_clothOnly_create(undefined4 param_1,EVP_PKEY_CTX *param_2)

{
  JKRArchive *pJVar1;
  dMCloth_c *this;
  ulong uVar2;
  EVP_PKEY_CTX *extraout_r4;
  
  pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive;
  this = (dMCloth_c *)JKernel::operator_new(0x9168);
  if (this != (dMCloth_c *)0x0) {
    dMCloth_c::dMCloth_c(this);
  }
  cloth_c = this;
  if (this == (dMCloth_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xab8,"cloth_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xab8,&DAT_80360851);
    param_2 = extraout_r4;
  }
  *(JKRArchive **)(cloth_c + 0x44) = pJVar1;
  cloth_c[0x913d] = (dMCloth_c)0x2;
  dMCloth_c::init(cloth_c,param_2);
  dMs_cloth_c = (undefined **)JKernel::operator_new(4);
  if (dMs_cloth_c == (undefined **)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_window.cpp",0xabf,"dMs_cloth_c != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0xabf,&DAT_80360851);
  }
  else {
    *dMs_cloth_c = (undefined *)&dDlst_base_c::__vt;
    *dMs_cloth_c = &::dDlst_MENU_CLOTH_c::__vt;
  }
  return;
}


/* __stdcall dMs_clothOnly_delete(sub_ms_screen_class *) */

void dMs_clothOnly_delete(void)

{
  if (dMs_cloth_c != (int *)0x0) {
    if (dMs_cloth_c != (int *)0x0) {
      (**(code **)(*dMs_cloth_c + 8))(dMs_cloth_c,1);
    }
    dMs_cloth_c = (int *)0x0;
  }
  if (cloth_c != (int *)0x0) {
    (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive)->parent).parent.vtbl)->
              removeResourceAll)();
    if (cloth_c != (int *)0x0) {
      (**(code **)(*cloth_c + 8))(cloth_c,1);
    }
    cloth_c = (int *)0x0;
  }
  return;
}


/* __stdcall dMs_onButtonBit(sub_ms_screen_class *,
                             unsigned char) */

void dMs_onButtonBit(int param_1,byte param_2)

{
  *(byte *)(param_1 + 0x1b6) = *(byte *)(param_1 + 0x1b6) | param_2;
  return;
}


/* __stdcall dMs_offButtonBit(sub_ms_screen_class *,
                              unsigned char) */

void dMs_offButtonBit(int param_1,byte param_2)

{
  *(byte *)(param_1 + 0x1b6) = *(byte *)(param_1 + 0x1b6) & ~param_2;
  return;
}


/* __stdcall dMs_isButtonBit(sub_ms_screen_class *,
                             unsigned char) */

bool dMs_isButtonBit(int param_1,byte param_2)

{
  return (param_2 & *(byte *)(param_1 + 0x1b6)) != 0;
}


/* __stdcall dMs_isPush_L_Button(sub_ms_screen_class *) */

undefined4 dMs_isPush_L_Button(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0) ||
     (iVar1 = dMs_isButtonBit(param_1,1), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    dMs_onButtonBit(param_1,1);
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall dMs_isPush_R_Button(sub_ms_screen_class *) */

undefined4 dMs_isPush_R_Button(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel == 0) ||
     (iVar1 = dMs_isButtonBit(param_1,2), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    dMs_onButtonBit(param_1,2);
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall dMs_childHeap_freeAll(sub_ms_screen_class *) */

void dMs_childHeap_freeAll(int param_1)

{
  if (*(JKRHeap **)(param_1 + 0x100) != (JKRHeap *)0x0) {
    JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0x100));
  }
  return;
}


/* __stdcall dMs_telescopeMove(sub_ms_screen_class *) */

void dMs_telescopeMove(int param_1)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  msg_class *pmVar4;
  float local_18;
  float local_14;
  float local_10;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) {
    dEvt_control_c::photoCheck(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl);
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 8) == 0) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 0x40) == 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 == 2) {
          *(undefined2 *)(param_1 + 0x1b0) = 0x62;
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 2) ||
             (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 3)) {
            *(undefined2 *)(param_1 + 0x1b0) = 0x59;
            d_meter::dMenu_flagSet(1);
          }
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x1b0) = 0x59;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x1b0) = 99;
    }
    sVar1 = *(short *)(param_1 + 0x1b0);
    if ((((sVar1 == 99) || (sVar1 == 0x59)) || (sVar1 == 0x62)) && (*(int *)(param_1 + 0x108) == -1)
       ) {
      local_18 = _4299;
      local_14 = _4299;
      local_10 = _4299;
      uVar3 = f_op_msg_mng::fopMsgM_messageSet((uint)*(ushort *)(param_1 + 0x1b0) << 0x10,&local_18)
      ;
      *(undefined4 *)(param_1 + 0x108) = uVar3;
      uVar2 = *(ushort *)(param_1 + 0x1b0);
      if (uVar2 < 0x62) {
        if (uVar2 == 0x59) {
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 6;
        }
      }
      else {
        if (uVar2 < 100) {
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 5;
        }
      }
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x108) != 0xffffffff) &&
       (pmVar4 = f_op_msg_mng::fopMsgM_SearchByID(*(uint *)(param_1 + 0x108)),
       pmVar4 != (msg_class *)0x0)) {
      if (pmVar4->mMode == 0xe) {
        pmVar4->mMode = 0x10;
      }
      else {
        if (pmVar4->mMode == 0x12) {
          pmVar4->mMode = 0x13;
          *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
          *(undefined2 *)(param_1 + 0x1b0) = 0;
        }
      }
    }
  }
  return;
}


/* __stdcall dMs_placenameMove(sub_ms_screen_class *) */

void dMs_placenameMove(void)

{
  int iVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) {
    iVar1 = dEvent_manager_c::startCheckOld
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"awake");
    if (iVar1 == 0) {
      iVar1 = dEvent_manager_c::startCheckOld
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"majyuu_shinnyuu");
      if ((iVar1 != 0) &&
         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr != (dDemo_manager_c *)0x0)) {
        if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 0xb54) {
          d_com_inf_game::g_dComIfG_gameInfo._23543_1_ = 1;
          d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = 2;
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 0xbea) {
            d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = 1;
          }
        }
      }
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr != (dDemo_manager_c *)0x0) {
        if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 200) {
          d_com_inf_game::g_dComIfG_gameInfo._23543_1_ = 0;
          d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = 2;
          dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3510);
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8 == 0x15e) {
            d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = 1;
          }
        }
      }
    }
  }
  return;
}


/* __stdcall dMs_Draw(sub_ms_screen_class *) */

undefined4 dMs_Draw(void)

{
  byte bVar2;
  int iVar1;
  
  bVar2 = d_meter::dMenu_flag();
  if ((bVar2 == 1) ||
     ((dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0 && (dMs_capture_c->mStatus != 0)))) {
    if (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0) {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                        &dMs_capture_c->parent);
      if (dMs_capture_c->mStatus == 2) {
        dMs_capture_c->mStatus = 0;
        d_meter::dMenu_flagSet(1);
      }
    }
    bVar2 = d_meter::dMenu_getMenuStatus();
    if (bVar2 == 1) {
      if (dMs_cloth_c != (dDlst_base_c *)0x0) {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,dMs_cloth_c);
      }
      if (dMi_c != (dDlst_base_c *)0x0) {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,dMi_c);
      }
    }
    else {
      bVar2 = d_meter::dMenu_getMenuStatus();
      if (bVar2 == 2) {
        if (dMs_cloth_c != (dDlst_base_c *)0x0) {
          dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                            &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                            &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,dMs_cloth_c);
        }
        if (dMc_c != (dDlst_base_c *)0x0) {
          dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                            &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                            &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,dMc_c);
        }
      }
      else {
        bVar2 = d_meter::dMenu_getMenuStatus();
        if (bVar2 == 3) {
          iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(ushort *)(iVar1 + 10) & 3) == 1) {
            if (dMd_c != (dDlst_base_c *)0x0) {
              dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                                &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                                &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,dMd_c);
            }
          }
          else {
            iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getStagInfo)(0x803c9d58);
            if ((*(ushort *)(iVar1 + 10) & 3) == 0) {
              if (dMs_cloth_c != (dDlst_base_c *)0x0) {
                dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                                  &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                                  &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                                  dMs_cloth_c);
              }
              if (dMf_c != (dMenu_Fmap_c *)0x0) {
                ::dMenu_Fmap_c::_draw(dMf_c);
              }
            }
          }
        }
        else {
          bVar2 = d_meter::dMenu_getMenuStatus();
          if (bVar2 == 4) {
            if (dNm_c != (dName_c *)0x0) {
              ::dName_c::_draw(dNm_c);
            }
          }
          else {
            bVar2 = d_meter::dMenu_getMenuStatus();
            if ((bVar2 == 5) && (dMs_c != (dMenu_save_c *)0x0)) {
              dMenu_save_c::_draw2(dMs_c);
            }
          }
        }
      }
    }
  }
  else {
    bVar2 = d_meter::dMenu_flag();
    if ((bVar2 == 3) && (dMs_capture_c != (dDlst_MENU_CAPTURE_c *)0x0)) {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                        &dMs_capture_c->parent);
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMs_Execute(sub_ms_screen_class *) */

undefined4 dMs_Execute(int param_1)

{
  undefined4 uVar1;
  byte bVar3;
  int iVar2;
  char cVar4;
  
  if (init_7110 == '\0') {
    timer_7109 = 0;
    init_7110 = '\x01';
  }
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    if (event_wait_frame < '\x01') {
      event_wait_frame = '\0';
    }
    else {
      event_wait_frame = event_wait_frame + -1;
    }
  }
  else {
    event_wait_frame = '\x05';
  }
  cVar4 = *(char *)(param_1 + 0x1b5);
  if (((cVar4 == '\0') && (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0)) &&
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca == 0)) {
    bVar3 = d_meter::dMenu_flag();
    if (bVar3 == 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
        iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
        if (iVar2 == 0) {
          if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf1 == 1) {
            timer_7109 = 0;
            *(undefined *)(param_1 + 0x1b5) = 0x16;
            dMs_fmap_create(param_1);
            d_meter::dMenu_flagSet(1);
            bVar3 = d_meter::dMenu_getMenuStatus();
            d_meter::dMenu_setMenuStatusOld(bVar3);
            d_meter::dMenu_setMenuStatus(3);
            d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf1 = 0;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8cb,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
            goto LAB_801df1c4;
          }
        }
      }
    }
    bVar3 = d_meter::dMenu_flag();
    if (bVar3 == 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
        iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
        if (iVar2 == 0) {
          if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf2 == 2) {
            timer_7109 = 0;
            *(undefined *)(param_1 + 0x1b5) = 0x21;
            dMs_name_create(param_1);
            d_meter::dMenu_flagSet(1);
            bVar3 = d_meter::dMenu_getMenuStatus();
            d_meter::dMenu_setMenuStatusOld(bVar3);
            d_meter::dMenu_setMenuStatus(4);
            goto LAB_801df1c4;
          }
        }
      }
    }
    bVar3 = d_meter::dMenu_flag();
    if (bVar3 == 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
        iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
        if ((iVar2 == 0) && (d_com_inf_game::g_dComIfG_gameInfo._23546_1_ != '\0')) {
          dMs_cloth_create(param_1);
          timer_7109 = 0;
          d_meter::dMenu_flagSet(1);
          *(undefined *)(param_1 + 0x1b5) = 0xc;
          m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
          dMs_collect_create2(param_1);
          bVar3 = d_meter::dMenu_getMenuStatus();
          d_meter::dMenu_setMenuStatusOld(bVar3);
          d_meter::dMenu_setMenuStatus(2);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x815,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
          d_com_inf_game::g_dComIfG_gameInfo._23546_1_ = '\0';
          goto LAB_801df1c4;
        }
      }
    }
    bVar3 = d_meter::dMenu_flag();
    if (bVar3 == 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
        iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
        if (iVar2 == 0) {
          if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf1 == 2) {
            timer_7109 = 0;
            *(undefined *)(param_1 + 0x1b5) = 0x18;
            dMs_fmap_create(param_1);
            d_meter::dMenu_flagSet(1);
            bVar3 = d_meter::dMenu_getMenuStatus();
            d_meter::dMenu_setMenuStatusOld(bVar3);
            d_meter::dMenu_setMenuStatus(3);
            d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf1 = 0;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x850,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
            goto LAB_801df1c4;
          }
        }
      }
    }
    bVar3 = d_meter::dMenu_flag();
    if (bVar3 == 0) {
      iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
      if (iVar2 == 0) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
          if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0) {
              if (event_wait_frame != '\0') {
                iVar2 = daPy_lk_c::getTactNormalWait
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
                if ((iVar2 == 0) ||
                   ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)) {
                  if ((d_com_inf_game::g_dComIfG_gameInfo._23526_1_ != '\x02') ||
                     ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0 ||
                       (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.
                                          parent)->getStagInfo)(0x803c9d58),
                       (*(ushort *)(iVar2 + 10) & 3) != 0)) ||
                      (iVar2 = dSv_event_c::isEventBit
                                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                          0x908), iVar2 == 0)))) goto LAB_801df1c4;
                }
              }
              if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca == 0) {
                if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0) {
                  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 8) == 0)
                  {
                    if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 0x40)
                         == 0) &&
                       ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x800000U) == 0)) {
                      if (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02') {
                        if (((d_com_inf_game::g_dComIfG_gameInfo._23526_1_ != '\x02') ||
                            ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0)) ||
                           (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.
                                              parent)->getStagInfo)(0x803c9d58),
                           (*(ushort *)(iVar2 + 10) & 3) != 0)) goto LAB_801df1c4;
                        iVar2 = dSv_event_c::isEventBit
                                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                           0x908);
                        if (iVar2 == 0) goto LAB_801df1c4;
                      }
                      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0) {
                        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
                          if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor ==
                              d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor) {
                            dMs_cloth_create(param_1);
                            timer_7109 = 0;
                            d_meter::dMenu_flagSet(1);
                            bVar3 = d_meter::dMenu_getMenuStatus();
                            if ((bVar3 == 2) ||
                               (iVar2 = daPy_lk_c::getTactNormalWait
                                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.
                                                   mpLinkActor), iVar2 != 0)) {
                              m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
                              dMs_collect_create(param_1);
                              *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x2;
                              iVar2 = daPy_lk_c::getTactNormalWait
                                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.
                                                 mpLinkActor);
                              if (iVar2 == 0) {
                                *(undefined *)(param_1 + 0x1b5) = 8;
                              }
                              else {
                                *(undefined *)(param_1 + 0x1b5) = 0xb;
                              }
                              bVar3 = d_meter::dMenu_getMenuStatus();
                              d_meter::dMenu_setMenuStatusOld(bVar3);
                              d_meter::dMenu_setMenuStatus(2);
                              d_meter::dMenu_setPushMenuButton(2);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x815,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                            }
                            else {
                              m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
                              dMs_item_create(param_1);
                              *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x2;
                              *(undefined *)(param_1 + 0x1b5) = 1;
                              bVar3 = d_meter::dMenu_getMenuStatus();
                              d_meter::dMenu_setMenuStatusOld(bVar3);
                              d_meter::dMenu_setMenuStatus(1);
                              d_meter::dMenu_setPushMenuButton(1);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x815,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                            }
                            goto LAB_801df1c4;
                          }
                        }
                      }
                      bVar3 = d_meter::dMenu_flag();
                      if ((bVar3 == 0) &&
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0)) {
                        iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
                        if ((iVar2 == 0) &&
                           ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) != 0)) {
                          timer_7109 = 0;
                          iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.
                                            parent)->getStagInfo)(0x803c9d58);
                          if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
                            *(undefined *)(param_1 + 0x1b5) = 0x1e;
                            dMs_dmap_create(param_1);
                            d_meter::dMenu_flagSet(1);
                            bVar3 = d_meter::dMenu_getMenuStatus();
                            d_meter::dMenu_setMenuStatusOld(bVar3);
                            d_meter::dMenu_setMenuStatus(3);
                            JAIZelBasic::seStart
                                      (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,
                                       _7759,_7759,0);
                            JAIZelBasic::seStart
                                      (JAIZelBasic::zel_basic,0x850,(cXyz *)0x0,0,0,_4300,_4300,
                                       _7759,_7759,0);
                          }
                          else {
                            iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.
                                              parent)->getStagInfo)(0x803c9d58);
                            if (((((*(ushort *)(iVar2 + 10) & 3) == 0) &&
                                 (iVar2 = dSv_event_c::isEventBit
                                                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.
                                                      mSave.mEvent,0x908), iVar2 != 0)) &&
                                (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 1)) &&
                               (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 6)) {
                              if (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02') {
                                *(undefined *)(param_1 + 0x1b5) = 0x17;
                              }
                              else {
                                *(undefined *)(param_1 + 0x1b5) = 0x15;
                                dMs_clothOnly_create(param_1);
                                d_meter::dMenu_flagSet(1);
                              }
                              dMs_fmap_create(param_1);
                              bVar3 = d_meter::dMenu_getMenuStatus();
                              d_meter::dMenu_setMenuStatusOld(bVar3);
                              d_meter::dMenu_setMenuStatus(3);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x80f,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                              JAIZelBasic::seStart
                                        (JAIZelBasic::zel_basic,0x850,(cXyz *)0x0,0,0,_4300,_4300,
                                         _7759,_7759,0);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x01') {
    timer_7109 = timer_7109 + 1;
    dMCloth_c::cloth_move(cloth_c);
    if (DAT_803e6afc < timer_7109) {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      cVar4 = (**(code **)(*dMi_c + 0x20))();
      if (cVar4 != '\0') {
        *(undefined *)(param_1 + 0x1b5) = 4;
      }
    }
    goto LAB_801df1c4;
  }
  if ((cVar4 == '\b') || (cVar4 == '\v')) {
    timer_7109 = timer_7109 + 1;
    dMCloth_c::cloth_move(cloth_c);
    if (DAT_803e6afc < timer_7109) {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      cVar4 = (**(code **)(*dMc_c + 0x20))();
      if (cVar4 != '\0') {
        if (*(char *)(param_1 + 0x1b5) == '\v') {
          *(undefined *)(param_1 + 0x1b5) = 0xe;
        }
        else {
          *(undefined *)(param_1 + 0x1b5) = 0xd;
        }
      }
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\f') {
    timer_7109 = timer_7109 + 1;
    dMCloth_c::cloth_move(cloth_c);
    if (DAT_803e6afc < timer_7109) {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      cVar4 = dMenu_Collect_c::_open3((dMenu_Collect_c *)dMc_c);
      if (cVar4 != '\0') {
        *(undefined *)(param_1 + 0x1b5) = 0xf;
      }
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x11') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Collect_c::_close2((dMenu_Collect_c *)dMc_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 2;
      bVar3 = d_meter::dMenu_getMenuStatus();
      d_meter::dMenu_setMenuStatusOld(bVar3);
      d_meter::dMenu_setMenuStatus(1);
      dMs_collect_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      dMs_item_create(param_1);
      *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x1;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x12') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Collect_c::_close2((dMenu_Collect_c *)dMc_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 3;
      bVar3 = d_meter::dMenu_getMenuStatus();
      d_meter::dMenu_setMenuStatusOld(bVar3);
      d_meter::dMenu_setMenuStatus(1);
      dMs_collect_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      dMs_item_create(param_1);
      *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x2;
    }
    goto LAB_801df1c4;
  }
  if ((cVar4 == '\x02') || (cVar4 == '\x03')) {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Item_c::_open2((dMenu_Item_c *)dMi_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 4;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x06') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Item_c::_close2((dMenu_Item_c *)dMi_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 9;
      bVar3 = d_meter::dMenu_getMenuStatus();
      d_meter::dMenu_setMenuStatusOld(bVar3);
      d_meter::dMenu_setMenuStatus(2);
      dMs_item_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      dMs_collect_create(param_1);
      *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x1;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\a') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Item_c::_close2((dMenu_Item_c *)dMi_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 10;
      bVar3 = d_meter::dMenu_getMenuStatus();
      d_meter::dMenu_setMenuStatusOld(bVar3);
      d_meter::dMenu_setMenuStatus(2);
      dMs_item_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      dMs_collect_create(param_1);
      *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x2;
    }
    goto LAB_801df1c4;
  }
  if ((cVar4 == '\t') || (cVar4 == '\n')) {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Collect_c::_open2((dMenu_Collect_c *)dMc_c);
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 0xd;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x04') {
    dMCloth_c::cloth_move(cloth_c);
    if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0) ||
        ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) &&
       (cVar4 = dMenu_Item_c::noteCheck((dMenu_Item_c *)dMi_c), cVar4 == '\0')) {
      if ((*(dMenu_Item_c *)((int)dMi_c + 0x23fe) == (dMenu_Item_c)0x0) &&
         (cVar4 = d_meter::dMeter_subWinFlag(), cVar4 == '\0')) {
        dMCloth_c::alpha_out(cloth_c);
        m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
        *(undefined *)(param_1 + 0x1b5) = 5;
        *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x0;
        *(undefined2 *)(dMi_c + 0x8fe) = 10;
        d_meter::dMenu_setPushMenuButton(0);
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0)
        ;
        goto LAB_801df1c4;
      }
    }
    iVar2 = dMs_isPush_R_Button(param_1);
    if ((iVar2 == 0) ||
       ((cVar4 = dMenu_Item_c::noteCheck((dMenu_Item_c *)dMi_c), cVar4 != '\0' ||
        (*(dMenu_Item_c *)((int)dMi_c + 0x23fe) != (dMenu_Item_c)0x0)))) {
      iVar2 = dMs_isPush_L_Button(param_1);
      if ((iVar2 == 0) ||
         ((cVar4 = dMenu_Item_c::noteCheck((dMenu_Item_c *)dMi_c), cVar4 != '\0' ||
          (*(dMenu_Item_c *)((int)dMi_c + 0x23fe) != (dMenu_Item_c)0x0)))) {
        m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
        (**(code **)(*dMi_c + 0x18))();
      }
      else {
        m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
        *(undefined *)(param_1 + 0x1b5) = 6;
        *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x1;
        *(undefined2 *)(dMi_c + 0x8fe) = DAT_803e6afe;
        d_meter::dMenu_setPushMenuButton(2);
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x8b5,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0)
        ;
      }
    }
    else {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      *(undefined *)(param_1 + 0x1b5) = 7;
      *(dMenu_Item_c *)((int)dMi_c + 0x2421) = (dMenu_Item_c)0x2;
      *(undefined2 *)(dMi_c + 0x8fe) = DAT_803e6afe;
      d_meter::dMenu_setPushMenuButton(2);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x8b5,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\r') {
    dMCloth_c::cloth_move(cloth_c);
    if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) &&
        (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) ||
       ((cVar4 = dMenu_Collect_c::noteCheck((dMenu_Collect_c *)dMc_c), cVar4 != '\0' ||
        ((*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x0 &&
         (*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x2)))))) {
      iVar2 = dMs_isPush_R_Button(param_1);
      if ((iVar2 == 0) ||
         ((cVar4 = dMenu_Collect_c::noteCheck((dMenu_Collect_c *)dMc_c), cVar4 != '\0' ||
          ((*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x0 &&
           (*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x2)))))) {
        iVar2 = dMs_isPush_L_Button(param_1);
        if ((iVar2 == 0) ||
           ((cVar4 = dMenu_Collect_c::noteCheck((dMenu_Collect_c *)dMc_c), cVar4 != '\0' ||
            ((*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x0 &&
             (*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x2)))))) {
          m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
          (**(code **)(*dMc_c + 0x18))();
        }
        else {
          m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
          *(undefined *)(param_1 + 0x1b5) = 0x11;
          *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x1;
          *(undefined2 *)((int)dMc_c + 0x27e2) = DAT_803e6afe;
          d_meter::dMenu_setPushMenuButton(1);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8b5,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
        }
      }
      else {
        m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
        *(undefined *)(param_1 + 0x1b5) = 0x12;
        *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x2;
        *(undefined2 *)((int)dMc_c + 0x27e2) = DAT_803e6afe;
        d_meter::dMenu_setPushMenuButton(1);
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x8b5,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0)
        ;
      }
    }
    else {
      dMCloth_c::alpha_out(cloth_c);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      *(undefined *)(param_1 + 0x1b5) = 0x10;
      *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x0;
      *(undefined2 *)((int)dMc_c + 0x27e2) = 10;
      d_meter::dMenu_setPushMenuButton(0);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x0e') {
    dMCloth_c::cloth_move(cloth_c);
    if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0) &&
         (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) ||
        (cVar4 = dMenu_Collect_c::noteCheck((dMenu_Collect_c *)dMc_c), cVar4 != '\0')) ||
       ((*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x0 &&
        (*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) != (dMenu_Collect_c)0x2)))) {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      (**(code **)(*dMc_c + 0x18))();
    }
    else {
      dMCloth_c::alpha_out(cloth_c);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      *(undefined *)(param_1 + 0x1b5) = 0x13;
      *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x0;
      *(undefined2 *)((int)dMc_c + 0x27e2) = 10;
      d_meter::dMenu_setPushMenuButton(0);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x0f') {
    dMCloth_c::cloth_move(cloth_c);
    if (*(dMenu_Collect_c *)((int)dMc_c + 0x27ee) == (dMenu_Collect_c)0x5) {
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      dMenu_Collect_c::_move3((dMenu_Collect_c *)dMc_c);
    }
    else {
      dMCloth_c::alpha_out(cloth_c);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      *(undefined *)(param_1 + 0x1b5) = 0x14;
      *(dMenu_Collect_c *)(dMc_c + 0x9fb) = (dMenu_Collect_c)0x0;
      *(undefined2 *)((int)dMc_c + 0x27e2) = 10;
      d_meter::dMenu_setPushMenuButton(0);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x05') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = (**(code **)(*dMi_c + 0x24))();
    if (cVar4 != '\0') {
      dMs_item_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
      dMs_cloth_delete(param_1);
      *(undefined *)(param_1 + 0x1b5) = 0;
      d_meter::dMenu_flagSet(0);
      JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
    }
    goto LAB_801df1c4;
  }
  if ((cVar4 == '\x10') || (cVar4 == '\x13')) {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = (**(code **)(*dMc_c + 0x24))();
    if (cVar4 != '\0') {
      dMs_collect_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
      dMs_cloth_delete(param_1);
      *(undefined *)(param_1 + 0x1b5) = 0;
      d_meter::dMenu_flagSet(0);
      JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
      daPy_lk_c::resetTactCount(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x14') {
    dMCloth_c::cloth_move(cloth_c);
    m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    cVar4 = dMenu_Collect_c::_close3((dMenu_Collect_c *)dMc_c);
    if (cVar4 != '\0') {
      dMs_collect_delete(param_1);
      dMs_childHeap_freeAll(param_1);
      m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
      dMs_cloth_delete(param_1);
      *(undefined *)(param_1 + 0x1b5) = 0;
      d_meter::dMenu_flagSet(0);
      JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 == '\x1e') {
    cVar4 = (**(code **)(*dMd_c + 0x20))();
    if (cVar4 != '\0') {
      *(undefined *)(param_1 + 0x1b5) = 0x1f;
    }
    goto LAB_801df1c4;
  }
  if (cVar4 != '\x1f') {
    if (cVar4 == ' ') {
      cVar4 = (**(code **)(*dMd_c + 0x24))();
      if (cVar4 != '\0') {
        *(undefined *)(param_1 + 0x1b5) = 0;
        d_meter::dMenu_flagSet(0);
        dMs_dmap_delete(param_1);
        JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
      }
    }
    else {
      if (cVar4 == '\x15') {
        dMCloth_c::cloth_move(cloth_c);
        cVar4 = ::dMenu_Fmap_c::_open(dMf_c);
        if (cVar4 != '\0') {
          *(undefined *)(param_1 + 0x1b5) = 0x19;
        }
      }
      else {
        if (cVar4 == '\x16') {
          cVar4 = ::dMenu_Fmap_c::_open_warpMode(dMf_c);
          if (cVar4 != '\0') {
            *(undefined *)(param_1 + 0x1b5) = 0x1a;
          }
        }
        else {
          if (cVar4 == '\x17') {
            bVar3 = d_meter::dMenu_flag();
            if ((bVar3 != 0) && (cVar4 = ::dMenu_Fmap_c::_open_wallPaper(dMf_c), cVar4 != '\0')) {
              *(undefined *)(param_1 + 0x1b5) = 0x1b;
            }
          }
          else {
            if (cVar4 == '\x18') {
              bVar3 = d_meter::dMenu_flag();
              if ((bVar3 != 0) && (cVar4 = ::dMenu_Fmap_c::_open_fishManMode(dMf_c), cVar4 != '\0'))
              {
                *(undefined *)(param_1 + 0x1b5) = 0x1c;
              }
            }
            else {
              if ((cVar4 == '\x19') || (cVar4 == '\x1a')) {
                if (cloth_c != (dMCloth_c *)0x0) {
                  dMCloth_c::cloth_move(cloth_c);
                }
                cVar4 = ::dMenu_Fmap_c::isFmapClose(dMf_c);
                if (cVar4 == '\0') {
                  ::dMenu_Fmap_c::_move(dMf_c);
                }
                else {
                  *(undefined *)(param_1 + 0x1b5) = 0x1d;
                  JAIZelBasic::seStart
                            (JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0)
                  ;
                }
              }
              else {
                if (cVar4 == '\x1b') {
                  cVar4 = ::dMenu_Fmap_c::isFmapClose(dMf_c);
                  if (cVar4 == '\0') {
                    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0) {
                      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
                        if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
                          if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0)
                              && ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0
                                 )) && (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02')) {
                            ::dMenu_Fmap_c::_move(dMf_c);
                            goto LAB_801df1c4;
                          }
                        }
                      }
                    }
                  }
                  *(undefined *)(param_1 + 0x1b5) = 0x1d;
                  JAIZelBasic::seStart
                            (JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0)
                  ;
                }
                else {
                  if (cVar4 == '\x1c') {
                    cVar4 = ::dMenu_Fmap_c::isFmapClose(dMf_c);
                    if (cVar4 == '\0') {
                      ::dMenu_Fmap_c::_move(dMf_c);
                    }
                    else {
                      *(undefined *)(param_1 + 0x1b5) = 0x1d;
                      JAIZelBasic::seStart
                                (JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,
                                 _7759,0);
                    }
                  }
                  else {
                    if (cVar4 == '\x1d') {
                      if (cloth_c != (dMCloth_c *)0x0) {
                        dMCloth_c::alpha_out(cloth_c);
                      }
                      cVar4 = ::dMenu_Fmap_c::_close(dMf_c);
                      if (cVar4 != '\0') {
                        *(undefined *)(param_1 + 0x1b5) = 0;
                        d_meter::dMenu_flagSet(0);
                        dMs_clothOnly_delete(param_1);
                        dMs_fmap_delete(param_1);
                        JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
                        d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
                      }
                    }
                    else {
                      if (cVar4 == '!') {
                        cVar4 = ::dName_c::_open(dNm_c);
                        if (cVar4 != '\0') {
                          *(undefined *)(param_1 + 0x1b5) = 0x22;
                        }
                      }
                      else {
                        if (cVar4 == '\"') {
                          ::dName_c::_move(dNm_c);
                          if (dNm_c[0x290b] == (dName_c)0x1) {
                            MSL_C.PPCEABI.bare.H::strcpy
                                      ((char *)&d_com_inf_game::g_dComIfG_gameInfo.field_0x5c06,
                                       (char *)(dNm_c + 0x2a5c));
                            *(undefined *)(param_1 + 0x1b5) = 0x23;
                            d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf2 = 1;
                          }
                          else {
                            if (dNm_c[0x290b] == (dName_c)0x2) {
                              MSL_C.PPCEABI.bare.H::strcpy
                                        ((char *)&d_com_inf_game::g_dComIfG_gameInfo.field_0x5c06,""
                                        );
                              *(undefined *)(param_1 + 0x1b5) = 0x23;
                              d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf2 = 0;
                            }
                          }
                        }
                        else {
                          if (cVar4 == '#') {
                            cVar4 = ::dName_c::_close(dNm_c);
                            if (cVar4 != '\0') {
                              *(undefined *)(param_1 + 0x1b5) = 0;
                              d_meter::dMenu_flagSet(0);
                              dMs_name_delete(param_1);
                              JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
                              d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
                            }
                          }
                          else {
                            if (cVar4 == '$') {
                              cVar4 = dMenu_save_c::_open(dMs_c);
                              if (cVar4 != '\0') {
                                *(undefined *)(param_1 + 0x1b5) = 0x25;
                              }
                            }
                            else {
                              if (cVar4 == '%') {
                                dMenu_save_c::_move(dMs_c);
                                if (dMs_c[0x531] == (dMenu_save_c)0x3) {
                                  if (dMs_c[0x538] == (dMenu_save_c)0x0) {
                                    d_com_inf_game::g_dComIfG_gameInfo._23545_1_ = 3;
                                  }
                                  else {
                                    if (dMs_c[0x538] == (dMenu_save_c)0x1) {
                                      d_com_inf_game::g_dComIfG_gameInfo._23545_1_ = 2;
                                    }
                                  }
                                  *(undefined *)(param_1 + 0x1b5) = 0x26;
                                }
                              }
                              else {
                                if ((cVar4 == '&') &&
                                   (cVar4 = dMenu_save_c::_close(dMs_c), cVar4 != '\0')) {
                                  *(undefined *)(param_1 + 0x1b5) = 0;
                                  d_meter::dMenu_flagSet(0);
                                  dMs_save_delete(param_1);
                                  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
                                  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LAB_801df1c4;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0) {
    if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') ||
       ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 < '\0')) goto LAB_801decc0;
  }
  else {
LAB_801decc0:
    cVar4 = dMenu_Dmap_c::noteCheck((dMenu_Dmap_c *)dMd_c);
    if (cVar4 == '\0') {
      *(undefined *)(param_1 + 0x1b5) = 0x20;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x810,(cXyz *)0x0,0,0,_4300,_4300,_7759,_7759,0);
      goto LAB_801df1c4;
    }
  }
  (**(code **)(*dMd_c + 0x18))();
LAB_801df1c4:
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerLeftLevel == 0) &&
     (iVar2 = dMs_isButtonBit(param_1,1), iVar2 != 0)) {
    dMs_offButtonBit(param_1,1);
  }
  if (dMi_c == (int *)0x0) {
    d_meter::dMenu_setItemMode(0);
  }
  else {
    d_meter::dMenu_setItemMode(*(dMenu_Item_c *)((int)dMi_c + 0x23fe));
  }
  if (dMc_c == (int *)0x0) {
    d_meter::dMenu_setCollectMode(0);
  }
  else {
    d_meter::dMenu_setCollectMode(*(dMenu_Collect_c *)((int)dMc_c + 0x27ee));
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mTriggerRightLevel == 0) &&
     (iVar2 = dMs_isButtonBit(param_1,2), iVar2 != 0)) {
    dMs_offButtonBit(param_1,2);
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 1) {
    dMs_placenameMove(param_1);
  }
  dMs_telescopeMove(param_1);
  bVar3 = d_meter::dMenu_flag();
  if ((bVar3 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) {
    dSv_player_item_record_c::decTimer
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf5 == 1) {
    if (d_com_inf_game::g_dComIfG_gameInfo._23490_2_ < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23490_2_ = 0;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf5 = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23490_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23490_2_ + -1;
    }
  }
  if (dMf_c == (dMenu_Fmap_c *)0x0) {
    uRam803f7071 = 3;
  }
  else {
    uRam803f7071 = ::dMenu_Fmap_c::getButtonIconMode(dMf_c);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return 1;
}


/* __stdcall dMs_IsDelete(sub_ms_screen_class *) */

undefined4 dMs_IsDelete(void)

{
  d_meter::dMenu_flagSet(0);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMs_Delete(sub_ms_screen_class *) */

undefined4 dMs_Delete(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  d_meter::dMenu_setPushMenuButton(0);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe = 0;
  uVar1 = m_Do_ext::mDoExt_getCurrentHeap();
  if (*(int *)(param_1 + 0x100) != 0) {
    m_Do_ext::mDoExt_setCurrentHeap();
    if (dMi_c != 0) {
      dMs_item_delete(param_1);
    }
    if (dMc_c != 0) {
      dMs_collect_delete(param_1);
    }
    dMs_childHeap_freeAll(param_1);
  }
  m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
    dMs_dmap_delete(param_1);
  }
  else {
    iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((*(ushort *)(iVar2 + 10) & 3) == 0) {
      dMs_fmap_delete(param_1);
    }
  }
  dMs_name_delete(param_1);
  dMs_save_delete(param_1);
  dMs_cloth_delete(param_1);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e635c);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6450);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMs_Create(msg_class *) */

undefined4 dMs_Create(sub_ms_screen_class *this)

{
  ulong uVar1;
  short sVar2;
  
  DAT_803e635c = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"アイテムビット",
                            (JORReflexible *)&g_mwHIO);
  DAT_803e6450 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"ダンジョンビット",
                            (JORReflexible *)&g_mwDHIO);
  this->mpHeap = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
  fonttype = m_Do_ext::mDoExt_getMesgFont();
  if (fonttype == (JUTFont *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_window.cpp",0x1001,"fonttype != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x1001,&DAT_80360851);
  }
  rfonttype = m_Do_ext::mDoExt_getRubyFont();
  if (rfonttype == (JUTFont *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_menu_window.cpp",0x1004,"rfonttype != 0");
    m_Do_printf::OSPanic("d_menu_window.cpp",0x1004,&DAT_80360851);
  }
  event_wait_frame = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf2 = 0;
  this->field_0x1b6 = 0;
  this->field_0x108 = -1;
  this->field_0x1b0 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  sVar2 = dSv_player_item_record_c::getTimer
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  if (sVar2 != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf6 = 1;
  }
  d_meter::dMenu_setMenuStatus(1);
  dMv_CIO_c = 0;
  DAT_803e6341 = 0;
  DAT_803e6342 = 0xf6;
  DAT_803e6343 = 0xf6;
  DAT_803e6344 = 0xf6;
  DAT_803e6345 = 0xf6;
  DAT_803e6346 = 0xf6;
  DAT_803e6347 = 0xf6;
  DAT_803e6348 = 0;
  DAT_803e6349 = 0xff;
  DAT_803e634a = 0xf6;
  DAT_803e634b = 0xf6;
  f_op_msg_mng::fopMsgM_setStageLayer(this);
  return 4;
}

}

/* __thiscall dDlst_MENU_CAPTURE_c::draw(void) */

void __thiscall dDlst_MENU_CAPTURE_c::draw(dDlst_MENU_CAPTURE_c *this)

{
  double dVar1;
  _GXColor local_68;
  GXTexObj GStack100;
  MTX44 MStack68;
  
  if (this->mStatus == 1) {
    this->mStatus = 2;
    gx::GXSetTexCopySrc(0,0,0x280,0x1e0);
    gx::GXSetTexCopyDst(0x140,0xf0,mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,1);
    gx::GXCopyTex(mDoGph_gInf_c::mFrameBufferTex,0);
    gx::GXPixModeSync();
  }
  else {
    gx::GXSetTexCopySrc(0,0,0x280,0x1e0);
    gx::GXSetTexCopyDst(0x140,0xf0,4,1);
    gx::GXCopyTex(mDoGph_gInf_c::mZbufferTex,0);
    gx::GXPixModeSync();
    gx::GXInitTexObj(&GStack100,mDoGph_gInf_c::mFrameBufferTex,0x140,0xf0,
                     mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,GX_CLAMP,GX_CLAMP,false);
    dVar1 = (double)d_menu_window::_4299;
    gx::GXInitTexObjLOD(dVar1,dVar1,dVar1,&GStack100,1,1,0,0,0);
    gx::GXLoadTexObj(&GStack100,0);
    gx::GXSetNumChans(0);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetZCompLoc(1);
    gx::GXSetZMode(false,GX_ALWAYS,false);
    gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_OR);
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
    local_68 = d_com_inf_game::g_clearColor;
    gx::GXSetFog(GX_FOG_NONE,d_menu_window::_4299,d_menu_window::_4299,d_menu_window::_4299,
                 d_menu_window::_4299,&local_68);
    gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
    gx::GXSetCullMode(0);
    gx::GXSetDither(1);
    mtx::C_MTXOrtho(d_menu_window::_4299,d_menu_window::_4300,d_menu_window::_4299,
                    d_menu_window::_4300,d_menu_window::_4299,d_menu_window::_4301,&MStack68);
    gx::GXSetProjection(&MStack68,GX_ORTHOGRAPHIC);
    gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
    gx::GXSetCurrentMtx(0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
    gx::GXBegin(0x80,0,4);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
  }
  return;
}


/* __thiscall dDlst_MENU_CLOTH_c::draw(void) */

void __thiscall dDlst_MENU_CLOTH_c::draw(dDlst_MENU_CLOTH_c *this)

{
  _GXColor local_48;
  _GXColor local_44;
  MTX44 MStack64;
  
  mtx::C_MTXPerspective
            ((double)d_menu_window::_4317,
             (double)(((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cfc)->mWidth /
                      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cfc)->mHeight) *
                     f_ap_game::g_HIO.aspectRatio),(double)d_menu_window::_4300,
             (double)d_menu_window::_4318,&MStack64);
  gx::GXSetProjection(&MStack64,GX_PERSPECTIVE);
  local_48 = d_menu_item::g_miHIO.field_0x58;
  local_44 = d_menu_item::g_miHIO.field_0x54;
  dMCloth_c::draw(d_menu_window::cloth_c,d_menu_window::_4299,&local_44,&local_48,'\x01');
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  return;
}


/* __thiscall dDlst_MENU_CAPTURE_c::~dDlst_MENU_CAPTURE_c(void) */

void __thiscall dDlst_MENU_CAPTURE_c::_dDlst_MENU_CAPTURE_c(dDlst_MENU_CAPTURE_c *this)

{
  short in_r4;
  
  if (this != (dDlst_MENU_CAPTURE_c *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (dDlst_MENU_CAPTURE_c *)0x0) {
      (this->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_MENU_CLOTH_c::~dDlst_MENU_CLOTH_c(void) */

void __thiscall dDlst_MENU_CLOTH_c::_dDlst_MENU_CLOTH_c(dDlst_MENU_CLOTH_c *this)

{
  short in_r4;
  
  if (this != (dDlst_MENU_CLOTH_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_MENU_CLOTH_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_Fmap2_c::~dMenu_Fmap2_c(void) */

void __thiscall dMenu_Fmap2_c::_dMenu_Fmap2_c(dMenu_Fmap2_c *this)

{
  short in_r4;
  
  if (this != (dMenu_Fmap2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMenu_Fmap2_c *)0xffffffd8) {
      *(undefined1 **)(this + 0x28) = &dDlst_FMAP2GS_c::__vt;
      if (this != (dMenu_Fmap2_c *)0xffffffd8) {
        *(undefined ***)(this + 0x28) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dMenu_Fmap2_c *)0xffffffe0) {
      *(undefined1 **)(this + 0x20) = &dDlst_FMAP2_c::__vt;
      if (this != (dMenu_Fmap2_c *)0xffffffe0) {
        *(undefined ***)(this + 0x20) = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMenu_Fmap_c::~dMenu_Fmap_c(void) */

void __thiscall dMenu_Fmap_c::_dMenu_Fmap_c(dMenu_Fmap_c *this)

{
  short in_r4;
  
  if (this != (dMenu_Fmap_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMenu_Fmap_c *)0xffffffdc) {
      *(undefined1 **)&this->field_0x24 = &dMenu_Fmap2_c::__vt;
      if (this != (dMenu_Fmap_c *)0xffffffb4) {
        *(undefined1 **)&this->field_0x4c = &dDlst_FMAP2GS_c::__vt;
        if (this != (dMenu_Fmap_c *)0xffffffb4) {
          *(undefined ***)&this->field_0x4c = &dDlst_base_c::__vt;
        }
      }
      if (this != (dMenu_Fmap_c *)0xffffffbc) {
        *(undefined1 **)&this->field_0x44 = &dDlst_FMAP2_c::__vt;
        if (this != (dMenu_Fmap_c *)0xffffffbc) {
          *(undefined ***)&this->field_0x44 = &dDlst_base_c::__vt;
        }
      }
    }
    if (this != (dMenu_Fmap_c *)0xffffffe4) {
      *(undefined1 **)&this->field_0x1c = &dDlst_FMAP_c::__vt;
      if (this != (dMenu_Fmap_c *)0xffffffe4) {
        *(undefined ***)&this->field_0x1c = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_NameIN_c::~dDlst_NameIN_c(void) */

void __thiscall dDlst_NameIN_c::_dDlst_NameIN_c(dDlst_NameIN_c *this)

{
  short in_r4;
  
  if (this != (dDlst_NameIN_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_NameIN_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dName_c::~dName_c(void) */

void __thiscall dName_c::_dName_c(dName_c *this)

{
  short in_r4;
  
  if (this != (dName_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dName_c *)&DAT_fffffff8) {
      *(undefined1 **)(this + 8) = &dDlst_NameIN_c::__vt;
      if (this != (dName_c *)&DAT_fffffff8) {
        *(undefined ***)(this + 8) = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMw_DHIO_c::~dMw_DHIO_c(void) */

void __thiscall dMw_DHIO_c::_dMw_DHIO_c(dMw_DHIO_c *this)

{
  short in_r4;
  
  if ((this != (dMw_DHIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMw_HIO_c::~dMw_HIO_c(void) */

void __thiscall dMw_HIO_c::_dMw_HIO_c(dMw_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMw_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_menu_window {

void __sinit_d_menu_window_cpp(void)

{
  dMv_CIO_c = 0;
  DAT_803e6341 = 0;
  DAT_803e6342 = 0xf6;
  DAT_803e6343 = 0xf6;
  DAT_803e6344 = 0xf6;
  DAT_803e6345 = 0xf6;
  DAT_803e6346 = 0xf6;
  DAT_803e6347 = 0xf6;
  DAT_803e6348 = 0;
  DAT_803e6349 = 0xff;
  DAT_803e634a = 0xf6;
  DAT_803e634b = 0xf6;
  Runtime.PPCEABI.H::__register_global_object(&dMv_CIO_c,::dMenu_FmapSv_c::_dMenu_FmapSv_c,&_4265);
  ::dMw_HIO_c::dMw_HIO_c((dMw_HIO_c *)&g_mwHIO);
  Runtime.PPCEABI.H::__register_global_object();
  ::dMw_DHIO_c::dMw_DHIO_c((dMw_DHIO_c *)&g_mwDHIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

}

/* __thiscall dMenu_FmapSv_c::~dMenu_FmapSv_c(void) */

void __thiscall dMenu_FmapSv_c::_dMenu_FmapSv_c(dMenu_FmapSv_c *this)

{
  short in_r4;
  
  if ((this != (dMenu_FmapSv_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

