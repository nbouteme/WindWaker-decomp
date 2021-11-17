#include <d_place_name.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DScreen.h>
#include <f_op_msg_mng.h>
#include <d_com_inf_game.h>
#include <d_meter.h>
#include <d_resorce.h>
#include <m_Do_ext.h>
#include <d_place_name.h>
#include <m_Do_dvd_thread.h>
#include <os/OSCache.h>
#include <J2DGraph/J2DPicture.h>
#include <d_drawlist.h>
#include <dPlace_name_c.h>
#include <dPn_c.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPlace_name_c::setScreen(char const *,
                                       JKRArchive *) */

void __thiscall dPlace_name_c::setScreen(dPlace_name_c *this,char *param_1,JKRArchive *param_2)

{
  J2DPane *this_00;
  ulong uVar1;
  int iVar2;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_place_name::_4017;
    local_28.mTL.y = d_place_name::_4017;
    local_28.mBR.x = d_place_name::_4018;
    local_28.mBR.y = d_place_name::_4019;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  if (*(int *)(this + 4) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_place_name.cpp",0x5b,"scrn != 0");
    m_Do_printf::OSPanic("d_place_name.cpp",0x5b,"Halt");
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),param_1,param_2);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 8),*(J2DScreen **)(this + 4),0x706e);
  iVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x626c6331);
  *(undefined *)(iVar2 + 0xaa) = 0;
  iVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x626c6332);
  *(undefined *)(iVar2 + 0xaa) = 0;
  return;
}


/* __thiscall dPlace_name_c::_openAnime(void) */

undefined4 __thiscall dPlace_name_c::_openAnime(dPlace_name_c *this)

{
  double dVar1;
  
  if (*(short *)(this + 0x3e) < 10) {
    *(short *)(this + 0x3e) = *(short *)(this + 0x3e) + 1;
    dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x3e),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 8),(float)dVar1);
  }
  return 1;
}


/* __thiscall dPlace_name_c::_closeAnime(void) */

bool __thiscall dPlace_name_c::_closeAnime(dPlace_name_c *this)

{
  double dVar1;
  
  if (0 < *(short *)(this + 0x3e)) {
    *(short *)(this + 0x3e) = *(short *)(this + 0x3e) + -1;
    dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x3e),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 8),(float)dVar1);
  }
  return *(short *)(this + 0x3e) < 1;
}


/* __thiscall dPlace_name_c::draw(void) */

void __thiscall dPlace_name_c::draw(dPlace_name_c *this)

{
  J2DOrthoGraph *pCtx;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 8));
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_place_name::_4017,d_place_name::_4017,&pCtx->parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dPn_c::_create(void) */

PhaseState __thiscall dPn_c::_create(dPn_c *this)

{
  PhaseState PVar1;
  byte bVar8;
  dRes_info_c *pdVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined **ppuVar5;
  void *pvVar6;
  undefined4 uVar7;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x100),"PName");
  bVar8 = d_meter::dMenu_flag();
  if ((bVar8 != 0) ||
     (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 != 0 &&
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 != 10)) ||
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca != 0)))) {
    return 0;
  }
  if (this[0x114] == (dPn_c)0x0) {
    if (PVar1 != cPhs_COMPLEATE_e) {
      return PVar1;
    }
    pdVar2 = dRes_control_c::getResInfo
                       ("PName",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pdVar2 == (dRes_info_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_place_name.cpp",0xa9,"resInfo != 0");
      m_Do_printf::OSPanic("d_place_name.cpp",0xa9,"Halt");
    }
    *(JKRExpHeap **)(this + 0xfc) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 10;
    uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0xfc));
    ppuVar5 = (undefined **)JKernel::operator_new(0x40);
    if (ppuVar5 != (undefined **)0x0) {
      *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
      *ppuVar5 = &dPlace_name_c::__vt;
    }
    *(undefined ***)(this + 0x108) = ppuVar5;
    if (*(int *)(this + 0x108) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_place_name.cpp",0xb1,"dPn_scrn != 0");
      m_Do_printf::OSPanic("d_place_name.cpp",0xb1,"Halt");
    }
    dPlace_name_c::setScreen(*(dPlace_name_c **)(this + 0x108),"place_name.blo",pdVar2->mpArchive);
    pvVar6 = JKRHeap::alloc(*(JKRHeap **)(this + 0xfc),0x3c00,0x20);
    *(void **)(this + 0x110) = pvVar6;
    m_Do_ext::mDoExt_setCurrentHeap(uVar4);
    this[0x114] = (dPn_c)0x1;
    *(undefined4 *)(this + 0x10c) = 0;
    if (d_com_inf_game::g_dComIfG_gameInfo._23543_1_ != 0) {
      return 0;
    }
  }
  else {
    if (this[0x114] == (dPn_c)0x1) {
      uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0xfc));
      if (0x12 < d_com_inf_game::g_dComIfG_gameInfo._23543_1_) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar3,"d_place_name.cpp",0xc9,"dComIfGp_getNowStageNum() < dPn_stage_max_e");
        m_Do_printf::OSPanic("d_place_name.cpp",0xc9,"Halt");
      }
      uVar7 = mDoDvdThd_toMainRam_c::create
                        ((&d_place_name::name_texture)[d_com_inf_game::g_dComIfG_gameInfo._23543_1_]
                         ,0,*(JKRHeap **)(this + 0xfc));
      *(undefined4 *)(this + 0x10c) = uVar7;
      this[0x114] = (dPn_c)0x2;
      m_Do_ext::mDoExt_setCurrentHeap(uVar4);
      return 0;
    }
    uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0xfc));
    if (*(char *)(*(int *)(this + 0x10c) + 0xc) != '\0') {
      copy_bytes(*(byte **)(this + 0x110),*(byte **)(*(int *)(this + 0x10c) + 0x1c),0x3c00);
      os::DCStoreRangeNoSync(*(undefined4 *)(this + 0x110),0x3c00);
      J2DPicture::changeTexture
                (*(J2DPicture **)(*(int *)(this + 0x108) + 8),*(ResTIMG **)(this + 0x110),'\0');
      this[0x114] = (dPn_c)0x3;
    }
    m_Do_ext::mDoExt_setCurrentHeap(uVar4);
    if (this[0x114] != (dPn_c)0x3) {
      return 0;
    }
  }
  return cPhs_COMPLEATE_e;
}


/* __thiscall dPn_c::_execute(void) */

undefined4 __thiscall dPn_c::_execute(dPn_c *this)

{
  int iVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._23544_1_ == '\x02') {
    dPlace_name_c::_openAnime(*(dPlace_name_c **)(this + 0x108));
  }
  else {
    if ((d_com_inf_game::g_dComIfG_gameInfo._23544_1_ == '\x01') &&
       (iVar1 = dPlace_name_c::_closeAnime(*(dPlace_name_c **)(this + 0x108)), iVar1 != 0)) {
      f_op_msg_mng::fopMsgM_Delete(this);
    }
  }
  return 1;
}


/* __thiscall dPn_c::_draw(void) */

undefined4 __thiscall dPn_c::_draw(dPn_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0x108));
  return 1;
}


/* __thiscall dPn_c::_delete(void) */

undefined4 __thiscall dPn_c::_delete(dPn_c *this)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = 0;
  piVar2 = *(int **)(*(int *)(this + 0x108) + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  piVar2 = *(int **)(this + 0x108);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  iVar3 = *(int *)(this + 0x10c);
  if ((iVar3 != 0) && (iVar3 != 0)) {
    (**(code **)(*(int *)(iVar3 + 0x10) + 8))(iVar3,1);
  }
  JKRHeap::free(*(JKRHeap **)(this + 0xfc),*(void **)(this + 0x110));
  JKRHeap::freeAll(*(JKRHeap **)(this + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x100),"PName");
  return 1;
}


namespace d_place_name {

/* __stdcall dPn_Draw(dPn_c *) */

void dPn_Draw(dPn_c *param_1)

{
  ::dPn_c::_draw(param_1);
  return;
}


/* __stdcall dPn_Execute(dPn_c *) */

void dPn_Execute(dPn_c *param_1)

{
  ::dPn_c::_execute(param_1);
  return;
}


/* __stdcall dPn_IsDelete(dPn_c *) */

undefined4 dPn_IsDelete(void)

{
  return 1;
}


/* __stdcall dPn_Delete(dPn_c *) */

void dPn_Delete(dPn_c *param_1)

{
  ::dPn_c::_delete(param_1);
  return;
}


/* __stdcall dPn_Create(msg_class *) */

void dPn_Create(dPn_c *param_1)

{
  ::dPn_c::_create(param_1);
  return;
}

}

/* __thiscall dPlace_name_c::~dPlace_name_c(void) */

void __thiscall dPlace_name_c::_dPlace_name_c(dPlace_name_c *this)

{
  short in_r4;
  
  if (this != (dPlace_name_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dPlace_name_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

